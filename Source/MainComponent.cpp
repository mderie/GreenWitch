/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

#include "ConfigurationFiles.hpp"
#include "CommonStuffs.hpp"

#include <algorithm>
#include <string>
#include <vector>

/*
MidiDeviceModel::MidiDeviceModel()
{
//TODO
}

MidiDeviceModel::~MidiDeviceModel()
{
//TODO
}

int MidiDeviceModel::getNumRows()
{
//TODO
	return 0;
}

void MidiDeviceModel::paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected)
{
//TODO
}
*/

// Needed ?
//ConfigurationFile cf(appendPath({ runningFolder(), "GreenWitch.ini" }));

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize(446, 502);
    // Too early Dom !
    getTopLevelComponent()->setName("Welcome to the GreenWitch project"); // No effect :(

    // specify the number of input and output channels that we want to open
    //setAudioChannels (2, 2);
    setAudioChannels (0, 0); // We just do MIDI :)

    logThis("Session start", Target::misc);

    btnStart.setButtonText("Start");
    btnStart.addListener(this);
    addAndMakeVisible(btnStart);

	logThis("Session start 1", Target::misc);

    btnStop.setButtonText("Stop");
    btnStop.addListener(this);
    btnStop.setEnabled(false);
    addAndMakeVisible(btnStop);

    btnClose.setButtonText("Close");
    btnClose.addListener(this);
    addAndMakeVisible(btnClose);

	logThis("Session start 2", Target::misc);
    getAllMidiDevices();
	logThis("Session start 3", Target::misc);

    lblMidiInDevices.setText("Midi in devices", NotificationType::dontSendNotification);
    addAndMakeVisible(lblMidiInDevices);
    lblMidiOutDevices.setText("Midi out devices", NotificationType::dontSendNotification);
    addAndMakeVisible(lblMidiOutDevices);

	logThis("Session start 4", Target::misc);

    cboMidiInDevices.addListener(this);
    addAndMakeVisible(cboMidiInDevices);
    cboMidiOutDevices.addListener(this);
    addAndMakeVisible(cboMidiOutDevices);

    btnSetupSynth.setButtonText("Setup synth");
    btnSetupSynth.addListener(this);
    btnSetupSynth.setEnabled(false);
    addAndMakeVisible(btnSetupSynth);

	logThis("Session start 5", Target::misc);

    lblD1.setText("1", NotificationType::dontSendNotification);
    lblD2.setText("2", NotificationType::dontSendNotification);
    lblD3.setText("3", NotificationType::dontSendNotification);
    lblD4.setText("4", NotificationType::dontSendNotification);
    lblD5.setText("5", NotificationType::dontSendNotification);

    addAndMakeVisible(lblD1);
    addAndMakeVisible(lblD2);
    addAndMakeVisible(lblD3);
    addAndMakeVisible(lblD4);
    addAndMakeVisible(lblD5);

    lblInputCC.setText("CC", NotificationType::dontSendNotification);
    addAndMakeVisible(lblInputCC);
    lblInputMinCC.setText("Min", NotificationType::dontSendNotification);
    addAndMakeVisible(lblInputMinCC);
    lblInputMaxCC.setText("Max", NotificationType::dontSendNotification);
    addAndMakeVisible(lblInputMaxCC);
    lblOutputCC.setText("CC", NotificationType::dontSendNotification);
    addAndMakeVisible(lblOutputCC);
    lblOutputMinCC.setText("Min", NotificationType::dontSendNotification);
    addAndMakeVisible(lblOutputMinCC);
    lblOutputMaxCC.setText("Max", NotificationType::dontSendNotification);
    addAndMakeVisible(lblOutputMaxCC);

	logThis("Session start 6", Target::misc);

    String filePath = File::getCurrentWorkingDirectory().getFullPathName();
    ConfigurationFile cf(filePath.toStdString() + "/GreenWitch.ini"); //TODO: Do something multiplatform about this slash...
	// Seems to work anyway but in case the file is not present (artt least under Win) it hangs

	logThis("Session start 7", Target::misc);

    txtD1InputCC.setText(cf.keyValue("mapping", "D1CC"), false);
    txtD1InputCC.addListener(this);
    addAndMakeVisible(txtD1InputCC);
    txtD1InputMin.setText(cf.keyValue("mapping", "D1Min"), false);
    txtD1InputMin.addListener(this);
    addAndMakeVisible(txtD1InputMin);
    txtD1InputMax.setText(cf.keyValue("mapping", "D1Max"), false);
    txtD1InputMax.addListener(this);
    addAndMakeVisible(txtD1InputMax);
	//txtD1OutputCC.addListener(this);
	//addAndMakeVisible(txtD1OutputCC);
	cboD1OutputCC.addListener(this);
	addAndMakeVisible(cboD1OutputCC);
    txtD1OutputMin.addListener(this);
    addAndMakeVisible(txtD1OutputMin);
    txtD1OutputMax.addListener(this);
    addAndMakeVisible(txtD1OutputMax);

    txtD2InputCC.setText(cf.keyValue("mapping", "D2CC"), false);
    txtD2InputCC.addListener(this);
    addAndMakeVisible(txtD2InputCC);
    txtD2InputMin.setText(cf.keyValue("mapping", "D2Min"), false);
    txtD2InputMin.addListener(this);
    addAndMakeVisible(txtD2InputMin);
    txtD2InputMax.setText(cf.keyValue("mapping", "D2Max"), false);
    txtD2InputMax.addListener(this);
    addAndMakeVisible(txtD2InputMax);
	//txtD2OutputCC.addListener(this);
	//addAndMakeVisible(txtD2OutputCC);
	cboD2OutputCC.addListener(this);
	addAndMakeVisible(cboD2OutputCC);
    txtD2OutputMin.addListener(this);
    addAndMakeVisible(txtD2OutputMin);
    txtD2OutputMax.addListener(this);
    addAndMakeVisible(txtD2OutputMax);

    txtD3InputCC.setText(cf.keyValue("mapping", "D3CC"), false);
	txtD3InputCC.addListener(this);
    addAndMakeVisible(txtD3InputCC);
    txtD3InputMin.setText(cf.keyValue("mapping", "D3Min"), false);
    txtD3InputMin.addListener(this);
    addAndMakeVisible(txtD3InputMin);
    txtD3InputMax.setText(cf.keyValue("mapping", "D3Max"), false);
    txtD3InputMax.addListener(this);
    addAndMakeVisible(txtD3InputMax);
	//txtD3OutputCC.addListener(this);
	//addAndMakeVisible(txtD3OutputCC);
	cboD3OutputCC.addListener(this);
	addAndMakeVisible(cboD3OutputCC);
    txtD3OutputMin.addListener(this);
    addAndMakeVisible(txtD3OutputMin);
    txtD3OutputMax.addListener(this);
    addAndMakeVisible(txtD3OutputMax);

    txtD4InputCC.setText(cf.keyValue("mapping", "D4CC"), false);
	txtD4InputCC.addListener(this);
    addAndMakeVisible(txtD4InputCC);
    txtD4InputMin.setText(cf.keyValue("mapping", "D4Min"), false);
    txtD4InputMin.addListener(this);
    addAndMakeVisible(txtD4InputMin);
    txtD4InputMax.setText(cf.keyValue("mapping", "D4Max"), false);
    txtD4InputMax.addListener(this);
    addAndMakeVisible(txtD4InputMax);
	//txtD4OutputCC.addListener(this);
	//addAndMakeVisible(txtD4OutputCC);
	cboD4OutputCC.addListener(this);
	addAndMakeVisible(cboD4OutputCC);
    txtD4OutputMin.addListener(this);
    addAndMakeVisible(txtD4OutputMin);
    txtD4OutputMax.addListener(this);
    addAndMakeVisible(txtD4OutputMax);

    txtD5InputCC.setText(cf.keyValue("mapping", "D5CC"), false);
    txtD5InputCC.addListener(this);
    addAndMakeVisible(txtD5InputCC);
    txtD5InputMin.setText(cf.keyValue("mapping", "D5Min"), false);
    txtD5InputMin.addListener(this);
    addAndMakeVisible(txtD5InputMin);
    txtD5InputMax.setText(cf.keyValue("mapping", "D5Max"), false);
    txtD5InputMax.addListener(this);
    addAndMakeVisible(txtD5InputMax);
	//txtD5OutputCC.addListener(this);
	//addAndMakeVisible(txtD5OutputCC);
	cboD5OutputCC.addListener(this);
	addAndMakeVisible(cboD5OutputCC);
    txtD5OutputMin.addListener(this);
    addAndMakeVisible(txtD5OutputMin);
    txtD5OutputMax.addListener(this);
    addAndMakeVisible(txtD5OutputMax);

    lblDimension.setText("Dimension", NotificationType::dontSendNotification);
    addAndMakeVisible(lblDimension);
    lblInput.setText("Input", NotificationType::dontSendNotification);
    addAndMakeVisible(lblInput);
	lblOutput.setText("Output", NotificationType::dontSendNotification);
	addAndMakeVisible(lblOutput);

    // Doesn't work as expected
    //resized();
	
	logThis("Session start 8", Target::misc);

    m_dimensionsOutput = split(cf.keyValue("mapping", "DxOutput"), ";");
    logThis2("DxOutput = %s", Target::misc, cf.keyValue("mapping", "DxOutput").c_str());
    for (size_t i = 0; i < m_dimensionsOutput.size(); i++)
    {
		logThis2("m_dimensionsOutput[%d] = %s", Target::misc, i, m_dimensionsOutput[i].c_str());

		logThis("Session start 9", Target::misc);
    }

	logThis("Session start aa", Target::misc);
    getAllOutputDimensions();
	logThis("Session start bb", Target::misc);
}

