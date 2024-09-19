$NetBSD: patch-source_linux_main.cpp,v 1.1 2014/11/02 08:36:13 nsloss Exp $

Add frameskip soundskip scanlines abilit to change to native format
and emulation speed.
Remove dependency on gtk
--- source/linux/main.cpp.orig	2008-10-23 03:44:46.000000000 +0000
+++ source/linux/main.cpp
@@ -17,6 +17,7 @@
 #include <sys/types.h>
 #include <errno.h>
 #include <vector>
+#include <libgen.h>
 
 #include "core/api/NstApiEmulator.hpp"
 #include "core/api/NstApiVideo.hpp"
@@ -46,12 +47,12 @@
 #define NST_VERSION "1.4.0 [release H]"
 
 extern "C" {
-#include <gtk/gtk.h>
+//#include <gtk/gtk.h>
 
-#include "callbacks.h"
+//#include "callbacks.h"
 }
 
-#include "uihelp.h"
+//#include "uihelp.h"
 
 using namespace Nes::Api;
 using namespace LinuxNst;
@@ -65,6 +66,12 @@ void SetupSound();
 void SetupInput();
 
 SDL_Surface *screen;
+SDL_Surface *newscreen;
+SDL_Surface *altscreen;
+SDL_PixelFormat RGB16 = { NULL, 16, 2, 0,0,0,0,0,0,0,0, 0xf800,0x7e0,0x1f,0,0,0};
+SDL_PixelFormat RGB32 = { NULL, 32, 4, 0,0,0,0,0,0,0,0, 0xff0000,0xff00,0xff,0,0,0};
+SDL_PixelFormat BGR16 = { NULL, 16, 2, 0,0,0,0,0,0,0,0, 0x1f,0x7e0,0xf800,0,0,0};
+SDL_PixelFormat BGR32 = { NULL, 32, 4, 0,0,0,0,0,0,0,0, 0xff,0xff00,0xff0000,0,0,0};
 
 static short lbuf[48000];
 static long exholding[48000*2];
@@ -77,7 +84,7 @@ static int schedule_stop = 0;
 static SDL_Joystick *joy[10];
 
 extern int lnxdrv_apimode;
-extern GtkWidget *mainwindow;
+//extern GtkWidget *mainwindow;
 
 static char savename[512], capname[512], gamebasename[512];
 static char caption[128];
