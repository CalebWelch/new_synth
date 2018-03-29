/*
  ==============================================================================

    SynthVoice.h
    Created: 2 Mar 2018 1:48:06pm
    Author:  CW056762

  ==============================================================================
*/

#pragma once
#include "../../modules/libraries/Maximilian/maximilian.h"
#include "SynthSound.h"
#include "../JuceLibraryCode/JuceHeader.h"

class SynthVoice : public SynthesiserVoice
{
public: 
	bool canPlaySound(SynthesiserSound * sound){
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}
	void startNote(
		int midiNoteNumber, 
		float velocity, 
		SynthesiserSound *sound, 
		int currentPitchWheelPosition)
	{

		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		start_note = midiNoteNumber;
	}
	int getStartNote() {
		return start_note;
	}
	void stopNote(float velocity, bool allowTailOff){
		clearCurrentNote();
	}
	void pitchWheelMoved(int newPitchWheelValue){

	}
	void controllerMoved(int controllerNumber, int newControllerValue){

	}
	void aftertouchChanged(int newAftertouchValue){

	}
	void renderNextBlock(AudioBuffer< float > &outputBuffer, int startSample, int numSamples) {
		for (int i = 0; i < numSamples; i++) {
		double wave = osc1.sinewave(440);
			for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++) {
				outputBuffer.addSample(channel, startSample, wave);
			}
			++startSample;
		}
	}
	void channelPressureChanged(int newChannelPressureValue) {

	}
	void renderNextBlock(AudioBuffer< double > &outputBuffer, int startSample, int numSamples) {

	}
	void setCurrentPlaybackSampleRate(double newRate) {

	} 
	int start_note;
private:
	float frequency;
	float level;
	maxiOsc osc1;
};
