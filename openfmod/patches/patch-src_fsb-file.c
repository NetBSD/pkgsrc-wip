$NetBSD$

--- src/fsb-file.c.orig	2020-11-09 09:14:31.000000000 +0000
+++ src/fsb-file.c
@@ -51,9 +51,9 @@ static bool ensure_sound_loaded(FMOD_STU
 	if (snd->is_loaded) return true;
 
 	if (snd->is_mem) {
-		snd->handle = gau_create_handle_buffered_file(sys->ga.mixer, sys->ga.stream_mgr, snd->fpath, GAU_AUDIO_TYPE_OGG, NULL, NULL, NULL);
+		snd->handle = gau_create_handle_buffered_file(sys->ga.mixer, sys->ga.stream_mgr, snd->fpath, GauAudioType_Ogg, NULL, NULL, NULL);
 	} else {
-		ga_Sound *sound = gau_load_sound_file(snd->fpath, GAU_AUDIO_TYPE_OGG);
+		GaSound *sound = gau_load_sound_file(snd->fpath, GauAudioType_Ogg);
 		if (!sound) return false;
 		snd->handle = gau_create_handle_sound(sys->ga.mixer, sound, NULL, NULL, NULL);
 	}
