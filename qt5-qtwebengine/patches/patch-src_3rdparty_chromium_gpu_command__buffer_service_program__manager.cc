$NetBSD$

--- src/3rdparty/chromium/gpu/command_buffer/service/program_manager.cc.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/program_manager.cc
@@ -30,7 +30,7 @@
 #include "gpu/command_buffer/service/program_cache.h"
 #include "gpu/command_buffer/service/shader_manager.h"
 #include "gpu/config/gpu_preferences.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/progress_reporter.h"
 
