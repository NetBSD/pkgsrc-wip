$NetBSD$

Older SDL2_mixer used MIX_INIT_FLUIDSYNTH which has been renamed
to MIX_INIT_MID.

--- mixer.cpp.orig	2016-02-02 10:21:42.000000000 +0000
+++ mixer.cpp
@@ -53,7 +53,7 @@ struct Mixer_impl {
 		memset(_samples, 0, sizeof(_samples));
 		_music = 0;
 
-		Mix_Init(MIX_INIT_OGG | MIX_INIT_FLUIDSYNTH);
+		Mix_Init(MIX_INIT_OGG | MIX_INIT_MID);
 		if (Mix_OpenAudio(kMixFreq, AUDIO_S16SYS, 2, kMixBufSize) < 0) {
 			warning("Mix_OpenAudio failed: %s", Mix_GetError());
 		}
