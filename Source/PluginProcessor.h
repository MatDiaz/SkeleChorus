/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class SkeleChorusAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SkeleChorusAudioProcessor();
    ~SkeleChorusAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    // Estas son las variables que se van a modificar desde la interfaz grafica
    float timeValue, mixLevel, feedbackLevel, currentSampleRate;

private:
    int writeIndex, readIndex, totalBufferLength;
    // Dos punteros que nos servirán como nuestros buffer circulares
    ScopedPointer<float> circularBufferL, circularBufferR;
    // Este sera el arreglo para almacenar nuestros buffer circulares
    // Esto se hace simplemente por comodidad y para simplificar el codigo
    OwnedArray<float> bufferHolder;
    // este es un vector de dos posiciones, son los indices de escritura del arreglo
    // es de dos posiciones pues tenemos dos buffer circulares
    int vectIndex[2];
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SkeleChorusAudioProcessor)
};
