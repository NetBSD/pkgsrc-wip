$NetBSD$

NetBSD uses statvfs for the functionality of statfs on Linux.

--- libs/pbd/mountpoint.cc.orig	2016-02-19 01:28:56.000000000 +0000
+++ libs/pbd/mountpoint.cc
@@ -116,7 +116,11 @@ mountpoint (string path)
 string
 mountpoint (string path)
 {
+#if defined(__NetBSD__)
+	struct statvfs *mntbufp = 0;
+#else
 	struct statfs *mntbufp = 0;
+#endif
 	int count;
 	unsigned int maxmatch = 0;
 	unsigned int matchlen;
