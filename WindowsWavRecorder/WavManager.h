#ifndef __WAV_MANAGER_H
#define __WAV_MANAGER_H

#include <memory>
#include "common.h"


class WavRecord;
class CVoiceRecording;
class CVoicePlaying;



class WavManager
{
public:

	/**
	* Constructor.
	*/
	WavManager();

	/**
	* Destructor.
	*/
	~WavManager();

	/**
	*
	*/
	std::unique_ptr<WavRecord> recordWavBlocking(UINT aDurationSecs);
	
	/**
	*
	*/
	int playWavBlocking(const WavRecord*  aWav);


private:
	/*
	* Recorder object.
	*/
	CVoiceRecording* mWaveRecorder;

	/*
	* Player object.
	*/
	CVoicePlaying* mWavePlayer;
};


#endif


/********************** End Of File ************************/