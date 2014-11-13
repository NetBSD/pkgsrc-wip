$NetBSD: patch-source_linux_oss.cpp,v 1.2 2014/11/13 22:45:39 nsloss Exp $

Remove dependancy on alsa.
Set oss_nw flag for better performance.
Remove usleep for better performance on RPI
--- source/linux/oss.cpp.orig	2008-06-25 14:33:29.000000000 +0000
+++ source/linux/oss.cpp
@@ -12,9 +12,11 @@
 #include <sys/soundcard.h>
 #include <SDL.h>
 
+#ifndef __NetBSD__
 #define ALSA_PCM_NEW_HW_PARAMS_API
 #define ALSA_PCM_NEW_SW_PARAMS_API
 #include <alsa/asoundlib.h>
+#endif
 
 #include "oss.h"
 
@@ -36,7 +38,9 @@ int nDSoundSegLen = 0;
 static int oss_nw = 0, oss_playing = 0;
 
 int audiofd;
+#ifndef __NetBSD__
 static snd_pcm_t *pHandle = NULL;
+#endif
 int lnxdrv_apimode = 0;		// 0 = SDL, 1 = ALSA, 2 = OSS
 
 static INT16 samples[(48000*2)/10];
@@ -185,7 +189,10 @@ void m1sdr_Update(void)
 void m1sdr_TimeCheck(void)
 {
 	int timeout;
+	static int samplesPlayed = 0;
+#ifndef __NetBSD__
 	snd_pcm_sframes_t delay = 0;
+#endif
 
 #if VALGRIND
 	m1sdr_Update();
@@ -203,6 +210,7 @@ void m1sdr_TimeCheck(void)
 		SDL_UnlockAudio();
 		break;  
 
+#ifndef __NetBSD__
 	case 1:	// ALSA
 		if ((!pHandle) || (!oss_playing))
 		{
@@ -236,6 +244,9 @@ void m1sdr_TimeCheck(void)
 		break;	
 
 	case 2:	// OSS
+#else
+	case 1: // OSS
+#endif
 		audio_buf_info info;
 
 		if ((audiofd == -1) || (!oss_playing))
@@ -274,7 +285,7 @@ void m1sdr_TimeCheck(void)
 		break;
 	}
 
-	usleep(50);
+	//usleep(50);
 #endif
 }
 
@@ -284,7 +295,9 @@ INT16 m1sdr_Init(int sample_rate)
 {	
 	int format, stereo, rate, fsize, err;
 	unsigned int nfreq, periodtime;
+#ifndef __NetBSD__
 	snd_pcm_hw_params_t *hwparams;
+#endif
 
 	hw_present = 0;
 
@@ -319,6 +332,7 @@ INT16 m1sdr_Init(int sample_rate)
 		SDL_PauseAudio(1);
 		break;
 				
+#ifndef __NetBSD__
 	case 1:	// ALSA
 		// Try to open audio device
 		if ((err = snd_pcm_open(&pHandle, "plughw:0,0", SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
@@ -388,6 +402,9 @@ INT16 m1sdr_Init(int sample_rate)
 		break;	
 
 	case 2:	// OSS
+#else
+	case 1: // OSS
+#endif
 		audiofd = open("/dev/dsp", O_WRONLY, 0);
 		if (audiofd == -1)
 		{
@@ -465,11 +482,15 @@ void m1sdr_Exit(void)
 		}
 		break;	
 
+#ifndef __NetBSD__
 	case 1:	// ALSA
 		snd_pcm_close(pHandle);
 		break;	
 
 	case 2:	// OSS
+#else
+	case 1: // OSS
+#endif
 		close(audiofd);
 		break;	
 	}
@@ -489,6 +510,7 @@ INT16 m1sdr_IsThere(void)
 {
 	int err;
 
+#ifndef __NetBSD__
 	if (lnxdrv_apimode == 1)
 	{
 		if ((err = snd_pcm_open(&pHandle, "plughw:0,0", SND_PCM_STREAM_PLAYBACK, 0)) != 0)
@@ -502,6 +524,9 @@ INT16 m1sdr_IsThere(void)
 		hw_present = 1;
 	}
 	else if (lnxdrv_apimode == 2)
+#else
+	if (lnxdrv_apimode == 1)
+#endif
 	{
 		audiofd = open("/dev/dsp", O_WRONLY, 0);
 
