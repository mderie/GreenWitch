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

typedef unsigned char byte; // Same as juce::uint8

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public AudioAppComponent, public juce::MidiInputCallback,
	public ComboBox::Listener, public Button::Listener, public TextEditor::Listener //TODO: Check if we need the last one !
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

    bool m_flow = false;
    std::string m_prelude;
    std::string m_postlude;
    std::vector<std::string> m_dimensionsOutput;

    TextButton btnStart, btnStop, btnSetupSynth, btnClose;
    Label lblMidiInDevices, lblMidiOutDevices, lblDimension, lblD1, lblD2, lblD3, lblD4, lblD5;
    Label lblInput, lblOutput, lblInputCC, lblInputMinCC, lblInputMaxCC, lblOutputCC, lblOutputMinCC, lblOutputMaxCC;
    // Input CC ==> Midi event "kind", min & max for the acceptable range
    // Output CC ==> eventual mapping, min & max for the target range
    TextEditor txtD1InputCC, txtD1InputMin, txtD1InputMax, txtD1OutputCC, txtD1OutputMin, txtD1OutputMax;
    TextEditor txtD2InputCC, txtD2InputMin, txtD2InputMax, txtD2OutputCC, txtD2OutputMin, txtD2OutputMax;
    TextEditor txtD3InputCC, txtD3InputMin, txtD3InputMax, txtD3OutputCC, txtD3OutputMin, txtD3OutputMax;
    TextEditor txtD4InputCC, txtD4InputMin, txtD4InputMax, txtD4OutputCC, txtD4OutputMin, txtD4OutputMax;
    TextEditor txtD5InputCC, txtD5InputMin, txtD5InputMax, txtD5OutputCC, txtD5OutputMin, txtD5OutputMax;
    ComboBox cboMidiInDevices, cboMidiOutDevices;
    ComboBox cboD1OutputCC, cboD2OutputCC, cboD3OutputCC, cboD4OutputCC, cboD5OutputCC;
    //MidiDeviceModel mdmInputs, mdmOutputs;

	MidiInput* m_midiInput = nullptr;
	MidiOutput* m_midiOutput = nullptr;

	void sendMessage(const MidiMessage &msg) const;
	void sendPrelude() const;
	void sendPostlude() const;
	void getAllMidiDevices();
	void getAllOutputDimensions();
	byte getByte(const juce::MidiMessage &message, const int offset) const;
	juce::MidiMessage transformMidiMessage(const juce::MidiMessage &message, const byte b0, const byte b1, const byte b2);
	byte getTextHexValue(const TextEditor &te) const;
	std::string getNextToken(const std::string &token, const int offset) const;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
