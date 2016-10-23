$NetBSD$

--- src/other/tcl/unix/tclUnixPort.h.orig	2016-08-09 06:47:12.000000000 +0000
+++ src/other/tcl/unix/tclUnixPort.h
@@ -112,11 +112,7 @@ typedef off_t		Tcl_SeekOffset;
 #if HAVE_STDINT_H
 #   include <stdint.h>
 #endif
-#ifdef HAVE_UNISTD_H
-#   include <unistd.h>
-#else
-#   include "../compat/unistd.h"
-#endif
+#include <unistd.h>
 
 MODULE_SCOPE int TclUnixSetBlockingMode(int fd, int mode);
 
