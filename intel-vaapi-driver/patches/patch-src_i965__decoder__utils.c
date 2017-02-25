$NetBSD$

Honor AC_FUNC_ALLOCA and include the proper header files to use alloca(3).

--- src/i965_decoder_utils.c.orig	2016-11-10 05:04:36.000000000 +0000
+++ src/i965_decoder_utils.c
@@ -23,7 +23,17 @@
 
 #include "sysdeps.h"
 #include <limits.h>
-#include <alloca.h>
+#ifdef STDC_HEADERS
+# include <stdlib.h>
+# include <stddef.h>
+#else
+# ifdef HAVE_STDLIB_H
+#  include <stdlib.h>
+# endif
+#endif
+#ifdef HAVE_ALLOCA_H
+# include <alloca.h>
+#endif
 
 #include "intel_batchbuffer.h"
 #include "intel_media.h"
