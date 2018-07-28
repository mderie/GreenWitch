/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

#include "ConfigurationFiles.hpp"
#include "CommonStuffs.hpp"

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

    btnStop.setButtonText("Stop");
    btnStop.addListener(this);
    btnStop.setEnabled(false);
    addAndMakeVisible(btnStop);

    btnClose.setButtonText("Close");
    btnClose.addListener(this);
    addAndMakeVisible(btnClose);

    getAllMidiDevices();

    lblMidiInDevices.setText("Midi in devices", NotificationType::dontSendNotification);
    addAndMakeVisible(lblMidiInDevices);
    lblMidiOutDevices.setText("Midi out devices", NotificationType::dontSendNotification);
    addAndMakeVisible(lblMidiOutDevices);

    cboMidiInDevices.addListener(this);
    addAndMakeVisible(cboMidiInDevices);
    cboMidiOutDevices.addListener(this);
    addAndMakeVisible(cboMidiOutDevices);

    btnSetupSynth.setButtonText("Setup synth");
    btnSetupSynth.addListener(this);
    btnSetupSynth.setEnabled(false);
    addAndMakeVisible(btnSetupSynth);

    lblD1.setText("D1", NotificationType::dontSendNotification);
    lblD2.setText("D2", NotificationType::dontSendNotification);
    lblD3.setText("D3", NotificationType::dontSendNotification);
    lblD4.setText("D4", NotificationType::dontSendNotification);
    lblD5.setText("D5", NotificationType::dontSendNotification);
    addAndMakeVisible(lblD1);
    addAndMakeVisible(lblD2);
    addAndMakeVisible(lblD3);
    addAndMakeVisible(lblD4);
    addAndMakeVisible(lblD5);

    // Doesn't work as expected
    //resized();
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

    Image background = juce::ImageCache::getFromMemory(BinaryData::background_jpg, 21966);
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

    lblDimension.setBounds(20,20,40,20);
    //lblInput
    //lblOutput

    lblD1.setBounds(20,20,40,20);
    lblD2.setBounds(20,20,40,20);
    lblD3.setBounds(20,20,40,20);
    lblD4.setBounds(20,20,40,20);
    lblD5.setBounds(20,20,40,20);


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
}

void MainComponent::handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message)
{
	logThis("Incomming message = ...", Target::midi);
	const juce::uint8* p = message.getRawData();
	std::string s;
	for (int i = 0; i < message.getRawDataSize(); i++)
	{
		s = intToStr(static_cast<int>(*(p + i)));
		logThis(s.c_str(), Target::midi);
	}
	logThis2("channel = %d", Target::midi, message.getChannel());
	//logThis("channel = ...", Target::midi, Target::midi);
	//logThis((intToStr(message.getChannel())).c_str(), Target::midi);

	if (m_flow && m_midiOutput)
	{
		m_midiOutput->sendMessageNow(message); // I assume here that we are sending multichannel too...
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
