$NetBSD: patch-dom_media_AudioStream.cpp,v 1.1 2014/10/27 22:53:23 thomasklausner Exp $

--- dom/media/AudioStream.cpp.orig	2014-10-27 20:46:32.000000000 +0000
+++ dom/media/AudioStream.cpp
@@ -14,7 +14,6 @@
 #include "mozilla/Mutex.h"
 #include <algorithm>
 #include "mozilla/Telemetry.h"
-#include "soundtouch/SoundTouch.h"
 #include "Latency.h"
 #include "CubebUtils.h"
 #include "nsPrintfCString.h"
