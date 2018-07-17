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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginUserInterface.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SkeleChorusAudioProcessorEditor::SkeleChorusAudioProcessorEditor (SkeleChorusAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (rateSlider = new Slider ("rateSlider"));
    rateSlider->setRange (10, 5000, 0);
    rateSlider->setSliderStyle (Slider::Rotary);
    rateSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rateSlider->setColour (Slider::thumbColourId, Colour (0xff21a2ba));
    rateSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    rateSlider->addListener (this);

    rateSlider->setBounds (144, 104, 88, 80);

    addAndMakeVisible (feedBackSlider = new Slider ("feedBackSlider"));
    feedBackSlider->setRange (0, 1, 0);
    feedBackSlider->setSliderStyle (Slider::Rotary);
    feedBackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    feedBackSlider->setColour (Slider::thumbColourId, Colour (0xff397fad));
    feedBackSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    feedBackSlider->addListener (this);

    feedBackSlider->setBounds (264, 104, 88, 80);

    addAndMakeVisible (chorusOffsetSlider = new Slider ("chorusOffsetSlider"));
    chorusOffsetSlider->setRange (0, 1, 0);
    chorusOffsetSlider->setSliderStyle (Slider::Rotary);
    chorusOffsetSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    chorusOffsetSlider->setColour (Slider::thumbColourId, Colour (0xff2159ba));
    chorusOffsetSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    chorusOffsetSlider->addListener (this);

    chorusOffsetSlider->setBounds (384, 104, 88, 80);

    addAndMakeVisible (timeLabel = new Label ("timeLabel",
                                              TRANS("10 mSec")));
    timeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    timeLabel->setJustificationType (Justification::centred);
    timeLabel->setEditable (false, false, false);
    timeLabel->setColour (TextEditor::textColourId, Colours::black);
    timeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    timeLabel->setBounds (141, 176, 92, 24);

    addAndMakeVisible (feedbackLabel = new Label ("feedbackLabel",
                                                  TRANS("0 %")));
    feedbackLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    feedbackLabel->setJustificationType (Justification::centred);
    feedbackLabel->setEditable (false, false, false);
    feedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    feedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    feedbackLabel->setBounds (261, 176, 92, 24);

    addAndMakeVisible (mixLabel = new Label ("mixLabel",
                                             TRANS("0 %")));
    mixLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    mixLabel->setJustificationType (Justification::centred);
    mixLabel->setEditable (false, false, false);
    mixLabel->setColour (TextEditor::textColourId, Colours::black);
    mixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    mixLabel->setBounds (383, 176, 92, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 250);


    //[Constructor] You can add your own custom stuff here..
	rateSlider->setValue(0.18, dontSendNotification);
    //[/Constructor]
}

SkeleChorusAudioProcessorEditor::~SkeleChorusAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rateSlider = nullptr;
    feedBackSlider = nullptr;
    chorusOffsetSlider = nullptr;
    timeLabel = nullptr;
    feedbackLabel = nullptr;
    mixLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SkeleChorusAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    {
        int x = 8, y = 8, width = 585, height = 235;
        Colour fillColour = Colour (0x2a3a3a4e);
        Colour strokeColour = Colour (0xff3673a7);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 5);

    }

    {
        int x = 156, y = 19, width = 297, height = 40;
        String text (TRANS("Delay-yay"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 43.50f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 154, y = 83, width = 64, height = 25;
        String text (TRANS("Time"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 269, y = 83, width = 78, height = 25;
        String text (TRANS("Feedback"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 389, y = 83, width = 78, height = 25;
        String text (TRANS("Mix"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SkeleChorusAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SkeleChorusAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	float enteringValue = sliderThatWasMoved->getValue();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == rateSlider)
    {
        //[UserSliderCode_rateSlider] -- add your slider handling code here..
        processor.timeValue = ((enteringValue)/1000) * processor.currentSampleRate;
		String newValue(enteringValue, 2);
        timeLabel->setText(newValue + " mSec", dontSendNotification);
        //[/UserSliderCode_rateSlider]
    }
    else if (sliderThatWasMoved == feedBackSlider)
    {
        //[UserSliderCode_feedBackSlider] -- add your slider handling code here..
        processor.feedbackLevel = enteringValue;
		String newValue(enteringValue * 100, 2);
		feedbackLabel->setText(newValue + " %", dontSendNotification);
        //[/UserSliderCode_feedBackSlider]
    }
    else if (sliderThatWasMoved == chorusOffsetSlider)
    {
        //[UserSliderCode_chorusOffsetSlider] -- add your slider handling code here..
        processor.mixLevel = enteringValue;
		String newValue(enteringValue * 100, 2);
		mixLabel->setText(newValue + " %", dontSendNotification);
        //[/UserSliderCode_chorusOffsetSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SkeleChorusAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="SkeleChorusAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="250">
  <BACKGROUND backgroundColour="ff000000">
    <RECT pos="8 8 585 235" fill="solid: 2a3a3a4e" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff3673a7"/>
    <TEXT pos="156 19 297 40" fill="solid: ffffffff" hasStroke="0" text="Delay-yay"
          fontname="Default sans-serif font" fontsize="43.50000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="154 83 64 25" fill="solid: ffffffff" hasStroke="0" text="Time"
          fontname="Default sans-serif font" fontsize="15.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="269 83 78 25" fill="solid: ffffffff" hasStroke="0" text="Feedback"
          fontname="Default sans-serif font" fontsize="15.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="389 83 78 25" fill="solid: ffffffff" hasStroke="0" text="Mix"
          fontname="Default sans-serif font" fontsize="15.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="rateSlider" id="687bad69a5bfa144" memberName="rateSlider"
          virtualName="" explicitFocusOrder="0" pos="144 104 88 80" thumbcol="ff21a2ba"
          rotarysliderfill="ffffffff" min="10.00000000000000000000" max="5000.00000000000000000000"
          int="0.00000000000000000000" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="feedBackSlider" id="3c56cb0279a5241e" memberName="feedBackSlider"
          virtualName="" explicitFocusOrder="0" pos="264 104 88 80" thumbcol="ff397fad"
          rotarysliderfill="ffffffff" min="0.00000000000000000000" max="1.00000000000000000000"
          int="0.00000000000000000000" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="chorusOffsetSlider" id="a6ed186501621b7b" memberName="chorusOffsetSlider"
          virtualName="" explicitFocusOrder="0" pos="384 104 88 80" thumbcol="ff2159ba"
          rotarysliderfill="ffffffff" min="0.00000000000000000000" max="1.00000000000000000000"
          int="0.00000000000000000000" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="timeLabel" id="d3b54b5165739b87" memberName="timeLabel"
         virtualName="" explicitFocusOrder="0" pos="141 176 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="10 mSec" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="feedbackLabel" id="59e51d4415043708" memberName="feedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="261 176 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0 %" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="mixLabel" id="2f8b3721a5e11baf" memberName="mixLabel" virtualName=""
         explicitFocusOrder="0" pos="383 176 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0 %" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
