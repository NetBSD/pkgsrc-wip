$NetBSD: patch-cpdup.h,v 1.1 2013/01/03 21:21:36 mrampke Exp $

Linux compatibility defines and libbsd includes

--- cpdup.h.orig	2010-07-19 19:01:56.000000000 +0000
+++ cpdup.h
@@ -25,8 +25,13 @@
 #include <fnmatch.h>
 #include <assert.h>
 #ifndef NOMD5
+#ifdef LIBBSD
+#include <bsd/sys/cdefs.h>
+#include <bsd/md5.h>
+#else
 #include <md5.h>
 #endif
+#endif
 
 /* Solaris needs <strings.h> for bzero(), bcopy() and bcmp(). */
 #include <strings.h>
@@ -35,6 +40,13 @@
 #include "compat_sun.h"
 #endif
 
+/* as per PORTING in cpdup-1.17 */
+#ifdef __linux__
+#define __unused
+#define _GNU_SOURCE
+#define __USE_FILE_OFFSET64
+#endif
+
 void logstd(const char *ctl, ...);
 void logerr(const char *ctl, ...);
 char *mprintf(const char *ctl, ...);
