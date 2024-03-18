$NetBSD$

Adapt for portaudio19.
From Debian.

--- gameSource/sound/SoundPlayer.h.orig	2006-10-02 22:29:43.000000000 +0000
+++ gameSource/sound/SoundPlayer.h
@@ -52,8 +52,7 @@
 #include "SoundFilter.h"
 #include "PlayableSound.h"
 
-#include "minorGems/sound/portaudio/pa_common/portaudio.h"
-#include "minorGems/sound/portaudio/pablio/pablio.h"
+#include <portaudio.h>
 
 
 #include "minorGems/util/SimpleVector.h"
@@ -240,7 +239,7 @@ class SoundPlayer {
         char mFadingIn;
         int mNumFadeFramesRemaining;
         
-        PortAudioStream *mAudioStream;
+        PaStream *mAudioStream;
 
         // realtime sounds that should be mixed into the next to-speaker call
         SimpleVector<PlayableSound *> *mRealtimeSounds;