MainComponent::~MainComponent()
{
	logThis("Session stop", Target::misc);
    // This shuts down the audio device and clears the audio source.

	if (m_midiInput != nullptr)
	{
		m_midiInput->stop();
		delete m_midiInput;
	}

	if (m_midiOutput != nullptr)
	{
		//midiOutput->stop();
		delete m_midiOutput;
	}

    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!

    Image background = juce::ImageCache::getFromMemory(BinaryData::background_gif, 61925);
    g.drawImageAt(background, 0, 0); // 446 * 502 Use Pinta
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    //TODO : Check why this doesn't work until one resizes the window...
    getTopLevelComponent()->setName("Welcome to the GreenWitch project");

    int buttonWidth = (getWidth() - (4 * 20)) / 3; // Three buttons but four spaces !-)

    btnStart.setBounds((1 * 20) + (0 * buttonWidth), 20, buttonWidth, 20); // Remember : (x, y, w ,h)
    btnStop.setBounds((2 * 20) + (1 * buttonWidth), 20, buttonWidth, 20);
    btnClose.setBounds((3 * 20) + (2 * buttonWidth), 20, buttonWidth, 20);

    int labelWidth = (getWidth() - (3 * 20)) / 2;
    lblMidiInDevices.setBounds((1 * 20) + (0 * labelWidth), 40, labelWidth, 20);
    lblMidiOutDevices.setBounds((2 * 20) + (1 * labelWidth), 40, labelWidth, 20);

    int comboboxWidth = labelWidth;
    cboMidiInDevices.setBounds((1 * 20) + (0 * comboboxWidth), 60, comboboxWidth, 20);
    cboMidiOutDevices.setBounds((2 * 20) + (1 * comboboxWidth), 60, comboboxWidth, 20);

    btnSetupSynth.setBounds(20, 100, getWidth() - 40, 20);

    // Create a virtual midi port
    // https://superuser.com/questions/1164838/virtual-midi-port-route-in-rasbian
    //
    // sudo modprobe snd-virmidi snd_index=1
    // aconnect -lio

    lblInput.setBounds(40, 160, 80, 20);
	lblDimension.setBounds(180,160, 80, 20);
	lblOutput.setBounds(320, 160, 80, 20);

	lblInputCC.setBounds(20, 180, 40, 20);
	lblInputMinCC.setBounds(80, 180, 40, 20);
	lblInputMaxCC.setBounds(140, 180, 40, 20);
	lblOutputCC.setBounds(260, 180, 40, 20);
	lblOutputMinCC.setBounds(320, 180, 40, 20);
	lblOutputMaxCC.setBounds(380, 180, 40, 20);

    lblD1.setBounds(210, 200, 40, 20);
    lblD2.setBounds(210, 220, 40, 20);
    lblD3.setBounds(210, 240, 40, 20);
    lblD4.setBounds(210, 260, 40, 20);
    lblD5.setBounds(210, 280, 40, 20);

    txtD1InputCC.setBounds(20, 200, 40, 20);
    txtD2InputCC.setBounds(20, 220, 40, 20);
    txtD3InputCC.setBounds(20, 240, 40, 20);
    txtD4InputCC.setBounds(20, 260, 40, 20);
    txtD5InputCC.setBounds(20, 280, 40, 20);

    txtD1InputMin.setBounds(80, 200, 40, 20);
    txtD2InputMin.setBounds(80, 220, 40, 20);
    txtD3InputMin.setBounds(80, 240, 40, 20);
    txtD4InputMin.setBounds(80, 260, 40, 20);
    txtD5InputMin.setBounds(80, 280, 40, 20);

    txtD1InputMax.setBounds(140, 200, 40, 20);
    txtD2InputMax.setBounds(140, 220, 40, 20);
    txtD3InputMax.setBounds(140, 240, 40, 20);
    txtD4InputMax.setBounds(140, 260, 40, 20);
    txtD5InputMax.setBounds(140, 280, 40, 20);

    /*
    txtD1OutputCC.setBounds(260, 200, 40, 20);
    txtD2OutputCC.setBounds(260, 220, 40, 20);
    txtD3OutputCC.setBounds(260, 240, 40, 20);
    txtD4OutputCC.setBounds(260, 260, 40, 20);
    txtD5OutputCC.setBounds(260, 280, 40, 20);
    */
    cboD1OutputCC.setBounds(260, 200, 40, 20);
    cboD2OutputCC.setBounds(260, 220, 40, 20);
    cboD3OutputCC.setBounds(260, 240, 40, 20);
    cboD4OutputCC.setBounds(260, 260, 40, 20);
    cboD5OutputCC.setBounds(260, 280, 40, 20);

    txtD1OutputMin.setBounds(320, 200, 40, 20);
    txtD2OutputMin.setBounds(320, 220, 40, 20);
    txtD3OutputMin.setBounds(320, 240, 40, 20);
    txtD4OutputMin.setBounds(320, 260, 40, 20);
    txtD5OutputMin.setBounds(320, 280, 40, 20);

    txtD1OutputMax.setBounds(380, 200, 40, 20);
    txtD2OutputMax.setBounds(380, 220, 40, 20);
    txtD3OutputMax.setBounds(380, 240, 40, 20);
    txtD4OutputMax.setBounds(380, 260, 40, 20);
    txtD5OutputMax.setBounds(380, 280, 40, 20);
}

