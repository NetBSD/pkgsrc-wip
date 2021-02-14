$NetBSD$

Prefer the SDL driver, since the openal driver may crash the game
(issue needs investigating).

--- id_sd.cpp.orig	2021-02-14 11:47:46.000000000 +0000
+++ id_sd.cpp
@@ -337,11 +337,11 @@ void sd_startup()
 
 			case AudioDriverType::auto_detect:
 			default:
-				if (sd_initialize_driver(AudioDriverType::r3_openal, snd_rate, snd_mix_size))
+				if (sd_initialize_driver(AudioDriverType::r2_sdl, snd_rate, snd_mix_size))
 				{
 					is_driver_initialized = true;
 				}
-				else if (sd_initialize_driver(AudioDriverType::r2_sdl, snd_rate, snd_mix_size))
+				else if (sd_initialize_driver(AudioDriverType::r3_openal, snd_rate, snd_mix_size))
 				{
 					is_driver_initialized = true;
 				}
