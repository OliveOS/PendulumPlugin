/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PendulumComponent.h"

//==============================================================================
/**
*/
class PendulumPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PendulumPluginAudioProcessorEditor (PendulumPluginAudioProcessor&);
    ~PendulumPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PendulumPluginAudioProcessor& audioProcessor;
    
    PendulumComponent pendulum;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PendulumPluginAudioProcessorEditor)
};
