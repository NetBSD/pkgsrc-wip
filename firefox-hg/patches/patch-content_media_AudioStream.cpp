$NetBSD: patch-content_media_AudioStream.cpp,v 1.1 2014/09/29 10:46:24 thomasklausner Exp $

--- content/media/AudioStream.cpp.orig	2014-09-28 08:30:00.000000000 +0000
+++ content/media/AudioStream.cpp
@@ -14,7 +14,6 @@
 #include "mozilla/Mutex.h"
 #include <algorithm>
 #include "mozilla/Telemetry.h"
-#include "soundtouch/SoundTouch.h"
 #include "Latency.h"
 #include "CubebUtils.h"
 #include "nsPrintfCString.h"
