#pragma once


// maybe create a music player for background ambiente and one for music
class AudioHandler{
public:
	AudioHandler();
	virtual ~AudioHandler();
	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void continue_play() = 0;
};




