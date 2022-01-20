/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "PendulumComponent.h"

//==============================================================================
PendulumPluginAudioProcessorEditor::PendulumPluginAudioProcessorEditor (PendulumPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(pendulum);
    setSize (800, 600);
}

PendulumPluginAudioProcessorEditor::~PendulumPluginAudioProcessorEditor()
{
}

//==============================================================================
void PendulumPluginAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void PendulumPluginAudioProcessorEditor::resized()
{
    pendulum.setBoundsToFit(getBounds(), juce::Justification::centred, false);
    pendulum.setPaintingIsUnclipped(true);
}
