$NetBSD$

NetBSD provides gmtime_r().

--- filetype/file/src/gmtime_r.c.orig	2025-07-27 08:17:07.378630293 +0000
+++ filetype/file/src/gmtime_r.c
@@ -1,5 +1,6 @@
 /*	$File: gmtime_r.c,v 1.4 2022/09/24 20:30:13 christos Exp $	*/
 
+#ifndef __NetBSD__
 #include "file.h"
 #ifndef	lint
 FILE_RCSID("@(#)$File: gmtime_r.c,v 1.4 2022/09/24 20:30:13 christos Exp $")
@@ -17,3 +18,4 @@ gmtime_r(const time_t *t, struct tm *tm)
 	memcpy(tm, tmp, sizeof(*tm));
 	return tmp;
 }
+#endif
