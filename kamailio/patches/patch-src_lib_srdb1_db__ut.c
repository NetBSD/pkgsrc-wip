$NetBSD$

Work around namespace visibility issues with a big hammer, leaving
actually understanding and fixing properly for later.

Not yet reported upstream.

--- src/lib/srdb1/db_ut.c.orig	2019-11-14 11:38:09.000000000 +0000
+++ src/lib/srdb1/db_ut.c
@@ -33,29 +33,8 @@
 #include "../../core/pvar.h"
 #endif
 
-/**
- * make strptime available
- * use 600 for 'Single UNIX Specification, Version 3'
- * _XOPEN_SOURCE creates conflict in swab definition in Solaris
- */
-#ifndef __OS_solaris
-	#define _XOPEN_SOURCE 600          /* glibc2 on linux, bsd */
-	#define _BSD_SOURCE 1              /* needed on linux to "fix" the effect
-										* of the above define on
-										* features.h/unistd.h syscall() */
-	#define _DEFAULT_SOURCE 1         /* _BSD_SOURCE is deprecated */
-#else
-	#define _XOPEN_SOURCE_EXTENDED 1   /* solaris */
-#endif
-
-#include <time.h>
-
-#ifndef __OS_solaris
-	#undef _XOPEN_SOURCE
-	#undef _XOPEN_SOURCE_EXTENDED
-#else  /* solaris */
-	#undef _XOPEN_SOURCE_EXTENDED
-#endif
+#define _NETBSD_SOURCE
+#include <sys/types.h>
 
 #include <limits.h>
 #include <errno.h>
