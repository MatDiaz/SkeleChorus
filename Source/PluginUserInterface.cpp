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

    addAndMakeVisible (depthSlider = new Slider ("depthSlider"));
    depthSlider->setRange (0, 1, 0);
    depthSlider->setSliderStyle (Slider::Rotary);
    depthSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    depthSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    depthSlider->addListener (this);

    depthSlider->setBounds (72, 136, 88, 80);

    addAndMakeVisible (rateSlider = new Slider ("rateSlider"));
    rateSlider->setRange (0.02, 5, 0);
    rateSlider->setSliderStyle (Slider::Rotary);
    rateSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rateSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    rateSlider->addListener (this);

    rateSlider->setBounds (200, 136, 88, 80);

    addAndMakeVisible (feedBackSlider = new Slider ("feedBackSlider"));
    feedBackSlider->setRange (-1, 1, 0);
    feedBackSlider->setSliderStyle (Slider::Rotary);
    feedBackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    feedBackSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    feedBackSlider->addListener (this);

    feedBackSlider->setBounds (320, 136, 88, 80);

    addAndMakeVisible (chorusOffsetSlider = new Slider ("chorusOffsetSlider"));
    chorusOffsetSlider->setRange (0, 10, 0);
    chorusOffsetSlider->setSliderStyle (Slider::Rotary);
    chorusOffsetSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    chorusOffsetSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    chorusOffsetSlider->addListener (this);

    chorusOffsetSlider->setBounds (440, 136, 88, 80);

    addAndMakeVisible (modTypeList = new ComboBox ("modTypeList"));
    modTypeList->setEditableText (false);
    modTypeList->setJustificationType (Justification::centredLeft);
    modTypeList->setTextWhenNothingSelected (String());
    modTypeList->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    modTypeList->addItem (TRANS("Flanger,"), 1);
    modTypeList->addItem (TRANS("Vibrato,"), 2);
    modTypeList->addItem (TRANS("Chorus"), 3);
    modTypeList->addListener (this);

    modTypeList->setBounds (275, 80, 150, 16);

    addAndMakeVisible (depthLabel = new Label ("depthLabel",
                                               TRANS("50%")));
    depthLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    depthLabel->setJustificationType (Justification::centred);
    depthLabel->setEditable (false, false, false);
    depthLabel->setColour (TextEditor::textColourId, Colours::black);
    depthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    depthLabel->setBounds (70, 208, 92, 24);

    addAndMakeVisible (rateLabel = new Label ("rateLabel",
                                              TRANS("0.18 Hz")));
    rateLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    rateLabel->setJustificationType (Justification::centred);
    rateLabel->setEditable (false, false, false);
    rateLabel->setColour (TextEditor::textColourId, Colours::black);
    rateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    rateLabel->setBounds (200, 208, 92, 24);

    addAndMakeVisible (feedbackLabel = new Label ("feedbackLabel",
                                                  TRANS("0 %")));
    feedbackLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    feedbackLabel->setJustificationType (Justification::centred);
    feedbackLabel->setEditable (false, false, false);
    feedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    feedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    feedbackLabel->setBounds (320, 208, 92, 24);

    addAndMakeVisible (offsetLabel = new Label ("offsetLabel",
                                                TRANS("0 mSec")));
    offsetLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    offsetLabel->setJustificationType (Justification::centred);
    offsetLabel->setEditable (false, false, false);
    offsetLabel->setColour (TextEditor::textColourId, Colours::black);
    offsetLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    offsetLabel->setBounds (440, 208, 92, 24);


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

    depthSlider = nullptr;
    rateSlider = nullptr;
    feedBackSlider = nullptr;
    chorusOffsetSlider = nullptr;
    modTypeList = nullptr;
    depthLabel = nullptr;
    rateLabel = nullptr;
    feedbackLabel = nullptr;
    offsetLabel = nullptr;


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
        float x = 150.0f, y = 71.0f, width = 288.0f, height = 32.0f;
        Colour fillColour = Colour (0x672a85a5);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 0.500f);
    }

    {
        int x = 175, y = 15, width = 240, height = 40;
        String text (TRANS("SkeleChorus"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 43.50f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 150, y = 65, width = 70, height = 40;
        String text (TRANS("Mode"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 18.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 85, y = 115, width = 64, height = 25;
        String text (TRANS("Depth"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 210, y = 115, width = 64, height = 25;
        String text (TRANS("Rate"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSansSerifFontName(), 15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 325, y = 115, width = 78, height = 25;
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
        int x = 445, y = 115, width = 78, height = 25;
        String text (TRANS("Offset"));
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

    if (sliderThatWasMoved == depthSlider)
    {
        //[UserSliderCode_depthSlider] -- add your slider handling code here..
		String newValue(enteringValue * 100, 2);
		depthLabel->setText(newValue + " %", dontSendNotification);
        //[/UserSliderCode_depthSlider]
    }
    else if (sliderThatWasMoved == rateSlider)
    {
        //[UserSliderCode_rateSlider] -- add your slider handling code here..
		String newValue(enteringValue, 2);
		rateLabel->setText(newValue + " Hz", dontSendNotification);
        //[/UserSliderCode_rateSlider]
    }
    else if (sliderThatWasMoved == feedBackSlider)
    {
        //[UserSliderCode_feedBackSlider] -- add your slider handling code here..
		String newValue(enteringValue * 100, 2);
		feedbackLabel->setText(newValue + " %", dontSendNotification);
        //[/UserSliderCode_feedBackSlider]
    }
    else if (sliderThatWasMoved == chorusOffsetSlider)
    {
        //[UserSliderCode_chorusOffsetSlider] -- add your slider handling code here..
		String newValue(enteringValue, 2);
		offsetLabel->setText(newValue + " mSec", dontSendNotification);
        //[/UserSliderCode_chorusOffsetSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SkeleChorusAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == modTypeList)
    {
        //[UserComboBoxCode_modTypeList] -- add your combo box handling code here..
        //[/UserComboBoxCode_modTypeList]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
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
    <ROUNDRECT pos="150 71 288 32" cornerSize="10.00000000000000000000" fill="solid: 672a85a5"
               hasStroke="1" stroke="0.5, mitered, butt" strokeColour="solid: ffffffff"/>
    <TEXT pos="175 15 240 40" fill="solid: ffffffff" hasStroke="0" text="SkeleChorus"
          fontname="Default sans-serif font" fontsize="43.50000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="150 65 70 40" fill="solid: ffffffff" hasStroke="0" text="Mode"
          fontname="Default sans-serif font" fontsize="18.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="85 115 64 25" fill="solid: ffffffff" hasStroke="0" text="Depth"
          fontname="Default sans-serif font" fontsize="15.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="210 115 64 25" fill="solid: ffffffff" hasStroke="0" text="Rate"
          fontname="Default sans-serif font" fontsize="15.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="325 115 78 25" fill="solid: ffffffff" hasStroke="0" text="Feedback"
          fontname="Default sans-serif font" fontsize="15.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
    <TEXT pos="445 115 78 25" fill="solid: ffffffff" hasStroke="0" text="Offset"
          fontname="Default sans-serif font" fontsize="15.00000000000000000000"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="depthSlider" id="c968fe14a38154c3" memberName="depthSlider"
          virtualName="" explicitFocusOrder="0" pos="72 136 88 80" rotarysliderfill="ffffffff"
          min="0.00000000000000000000" max="1.00000000000000000000" int="0.00000000000000000000"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="rateSlider" id="687bad69a5bfa144" memberName="rateSlider"
          virtualName="" explicitFocusOrder="0" pos="200 136 88 80" rotarysliderfill="ffffffff"
          min="0.02000000000000000042" max="5.00000000000000000000" int="0.00000000000000000000"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="feedBackSlider" id="3c56cb0279a5241e" memberName="feedBackSlider"
          virtualName="" explicitFocusOrder="0" pos="320 136 88 80" rotarysliderfill="ffffffff"
          min="-1.00000000000000000000" max="1.00000000000000000000" int="0.00000000000000000000"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="chorusOffsetSlider" id="a6ed186501621b7b" memberName="chorusOffsetSlider"
          virtualName="" explicitFocusOrder="0" pos="440 136 88 80" rotarysliderfill="ffffffff"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <COMBOBOX name="modTypeList" id="1b03d8eb77b94dd9" memberName="modTypeList"
            virtualName="" explicitFocusOrder="0" pos="275 80 150 16" editable="0"
            layout="33" items="Flanger,&#10;Vibrato,&#10;Chorus" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="depthLabel" id="81db525d18a5037e" memberName="depthLabel"
         virtualName="" explicitFocusOrder="0" pos="70 208 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="50%" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="rateLabel" id="d3b54b5165739b87" memberName="rateLabel"
         virtualName="" explicitFocusOrder="0" pos="200 208 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0.18 Hz" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="feedbackLabel" id="59e51d4415043708" memberName="feedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="320 208 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0 %" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="offsetLabel" id="2f8b3721a5e11baf" memberName="offsetLabel"
         virtualName="" explicitFocusOrder="0" pos="440 208 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0 mSec" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
