$NetBSD$

alloca.h is only found on Linux+Darwin.

--- src/avrdude/libavrdude.h.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/avrdude/libavrdude.h
@@ -950,7 +950,7 @@ int read_config_builtin();
 // Header file for alloca()
 #if defined(WIN32NATIVE)
 #  include <malloc.h>
-#else
+#elif defined(__linux__) || defined(__APPLE__)
 #  include <alloca.h>
 #endif
 
