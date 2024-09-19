$NetBSD: patch-source_linux_settings.h,v 1.1 2014/11/02 08:36:13 nsloss Exp $

Add methods for accessing additional flags/variables.
--- source/linux/settings.h.orig	2008-06-25 02:46:24.000000000 +0000
+++ source/linux/settings.h
@@ -8,7 +8,7 @@ namespace LinuxNst
 		public:
 			Settings();
 			~Settings();
-
+			void writeSettings();
 			// video accessors
 			int GetFullscreen(void) { return fullscreen; }
 			int GetScale(void) { return scaler; }
@@ -17,6 +17,11 @@ namespace LinuxNst
 			int GetNtscMode(void) { return ntscmode; }
 			int GetRenderType(void) { return rendertype; }
 			int GetScaleAmt(void) { return scaleamt; }
+			int GetScanlines(void) { return scanlines; }
+			int GetFrameSkip(void) { return frameskip; }
+			int GetBGR(void) { return bgr; }
+			int GetSpeed(void) { return speed * 30; }
+			int GetHWSurface(void) { return hwblit; }
 			void SetFullscreen(int fs) { fullscreen = fs; }
 			void SetScale(int scl) { scaler = scl; }
 			void SetSprlimit(int limit) { sprlimit = limit; }
@@ -24,6 +29,11 @@ namespace LinuxNst
 			void SetNtscMode(int mode) { ntscmode = mode; }
 			void SetRenderType(int mode) { rendertype = mode; }
 			void SetScaleAmt(int mode) { scaleamt = mode; }
+			void SetScanlines(int mode) { scanlines = mode; }
+			void SetFrameskip(int mode) { frameskip = mode; }
+			void SetBGR(int mode) { bgr = mode; }
+			void SetSpeed(int mode) { speed = mode; }
+			void SetHWSurface(int mode) { hwblit = mode; }
 
 			// input accessors
 			int GetUseJoypads(void) { return controls; }
@@ -40,6 +50,8 @@ namespace LinuxNst
 			int GetUseExciter(void) { return exciter; }
 			int GetUseSurround(void) { return litesurr; }
 			int GetSurrMult(void) { return surmult; }
+			int GetSoundSkip(void) { return soundskip; }
+			int GetSoundNoWait(void) { return soundnowait; }
 			void SetStereo(int st) { stereo = st; }
 			void SetSndAPI(int api) { sndapi = api; }
 			void SetVolume(int vol) { volume = vol; }
@@ -47,6 +59,8 @@ namespace LinuxNst
 			void SetUseExciter(int val) { exciter = val; }
 			void SetUseSurround(int val) { litesurr = val; }
 			void SetSurrMult(int val) { surmult = val; }
+			void SetSoundSkip(int mode) { soundskip = mode; }
+			void SetSoundNoWait(int mode) { soundnowait = mode; }
 
 			// other accessors
 			int GetPrefSystem(void) { return prefsys; }
@@ -57,13 +71,14 @@ namespace LinuxNst
 		private:
 			// video settings
 			int fullscreen, scaler, sprlimit, videomode, ntscmode;
-			int rendertype, scaleamt;
+			int rendertype, scaleamt, scanlines, frameskip, bgr, hwblit;
 			// input settings
 			int controls, configitem;
 			// sound settings
 			int stereo, sndapi, volume, rate, exciter, litesurr, surmult;
+			int soundskip, soundnowait;
 			// other settings
-			int prefsys, spatch;
+			int prefsys, spatch, speed;
 };
 };
 
