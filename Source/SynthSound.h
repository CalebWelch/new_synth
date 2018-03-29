
/*
  ==============================================================================

    SynthSound.h
    Created: 2 Mar 2018 1:47:52pm
    Author:  CW056762

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../../modules/libraries/Maximilian/maximilian.h"

class SynthSound : public SynthesiserSound
{
public:
	bool appliesToNote(int midinote){
		return true;
	}
	bool appliesToChannel(int midichannel){
		return true;

	}

};