void MainComponent::buttonClicked(Button *sender)
{
	//if (sender->getName() == "Close")
	if (sender == &btnClose)
	{
		JUCEApplication::getInstance()->systemRequestedQuit();
	}
	else if ((sender == &btnStart) && (m_midiInput != nullptr) && (m_midiOutput != nullptr))
	{
		btnStop.setEnabled(true);
		btnStart.setEnabled(false);
		cboMidiInDevices.setEnabled(false);
		cboMidiOutDevices.setEnabled(false);
		btnSetupSynth.setEnabled(false);
		logThis("Flow on", Target::misc);
		m_flow = true;
		m_midiInput->start();
	}
	else if (sender == &btnStop)
	{
		btnStop.setEnabled(false);
		btnStart.setEnabled(true);
		cboMidiInDevices.setEnabled(true);
		cboMidiOutDevices.setEnabled(true);
		btnSetupSynth.setEnabled(true);
		logThis("Flow off", Target::misc);
		m_flow = false;
		m_midiInput->stop();
	}
	else if (sender == &btnSetupSynth)
	{
		//TODO: This should come from configuration file ?
		if (cboMidiOutDevices.getText().contains("blofeld"))
		{
			// Time to be specific :)
			juce::MidiMessage message(0, 0, 0); // Strange : in order to code completion, one must mention explicitely the namespace !
			m_midiOutput->sendMessageNow(message);
		}
	}
}

