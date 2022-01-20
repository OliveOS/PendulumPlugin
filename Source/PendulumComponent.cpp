/*
  ==============================================================================

    PendulumComponent.cpp
    Created: 20 Jan 2022 7:09:49pm
    Author:  Oliver Wooding

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PendulumComponent.h"

//==============================================================================
struct Pendulum {
    float theta, omega;
    float length, mass;
};

class DoublePendulum {
private:
    Pendulum upper, lower;
    float g = 9.81;
    float dt = 0.01;

    float upper_alpha() {
        return (-g*(2*upper.mass + lower.mass)*sin(upper.theta)-lower.mass*g*sin(upper.theta-2*lower.theta)-2*sin(upper.theta-lower.theta)*lower.mass*(pow(lower.omega, 2)*lower.length+pow(upper.omega, 2)*lower.length*cos(upper.theta-lower.theta)))/(upper.length*(2*upper.mass+lower.mass-lower.mass*(2*upper.theta-2*lower.theta)));
    }
    
    float lower_alpha() {
        return (2*sin(upper.theta - lower.theta)*(pow(upper.omega, 2)*upper.length*(upper.mass+lower.mass)+g*(upper.mass+lower.mass)*cos(upper.theta)+pow(lower.omega, 2)*lower.length*lower.mass*cos(upper.theta-lower.theta)))/(upper.length*(2*upper.mass+lower.mass-lower.mass*(2*upper.theta-2*lower.theta)));
    }
public:
    DoublePendulum(Pendulum upper, Pendulum lower) {
        this->upper = upper;
        this->lower = lower;
    };
    
    Pendulum getUpper() {
        return this->upper;
    }
    
    Pendulum getLower() {
        return this->lower;
    }
    
    void update() { //advancing simulation with an Euler approximation
        upper.theta += upper_alpha() * dt;
        lower.theta += lower_alpha() * dt;
        upper.theta += upper.omega * dt;
        lower.theta += lower.omega * dt;
    }
    
};

PendulumComponent::PendulumComponent()
{
    Pendulum upper = {M_PI/3, 0, 1, 1};
    Pendulum lower = {-M_PI/3, 0, 1, 1};
    DoublePendulum dp = DoublePendulum(upper, lower);
}

PendulumComponent::~PendulumComponent()
{
}

void PendulumComponent::paint (juce::Graphics& g)
{
    g.setColour(juce::Colour(229, 149, 0)); //hex #E59500
    g.drawRect(getBounds(), 4);
}

void PendulumComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

