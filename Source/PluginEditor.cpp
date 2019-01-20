/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ValueTreeReloadTestAudioProcessorEditor::ValueTreeReloadTestAudioProcessorEditor (ValueTreeReloadTestAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible(&saveButton);
    saveButton.setButtonText("Save Preset");
    saveButton.onClick = [&]()
    {
        processor.savePreset("TestPreset");
    };
    
    addAndMakeVisible(&loadButton);
    loadButton.setButtonText("Load Preset");
    loadButton.onClick = [&]()
    {
        processor.loadPreset(processor.getDesktopDir().getFullPathName() + "/TestPreset.xml");
    };
    
    setSize (400, 300);
}

ValueTreeReloadTestAudioProcessorEditor::~ValueTreeReloadTestAudioProcessorEditor()
{
}

//==============================================================================
void ValueTreeReloadTestAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

 
}

void ValueTreeReloadTestAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    
    auto buttonArea = area.reduced(getHeight() * 0.25f);
    auto saveButtonArea = buttonArea.removeFromLeft(buttonArea.getWidth() * 0.5f);
   
    saveButton.setBounds(saveButtonArea);
    loadButton.setBounds(buttonArea);
    
    
}