void MainComponent::comboBoxChanged(ComboBox *sender)
{
	//logThis("Step 0", Target::misc);
	//return;
	if (sender == &cboMidiInDevices)
	{
		//logThis("Step 1", Target::misc);
		if (m_midiInput != nullptr)
		{
			//logThis("Step 2", Target::misc);
			m_midiInput->stop();
			//logThis("Step 3", Target::misc);
			delete m_midiInput;
			//logThis("Step 4", Target::misc);
		}
		//logThis("Step 5", Target::misc);
		m_midiInput = juce::MidiInput::openDevice(cboMidiInDevices.getSelectedId() - 1, this);
		logThis("New midi input device = ...", Target::midi);
		logThis(cboMidiInDevices.getText().toRawUTF8(), Target::midi);
	}
	else if (sender == &cboMidiOutDevices)
	{
		if (m_midiOutput != nullptr)
		{
			//midiOutput->stop();
			delete m_midiOutput;
		}
		m_midiOutput = juce::MidiOutput::openDevice(cboMidiOutDevices.getSelectedId() - 1);
		btnSetupSynth.setEnabled(true);
		logThis("New midi ouptut device = ...", Target::midi);
		logThis(cboMidiOutDevices.getText().toRawUTF8(), Target::midi);
	}
	else if (sender == &cboD1OutputCC)
	{
		logThis2("cboD1OutputCC.getSelectedId() = %d", Target::misc, cboD1OutputCC.getSelectedId() - 1);
		logThis2("%s", Target::misc, m_dimensionsOutput[cboD1OutputCC.getSelectedId() - 1].c_str());
		txtD1OutputCC.setText(getNextToken(m_dimensionsOutput[cboD1OutputCC.getSelectedId() - 1], 1) , false);
		txtD1OutputMin.setText(getNextToken(m_dimensionsOutput[cboD1OutputCC.getSelectedId() - 1], 2) , false);
		txtD1OutputMax.setText(getNextToken(m_dimensionsOutput[cboD1OutputCC.getSelectedId() - 1], 3) , false);
	}
	else if (sender == &cboD2OutputCC)
	{
		txtD2OutputCC.setText(getNextToken(m_dimensionsOutput[cboD2OutputCC.getSelectedId() - 1], 1) , false);
		txtD2OutputMin.setText(getNextToken(m_dimensionsOutput[cboD2OutputCC.getSelectedId() - 1], 2) , false);
		txtD2OutputMax.setText(getNextToken(m_dimensionsOutput[cboD2OutputCC.getSelectedId() - 1], 3) , false);
	}
	else if (sender == &cboD3OutputCC)
	{
		txtD3OutputCC.setText(getNextToken(m_dimensionsOutput[cboD3OutputCC.getSelectedId() - 1], 1) , false);
		txtD3OutputMin.setText(getNextToken(m_dimensionsOutput[cboD3OutputCC.getSelectedId() - 1], 2) , false);
		txtD3OutputMax.setText(getNextToken(m_dimensionsOutput[cboD3OutputCC.getSelectedId() - 1], 3) , false);
	}
	else if (sender == &cboD4OutputCC)
	{
		txtD4OutputCC.setText(getNextToken(m_dimensionsOutput[cboD4OutputCC.getSelectedId() - 1], 1) , false);
		txtD4OutputMin.setText(getNextToken(m_dimensionsOutput[cboD4OutputCC.getSelectedId() - 1], 2) , false);
		txtD4OutputMax.setText(getNextToken(m_dimensionsOutput[cboD4OutputCC.getSelectedId() - 1], 3) , false);
	}
	else if (sender == &cboD5OutputCC)
	{
		txtD5OutputCC.setText(getNextToken(m_dimensionsOutput[cboD5OutputCC.getSelectedId() - 1], 1) , false);
		txtD5OutputMin.setText(getNextToken(m_dimensionsOutput[cboD5OutputCC.getSelectedId() - 1], 2) , false);
		txtD5OutputMax.setText(getNextToken(m_dimensionsOutput[cboD5OutputCC.getSelectedId() - 1], 3) , false);
	}
}

