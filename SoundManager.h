#pragma once

#include "Singleton.h"
#include "SoundSample.h"

enum ExtensionType
{
	MP3,
	WAV,
};

class SoundManager : public Singleton<SoundManager>
{
	bool isMuted;
	float volume;
	string prefixPath;
	multimap<string, SoundSample*> allSamples;

public:
	FORCEINLINE void RegisterSample(SoundSample* _sample, const string& _path)
	{
		allSamples.insert(make_pair(_sample->GetPath(), _sample));
	}
	FORCEINLINE string GetExtension(const ExtensionType& _type)
	{
		return vector<string>({ ".mp3", ".wav", })[_type];
	}

public:
	SoundManager();
	~SoundManager();

public:
	SoundSample* PlaySound(const string& _path, const ExtensionType& _type = MP3);
	void PauseSound(const string& _path);
	void StopSound(const string& _path);
	void ToggleMute();
};

