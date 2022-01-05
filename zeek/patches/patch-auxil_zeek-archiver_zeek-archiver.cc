$NetBSD$

Fix build on NetBSD, ::snprintf is not visible when _XOPEN_SOURCE is set

--- auxil/zeek-archiver/zeek-archiver.cc.orig	2021-03-01 20:17:26.000000000 +0000
+++ auxil/zeek-archiver/zeek-archiver.cc
@@ -1,4 +1,6 @@
+#ifndef __NetBSD__
 #define _XOPEN_SOURCE
+#endif
 #include <time.h>
 
 #include <sys/time.h>
