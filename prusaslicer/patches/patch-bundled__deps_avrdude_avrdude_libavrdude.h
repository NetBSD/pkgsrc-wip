$NetBSD$

alloca.h is only found on Linux+Darwin.

--- bundled_deps/avrdude/avrdude/libavrdude.h.orig	2024-09-20 23:44:46.451970401 +0000
+++ bundled_deps/avrdude/avrdude/libavrdude.h
@@ -950,7 +950,7 @@ int read_config_builtin();
 // Header file for alloca()
 #if defined(WIN32NATIVE)
 #  include <malloc.h>
-#else
+#elif defined(__linux__) || defined(__APPLE__)
 #  include <alloca.h>
 #endif
 
