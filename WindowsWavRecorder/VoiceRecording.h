
/*
* Author: Kosta Bulgakov
*
* Date: 05/10/2016
*
* Brief: This file contains header of class
*        that used as windows audio recording tool.
*
*/

#ifndef _VOICE_RECORDING_H
#define _VOICE_RECORDING_H

#include "VoiceBase.h"
#include <iostream>

void CALLBACK VoiceWaveInProc(
						 HWAVEIN hwi,       
						 UINT uMsg,         
						 DWORD dwInstance,  
						 DWORD dwParam1,    
						 DWORD dwParam2     
						 );


/**
* Class that used to record voice from voice input device.
*
*/
class CVoiceRecording : public CVoiceBase  
{
public:
	/**
	* Constructor.
	*/
	CVoiceRecording();
	/*
	* Destructor.
	*/
	virtual ~CVoiceRecording();
	/**
	*
	*/
	virtual void RecordFinished();

	/**
	*
	*/
	BOOL IsOpen();

	/**
	*
	*/
	BOOL Close();

	/**
	*
	*/
	BOOL Open();

	/**
	*
	*/
    BOOL Record();


    HWAVEIN hWaveIn;
	HANDLE hRecordIsDoneEvent;

};

#endif
