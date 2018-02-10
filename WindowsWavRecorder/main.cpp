#include <memory>
#include "WavManager.h"
#include "WavRecord.h"
#include "common.h"

#define AUDIO_REC_DURATION 1
#define WAV_FILE_NAME L"record.wav"

int main()
{
	debug_log("Starting Example Programm");

	std::unique_ptr<WavManager> lManagerPtr = std::make_unique<WavManager>();

	debug_log("Recording audio");
	auto lRecordPtr = lManagerPtr->recordWavBlocking(AUDIO_REC_DURATION);
	if (!lRecordPtr)
	{
		debug_log("recordWavBlocking failed");
		return MY_ERROR;
	}

	debug_log("Playing recorded audio.");
	if (lManagerPtr->playWavBlocking(lRecordPtr.get()) == MY_ERROR)
	{
		debug_log("playWavBlocking failed.");
		return MY_ERROR;
	}

	debug_log("Writing record to disk");
	if (lRecordPtr->writeRecordToWavFile(WAV_FILE_NAME) == MY_ERROR)
	{
		debug_log("writeRecordToWavFile failed.");
		return MY_ERROR;
	}
	return SUCCESS;
}
