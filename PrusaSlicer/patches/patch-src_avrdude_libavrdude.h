$NetBSD$

alloca.h is Linux specific.

--- src/avrdude/libavrdude.h.orig	2020-03-21 10:55:51.000000000 +0000
+++ src/avrdude/libavrdude.h
@@ -950,7 +950,7 @@ int read_config_builtin();
 // Header file for alloca()
 #if defined(WIN32NATIVE)
 #  include <malloc.h>
-#else
+#elif defined(__linux__)
 #  include <alloca.h>
 #endif
 
