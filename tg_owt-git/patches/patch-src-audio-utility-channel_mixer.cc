$NetBSD$

Add missing <cstring> include for std::memcmp.

--- src/audio/utility/channel_mixer.cc	2026-07-30 11:53:07.371819043 +0300
+++ src/audio/utility/channel_mixer.cc	2026-07-30 11:53:07.390153437 +0300
@@ -10,6 +10,7 @@
 
 #include "audio/utility/channel_mixer.h"
 
+#include <cstring>
 #include "audio/utility/channel_mixing_matrix.h"
 #include "rtc_base/checks.h"
 #include "rtc_base/logging.h"
