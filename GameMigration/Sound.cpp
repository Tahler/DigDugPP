
#include "Sound.h"
#include "Core.h"
#include <mmsystem.h>

// Stop the sound so that it can play again.
// Play sound effect
void Sound::stopSoundEffects()
{
	mciSendString(TEXT("stop resources/breakBlock.wav"), nullptr, 0, nullptr);
	mciSendString(TEXT("stop resources/breakResource.wav"), nullptr, 0, nullptr);
	mciSendString(TEXT("stop resources/breakGem.wav"), nullptr, 0, nullptr);
}
void Sound::playBlockBreak()
{
	stopSoundEffects();
	mciSendString(TEXT("play resources/breakBlock.wav"), nullptr, 0, nullptr);
}
void Sound::playResourceBreak()
{
	stopSoundEffects();
	mciSendString(TEXT("play resources/breakResource.wav"), nullptr, 0, nullptr);
}
void Sound::playGemBreak()
{
	stopSoundEffects();
	mciSendString(TEXT("play resources/breakGem.wav"), nullptr, 0, nullptr);
}

void Sound::playDeath()
{
	stopSoundEffects();
	mciSendString(TEXT("play resources/death.wav"), nullptr, 0, nullptr);
}

void Sound::playSell()
{
	
}

void Sound::playMusic()
{
	mciSendString(TEXT("open resources/music.wav type mpegvideo alias song"), nullptr, 0, nullptr);
	mciSendString(TEXT("play song repeat"), nullptr, 0, nullptr);
}
