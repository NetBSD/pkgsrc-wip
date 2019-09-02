$NetBSD$

--- gdb/gdbsupport/common-defs.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/gdbsupport/common-defs.h
@@ -96,9 +96,9 @@
 #include <strings.h>	/* for strcasecmp and strncasecmp */
 #endif
 #include <errno.h>
-#include <alloca.h>
 
 #include "ansidecl.h"
+#ifndef __NetBSD__
 /* This is defined by ansidecl.h, but we prefer gnulib's version.  On
    MinGW, gnulib might enable __USE_MINGW_ANSI_STDIO, which may or not
    require use of attribute gnu_printf instead of printf.  gnulib
@@ -106,6 +106,7 @@
    is compatible with ATTRIBUTE_PRINTF, simply use it.  */
 #undef ATTRIBUTE_PRINTF
 #define ATTRIBUTE_PRINTF _GL_ATTRIBUTE_FORMAT_PRINTF
+#endif
 
 #if GCC_VERSION >= 3004
 #define ATTRIBUTE_UNUSED_RESULT __attribute__ ((__warn_unused_result__))
