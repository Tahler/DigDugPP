
#ifndef SOUND_H
#define SOUND_H

struct Sound
{
	static void stopSoundEffects();

	static void playBlockBreak();
	static void playResourceBreak();
	static void playGemBreak();
	
	static void playDeath();

	static void playSell();

	static void playMusic();
};

#endif
