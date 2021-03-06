/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SkeleChorusAudioProcessorEditor  : public AudioProcessorEditor,
                                         public Slider::Listener,
                                         public ComboBox::Listener
{
public:
    //==============================================================================
    SkeleChorusAudioProcessorEditor (SkeleChorusAudioProcessor& p);
    ~SkeleChorusAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SkeleChorusAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> depthSlider;
    ScopedPointer<Slider> rateSlider;
    ScopedPointer<Slider> feedBackSlider;
    ScopedPointer<Slider> chorusOffsetSlider;
    ScopedPointer<ComboBox> modTypeList;
    ScopedPointer<Label> depthLabel;
    ScopedPointer<Label> rateLabel;
    ScopedPointer<Label> feedbackLabel;
    ScopedPointer<Label> offsetLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SkeleChorusAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
