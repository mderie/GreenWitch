/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

/*
class MidiDeviceModel : public ListBoxModel
{
public:
	MidiDeviceModel();
	~MidiDeviceModel();

	int getNumRows() override;
	void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected) override;
};
*/

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public AudioAppComponent, public Button::Listener, public ComboBox::Listener, public juce::MidiInputCallback
{
public:
    virtual void buttonClicked(Button *sender) override;
    virtual void comboBoxChanged(ComboBox *sender) override;
    virtual void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;

    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    bool flow = false;

    TextButton btnStart, btnStop, btnClose;
    Label lblMidiInDevices, lblMidiOutDevices;
    ComboBox cboMidiInDevices, cboMidiOutDevices;
    //MidiDeviceModel mdmInputs, mdmOutputs;

	MidiInput* midiInput = nullptr;
	MidiOutput* midiOutput = nullptr;

	void getAllMidiDevices();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