byte MainComponent::getTextHexValue(const TextEditor &te)
{
	return (stoi(te.getText().toStdString())); // New in C++ 11 :)
}

std::string MainComponent::getNextToken(const std::string &token, int offset)
{
	auto it = std::find(m_dimensionsOutput.begin(), m_dimensionsOutput.end(), token);
	if (it == m_dimensionsOutput.end())
	{
		return "";
	}

	for (int i = 0; i < offset; i++)
	{
		it++;
	}

	return *it;
}

juce::MidiMessage MainComponent::transformMidiMessage(const juce::MidiMessage& message, const byte b0, const byte b1, const byte b2)
{
	if (b0 != 0xCC)
	{
		return message;
	}

	// Can't do a switch (b1) here...
	if (b1 == getTextHexValue(txtD1InputCC))
	{
	}
	else if (b1 == getTextHexValue(txtD2InputCC))
	{
	}
	else if (b1 == getTextHexValue(txtD3InputCC))
	{
	}
	else if (b1 == getTextHexValue(txtD4InputCC))
	{
	}
	else if (b1 == getTextHexValue(txtD5InputCC))
	{
		byte inputMin = getTextHexValue(txtD5InputMin);
		byte inputMax = getTextHexValue(txtD5InputMax);
		byte outputMin = getTextHexValue(txtD5OutputMin);
		byte outputMax = getTextHexValue(txtD5OutputMax);

		return juce::MidiMessage(0xCC, getTextHexValue(txtD5OutputCC), (b2 * (outputMax - outputMin)) / (inputMax - inputMin));
	}

	return message;
}

