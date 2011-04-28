$NetBSD: patch-media_audio_openbsd_audio__manager__openbsd.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- media/audio/openbsd/audio_manager_openbsd.h.orig	2011-04-13 08:01:06.000000000 +0000
+++ media/audio/openbsd/audio_manager_openbsd.h
@@ -5,7 +5,15 @@
 #ifndef MEDIA_AUDIO_OPENBSD_AUDIO_MANAGER_OPENBSD_H_
 #define MEDIA_AUDIO_OPENBSD_AUDIO_MANAGER_OPENBSD_H_
 
-#include "media/audio/audio_io.h"
+#include <map>
+
+#include "base/ref_counted.h"
+#include "base/scoped_ptr.h"
+#include "base/synchronization/lock.h"
+#include "base/threading/thread.h"
+#include "media/audio/audio_manager_base.h"
+
+class AlsaPcmOutputStream;
 
 class AudioManagerOpenBSD : public AudioManagerBase {
  public:
@@ -19,9 +27,12 @@ class AudioManagerOpenBSD : public Audio
   virtual bool HasAudioInputDevices();
   virtual AudioOutputStream* MakeAudioOutputStream(AudioParameters params);
   virtual AudioInputStream* MakeAudioInputStream(AudioParameters params);
+
   virtual void MuteAll();
   virtual void UnMuteAll();
 
+  virtual void ReleaseOutputStream(AlsaPcmOutputStream* stream);
+
  protected:
   virtual ~AudioManagerOpenBSD();
 