@@ -168,7 +175,7 @@ static void opengl_cleanup()
 {
 	if (using_opengl)
 	{
-		SDL_FreeSurface( screen );
+		SDL_FreeSurface( newscreen );
 		glDeleteTextures( 1, &screenTexID );
 		if (intbuffer)
 		{
@@ -215,6 +222,7 @@ long Linux_LockScreen(void*& ptr)
 	}
 	else
 	{
+		if (SDL_MUSTLOCK(newscreen)) SDL_LockSurface(newscreen);
 		if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
 
 		ptr = intbuffer;
@@ -233,7 +241,9 @@ void Linux_UnlockScreen(void*)
 		unsigned short *src, *dst1;
 		unsigned int *srcL, *dst1L;
 		int x, y, vdouble;
+		static int frame = 0;
 
+		if (frame == sSettings->GetFrameSkip()) {
 		// is this a software x2 expand for NTSC mode?
 		vdouble = 0;
 		if (screen->h == (cur_height<<1))
@@ -244,11 +254,14 @@ void Linux_UnlockScreen(void*)
 		if (screen->format->BitsPerPixel == 16)
 		{
 			src = (UINT16 *)intbuffer;
-			dst1 = (UINT16 *)screen->pixels;
+			dst1 = (UINT16 *)newscreen->pixels;
 
 			for (y = 0; y < cur_Rheight; y++)
 			{
-				memcpy(dst1, src, cur_width*screen->format->BitsPerPixel/8);
+				if (sSettings->GetScanlines() && (y & 1))
+					memset(dst1, 0, cur_width*newscreen->format->BitsPerPixel/8);
+				else
+					memcpy(dst1, src, cur_width*newscreen->format->BitsPerPixel/8);
 				if (vdouble)
 				{
 					if (!(y & 1))
@@ -260,17 +273,26 @@ void Linux_UnlockScreen(void*)
 				{
 					src += cur_width;
 				}
-				dst1 += screen->pitch/2;
+				dst1 += newscreen->pitch/2;
 			}
+			dst1 = (UINT16 *)screen->pixels;
+			if (sSettings->GetBGR()) {
+				altscreen = SDL_ConvertSurface(newscreen, &BGR16, 0);
+				memcpy(dst1, altscreen->pixels, cur_Rheight*screen->pitch);
+			} else
+				memcpy(dst1, newscreen->pixels, cur_Rheight*screen->pitch);
 		}
 		else if (screen->format->BitsPerPixel == 32)
 		{
 			srcL = (UINT32 *)intbuffer;
-			dst1L = (UINT32 *)screen->pixels;
+			dst1L = (UINT32 *)newscreen->pixels;
 
 			for (y = 0; y < cur_Rheight; y++)
 			{
-				memcpy(dst1L, srcL, cur_width*screen->format->BitsPerPixel/8);
+				if (sSettings->GetScanlines() && (y & 1))
+					memset(dst1L, 0, cur_width*newscreen->format->BitsPerPixel/8);
+				else
+					memcpy(dst1L, srcL, cur_width*newscreen->format->BitsPerPixel/8);
 				if (vdouble)
 				{
 					if (!(y & 1))
@@ -282,13 +304,29 @@ void Linux_UnlockScreen(void*)
 				{
 					srcL += cur_width;
 				}
-				dst1L += screen->pitch/4;
+				dst1L += newscreen->pitch/4;
 			}
+
+			dst1L = (UINT32 *)screen->pixels;
+
+			if (sSettings->GetBGR()) {
+				altscreen = SDL_ConvertSurface(newscreen, &BGR32, 0);
+				memcpy(dst1L, altscreen->pixels, cur_Rheight*screen->pitch);
+			} else
+				memcpy(dst1L, newscreen->pixels, cur_Rheight*screen->pitch);
 		}
 		else printf("ERROR: Unknown pixel format %d bpp\n", screen->format->BitsPerPixel);
 
+		SDL_FreeSurface(altscreen);
+		if (SDL_MUSTLOCK(newscreen)) SDL_UnlockSurface(newscreen);
 		if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
 		SDL_Flip(screen);
+		} 
+
+		frame++;
+
+		if (frame > sSettings->GetFrameSkip())
+			frame = 0;
 	}
 
 }
@@ -421,14 +459,14 @@ static void nst_unload2(void)
 	machine.Unload();
 
 	// erase any cheats
-	sCheatMgr->Unload();
+	//sCheatMgr->Unload();
 }
 
 static void nst_unload(void)
 {
 	nst_unload2();
 
-	UIHelp_Unload();
+	//UIHelp_Unload();
 }
 
 // if we're in full screen, kills video temporarily
@@ -471,12 +509,12 @@ void NstStopPlaying()
 		int i;
 
 		// kill any movie
-		auxio_do_movie_stop();
+		//auxio_do_movie_stop();
 
 		// close video sanely
 		if (!nsf_mode)
 		{
-			SDL_FreeSurface(screen);
+			SDL_FreeSurface(newscreen);
 			opengl_cleanup();
 			if (intbuffer)
 			{
@@ -514,7 +552,7 @@ void NstStopPlaying()
 	}
 
 	// show main window
-	gtk_widget_show(mainwindow);
+	//gtk_widget_show(mainwindow);
 
 	playing = 0;
 }
@@ -577,6 +615,7 @@ static void QuickLoad(int isvst)
 // start playing
 void NstPlayGame(void)
 {
+	#if 0
 	// hide main window
 	gtk_widget_hide(mainwindow);
 
@@ -585,6 +624,7 @@ void NstPlayGame(void)
 	{
 		gtk_main_iteration();
 	}
+	#endif
 
 	// initialization
 	SetupVideo();
@@ -592,7 +632,7 @@ void NstPlayGame(void)
 	SetupInput();
 
 	// apply any cheats into the engine
-	sCheatMgr->Enable();
+	//sCheatMgr->Enable();
 
 	cNstVideo = new Video::Output;
 	cNstSound = new Sound::Output;
@@ -661,7 +701,7 @@ static void ToggleFullscreen()
 	}
 
 	SDL_ShowCursor(1);
-	SDL_FreeSurface(screen);
+	SDL_FreeSurface(newscreen);
 	opengl_cleanup();
 
 	if (intbuffer)
@@ -1016,9 +1056,11 @@ static void NST_CALLBACK DoFileIO(void *
 
 static void cleanup_after_io(void)
 {
+	#if 0
 	gtk_main_iteration_do(FALSE);
 	gtk_main_iteration_do(FALSE);
 	gtk_main_iteration_do(FALSE);
+	#endif
 	if (sSettings->GetFullscreen())
 	{
 		SetupVideo();
@@ -1030,6 +1072,7 @@ int main(int argc, char *argv[])
 	static SDL_Event event;
 	int i;
 	void* userData = (void*) 0xDEADC0DE;
+	static int soundSamples = 0;
 
 	// read the key/controller mapping
 	ctl_defs = parse_input_file();
@@ -1045,9 +1088,9 @@ int main(int argc, char *argv[])
 	auxio_init();
 
 	sSettings = new Settings;
-	sCheatMgr = new CheatMgr;
+	//sCheatMgr = new CheatMgr;
 
-	UIHelp_Init(argc, argv, sSettings, sCheatMgr);
+	//UIHelp_Init(argc, argv, sSettings, sCheatMgr);
 	
 	// setup video lock/unlock callbacks
 	Video::Output::lockCallback.Set( VideoLock, userData );
@@ -1069,6 +1112,8 @@ int main(int argc, char *argv[])
 		NstLoadGame(argv[1]);
 
 		if (loaded)
+			NstPlayGame();
+		#if 0
 		{
 			if (nsf_mode)
 			{
@@ -1079,6 +1124,7 @@ int main(int argc, char *argv[])
 				on_playbutton_clicked(NULL, NULL);
 			}
 		}
+		#endif
 	}
 
 	nst_quit = 0;
@@ -1088,7 +1134,7 @@ int main(int argc, char *argv[])
 		{
 			if (nsf_mode)
 			{
-				gtk_main_iteration_do(FALSE);
+				//gtk_main_iteration_do(FALSE);
 			}
 			else
 			{
@@ -1120,7 +1166,15 @@ int main(int argc, char *argv[])
 				}
 			}
 
-			m1sdr_TimeCheck();
+			if (sSettings->GetSoundSkip() == 
+			    soundSamples)
+				m1sdr_TimeCheck();
+			else
+				m1sdr_Update();
+			soundSamples++;
+			if (soundSamples > sSettings->GetSoundSkip())
+				soundSamples = 0;
+
 			if (updateok)
 			{
 				emulator.Execute(cNstVideo, cNstSound, cNstPads);
@@ -1130,7 +1184,7 @@ int main(int argc, char *argv[])
 			if (state_save)
 			{
 				kill_video_if_fs();
-				auxio_do_state_save();
+				//auxio_do_state_save();
 				state_save = 0;
 				cleanup_after_io();
 			}
@@ -1138,7 +1192,7 @@ int main(int argc, char *argv[])
 			if (state_load)
 			{
 				kill_video_if_fs();
-				auxio_do_state_load();
+				//auxio_do_state_load();
 				state_load = 0;
 				cleanup_after_io();
 			}
@@ -1146,7 +1200,7 @@ int main(int argc, char *argv[])
 			if (movie_load)
 			{
 				kill_video_if_fs();
-				auxio_do_movie_load();
+				//auxio_do_movie_load();
 				movie_load = 0;
 				cleanup_after_io();
 			}
@@ -1154,7 +1208,7 @@ int main(int argc, char *argv[])
 			if (movie_save)
 			{
 				kill_video_if_fs();
-				auxio_do_movie_save();
+				//auxio_do_movie_save();
 				movie_load = 0;
 				cleanup_after_io();
 			}
@@ -1162,17 +1216,18 @@ int main(int argc, char *argv[])
 			if (movie_stop)
 			{
 				movie_stop = 0;
-				auxio_do_movie_stop();
+				//auxio_do_movie_stop();
 			}
 
 			if (schedule_stop)
 			{
 				NstStopPlaying();
+				nst_quit = 1;
 			}
 		}
 		else
 		{
-			gtk_main_iteration_do(FALSE);
+			//gtk_main_iteration_do(FALSE);
 		}
 	}
 
@@ -1181,7 +1236,7 @@ int main(int argc, char *argv[])
 	auxio_shutdown();
 
 	delete sSettings;
-	delete sCheatMgr;
+	//delete sCheatMgr;
 
 	write_output_file(ctl_defs);
 	free(ctl_defs);
@@ -1351,7 +1406,7 @@ void SetupVideo()
 
 
 
-	int eFlags = SDL_HWSURFACE;
+	int eFlags = (sSettings->GetHWSurface() ? SDL_HWSURFACE: SDL_SWSURFACE);
         using_opengl = (sSettings->GetRenderType() > 0);
 	linear_filter = (sSettings->GetRenderType() == 2);
 	if (using_opengl)
@@ -1375,6 +1430,10 @@ void SetupVideo()
 		exit(-1);
 	}
 
+if (screen->format->BitsPerPixel == 16)
+	newscreen = SDL_ConvertSurface(screen, &RGB16, 0);
+else
+	newscreen = SDL_ConvertSurface(screen, &RGB32, 0);
 	renderState.filter = filter;
 	renderState.width = cur_width;
 	renderState.height = cur_height;
@@ -1457,6 +1516,7 @@ void SetupSound()
 
 	m1sdr_Init(sSettings->GetRate());
 	m1sdr_SetCallback((void *)nst_do_frame);
+	m1sdr_SetNoWait(sSettings->GetSoundNoWait());
 	m1sdr_PlayStart();
 
 	// init DSP module
@@ -1466,6 +1526,8 @@ void SetupSound()
 	sound.SetSampleBits( 16 );
 	sound.SetSampleRate(sSettings->GetRate());
 	sound.SetVolume(Sound::ALL_CHANNELS, sSettings->GetVolume());
+	sound.SetAutoTranspose(true);
+	sound.SetSpeed(sSettings->GetSpeed());
 	if (sSettings->GetStereo())
 	{
 		sound.SetSpeaker( Sound::SPEAKER_STEREO );
@@ -1627,7 +1689,7 @@ void NstLoadGame(const char* filename)
 			if (!f)
 			{
 				loaded = 0;
-				UIHelp_Unload();
+				//UIHelp_Unload();
 				return;
 			}
 
@@ -1710,7 +1772,7 @@ void NstLoadGame(const char* filename)
 	if (nsf_mode)
 	{
 		// update the UI
-		UIHelp_NSFLoaded();
+	//	UIHelp_NSFLoaded();
 
 		// initialization
 		SetupVideo();
@@ -1734,7 +1796,7 @@ void NstLoadGame(const char* filename)
 	}
 	else
 	{
-		UIHelp_GameLoaded();
+		//UIHelp_GameLoaded();
 
 		if (machine.Is(Machine::DISK))
 		{
