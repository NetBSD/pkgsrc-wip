$NetBSD: patch-content_media_AudioStream.h,v 1.1 2014/09/29 10:46:24 thomasklausner Exp $

--- content/media/AudioStream.h.orig	2014-09-28 08:30:00.000000000 +0000
+++ content/media/AudioStream.h
@@ -15,10 +15,7 @@
 #include "mozilla/RefPtr.h"
 #include "mozilla/UniquePtr.h"
 #include "CubebUtils.h"
-
-namespace soundtouch {
-class SoundTouch;
-}
+#include "soundtouch/SoundTouch.h"
 
 namespace mozilla {
 
