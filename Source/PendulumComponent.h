/*
  ==============================================================================

    PendulumComponent.h
    Created: 20 Jan 2022 7:09:49pm
    Author:  Oliver Wooding

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PendulumComponent  : public juce::Component
{
public:
    PendulumComponent();
    ~PendulumComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PendulumComponent)
};
