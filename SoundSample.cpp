#include "SoundSample.h"
#include "SoundManager.h"

SoundSample::SoundSample(const string& _path)
{
	path = _path;
	if (!buffer.loadFromFile(_path))
	{
		LOG(Error, "Invalid path : " + _path);
		sound = nullptr;
		return;
	}
	volume = 0.1f;
	sound = new Sound(buffer);
	sound->setVolume(volume);
	M_SOUND.RegisterSample(this, path);
}

SoundSample::~SoundSample()
{
	delete sound;
}

void SoundSample::Play(const Time& _time)
{
	if (GetStatus() == SoundStatus::Paused)
	{
		sound->stop();
	}
	SetVolume(volume);
	sound->play();
	sound->setPlayingOffset(_time);
}

void SoundSample::Pause()
{
	sound->pause();
}

void SoundSample::Stop()
{
	sound->stop();
}

void SoundSample::Mute()
{
	
}
