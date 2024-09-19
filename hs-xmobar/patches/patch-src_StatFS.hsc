$NetBSD: patch-src_StatFS.hsc,v 1.1 2013/01/19 13:15:39 szptvlfn Exp $

Of course it runs NetBSD

--- src/StatFS.hsc.orig	2012-12-02 23:47:56.000000000 +0000
+++ src/StatFS.hsc
@@ -30,6 +30,9 @@ import Data.ByteString.Char8 (pack)
 #ifdef IS_BSD_SYSTEM
 # include <sys/param.h>
 # include <sys/mount.h>
+#elif defined (__NetBSD__)
+# define statfs statvfs
+# include <sys/statvfs.h>
 #else
 # include <sys/vfs.h>
 #endif