void MainComponent::handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message)
{
	logThis("Incomming message = ...", Target::midi);
	const juce::uint8* p = message.getRawData();
	std::string s;
	byte b0 = 0;
	byte b1 = 0;
	byte b2 = 0;

	for (int i = 0; i < message.getRawDataSize(); i++)
	{
		if (i == 0)
		{
			b0 = static_cast<int>(*(p+0));
		}
		else if (i == 1)
		{
			b1 = static_cast<int>(*(p+1));
		}
		else if (i == 2)
		{
			b2 = static_cast<int>(*(p+2));
		}

		s = intToStr(static_cast<int>(*(p + i)));
		logThis(s.c_str(), Target::midi);
	}
	logThis2("channel = %d", Target::midi, message.getChannel());
	//logThis("channel = ...", Target::midi, Target::midi);
	//logThis((intToStr(message.getChannel())).c_str(), Target::midi);

	if (m_flow && m_midiOutput)
	{
		//TODO: Check this : I assume here that we are sending multichannel too...
		//m_midiOutput->sendMessageNow(message);
		m_midiOutput->sendMessageNow(transformMidiMessage(message, b0, b1, b2));
	}
}

void MainComponent::getAllMidiDevices()
{
	juce::StringArray names = juce::MidiInput::getDevices();
	for (int i = 0; i < names.size(); i++)
	{
		cboMidiInDevices.addItem(names[i], i + 1); // See JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp L:87 assertion...
	}

	names = juce::MidiOutput::getDevices();
	for (int i = 0; i < names.size(); i++)
	{
		cboMidiOutDevices.addItem(names[i], i + 1); // ... We can't use index = 0 it means no item selected
	}
}

void MainComponent::getAllOutputDimensions()
{
	size_t i = 0;
	while (i < m_dimensionsOutput.size())
	{
		//logThis2("m_dimensionsOutput[%d] = %s", Target::misc, i, m_dimensionsOutput[i].c_str());
		cboD1OutputCC.addItem(m_dimensionsOutput[i], i + 1);
		cboD2OutputCC.addItem(m_dimensionsOutput[i], i + 1);
		cboD3OutputCC.addItem(m_dimensionsOutput[i], i + 1);
		cboD4OutputCC.addItem(m_dimensionsOutput[i], i + 1);
		cboD5OutputCC.addItem(m_dimensionsOutput[i], i + 1);
		i += 4;
	}
}
