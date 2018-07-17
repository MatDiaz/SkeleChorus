/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginUserInterface.h"


//==============================================================================
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
    circularBufferL = nullptr;
    circularBufferR = nullptr;
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
    currentSampleRate = sampleRate;
    timeValue = currentSampleRate * 5;
    
    if (circularBufferL == nullptr)
    {
        totalBufferLength = sampleRate * 5;
        
        circularBufferL = new float[totalBufferLength];
        circularBufferR = new float[totalBufferLength];
        
        bufferHolder.add(circularBufferR);
        bufferHolder.add(circularBufferL);
        
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
    
    if (totalNumOutputChannels > totalNumInputChannels || totalNumOutputChannels > 2 || totalNumInputChannels > 2)
    {
        for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
            buffer.clear (i, 0, buffer.getNumSamples());
    }
    
    for (auto j = 0; j < totalNumInputChannels; ++j)
    {
        float* channelData = buffer.getWritePointer(j);
        
        for (auto i = 0; i < buffer.getNumSamples(); ++i)
        {
            float previousValue = bufferHolder[j][vectIndex[j]];
            float newValue = channelData[i] + (previousValue * feedbackLevel);
            bufferHolder[j][vectIndex[j]] = newValue;
            
            channelData[i] = (channelData[i] * (mixLevel - 1)) + (previousValue * mixLevel);
            
            if (++vectIndex[j] >= timeValue)
                vectIndex[j] = 0;
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
