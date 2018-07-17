/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginUserInterface.h"


//==============================================================================
// En esta primera linea se inicializan todos los valores que hayan sido
// declarados en el header de esta misma clase
SkeleChorusAudioProcessor::SkeleChorusAudioProcessor():
writeIndex(0), readIndex(0), totalBufferLength(1), timeValue(44100 * 5), mixLevel(1), feedbackLevel(0.5)
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    
}

SkeleChorusAudioProcessor::~SkeleChorusAudioProcessor()
{   
    // En el destructor eliminamos los posibles vectores
    // que hayamos creados en punteros
    circularBufferL = nullptr;
    circularBufferR = nullptr;
    // Y muy importante en el arreglo de vectores se deben
    // eliminar los datos que hayamos incluido
    bufferHolder.clearQuick(false);
}

//==============================================================================
const String SkeleChorusAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SkeleChorusAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SkeleChorusAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SkeleChorusAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SkeleChorusAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SkeleChorusAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SkeleChorusAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SkeleChorusAudioProcessor::setCurrentProgram (int index)
{
}

const String SkeleChorusAudioProcessor::getProgramName (int index)
{
    return {};
}

void SkeleChorusAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SkeleChorusAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{   
    // Obtenemos la frecuencia de muestreo
    currentSampleRate = sampleRate;
    // Inicializamos el valor maximo en el punto de la frecuencia de muestreo
    timeValue = currentSampleRate * 5;
    
    // Si aun no hemos asignado un tamaño a los buffer circulares que creamos
    // entonces entramos en esta condicion
    if (circularBufferL == nullptr || circularBufferR == nullptr)
    {   
        // asignamos el tamaño de los buffer
        totalBufferLength = sampleRate * 5;
        
        // le asignamos un tamaño a los punteros previamente creados
        circularBufferL = new float[totalBufferLength];
        circularBufferR = new float[totalBufferLength];
        
        // agregamos los dos vectores al arreglo (esto es como una especie de ""matriz"")
        bufferHolder.add(circularBufferR);
        bufferHolder.add(circularBufferL);
        
        // llenamos de ceros ambos buffer
        for (auto i = 0; i < 2; ++i)
        {
            vectIndex[i] = 0;
            memset(bufferHolder[i], 0, sizeof (float) * totalBufferLength);
        }
    }
}

void SkeleChorusAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SkeleChorusAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SkeleChorusAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    // Si hay mas salidas que entradas
    // Si hay mas de dos salidas/entradas (por configuración nuestra)
    // limpiamos los buffer de salida (no suena nada)
    if (totalNumOutputChannels > totalNumInputChannels || totalNumOutputChannels > 2 || totalNumInputChannels > 2)
    {
        for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
            buffer.clear (i, 0, buffer.getNumSamples());
    }
    else // Si no entonces hacemos el ciclo
    {
        for (auto j = 0; j < totalNumInputChannels; ++j) // Recorremos cada uno de los canales
        {
            float* channelData = buffer.getWritePointer(j); // Obtenemos el puntero de escritura
        
            for (auto i = 0; i < buffer.getNumSamples(); ++i) // modificamos cada una de las muestras
            {
                float previousValue = bufferHolder[j][vectIndex[j]]; // Obtenemos el valor anterior ( de cada canal y cada muestra )
                float newValue = channelData[i] + (previousValue * feedbackLevel); // lo multiplicamos por el valor de feedback y le sumamos la muestra que entra
                bufferHolder[j][vectIndex[j]] = newValue; // Se guarda en la misma posicion del buffer circular
                
                // La salida sera: la misma entrada, mas el valor que extrajimmos del buffer circular
                channelData[i] = (channelData[i] * (mixLevel - 1)) + (previousValue * mixLevel);
                
                // Aumentamos la posicion del buffer circular
                if (++vectIndex[j] >= timeValue)
                    vectIndex[j] = 0;
            }
        }
    }
}

//==============================================================================
bool SkeleChorusAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SkeleChorusAudioProcessor::createEditor()
{
    return new SkeleChorusAudioProcessorEditor (*this);
}

//==============================================================================
void SkeleChorusAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SkeleChorusAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SkeleChorusAudioProcessor();
}
