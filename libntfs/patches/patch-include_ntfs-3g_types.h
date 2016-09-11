$NetBSD$

Fix TRUE and FALSE definitons.

--- include/ntfs-3g/types.h.orig	2016-09-11 14:41:15.893287643 +0000
+++ include/ntfs-3g/types.h	2016-09-11 14:44:17.222693852 +0000
@@ -76,6 +76,17 @@
 typedef s64 LCN;
 typedef sle64 leLCN;
 
+/* XXX For some reason, including sys/mount.h on osx defines TRUE and FALSE
+ * so clear them here.
+ */
+ 
+ #ifdef FALSE
+ #undef FALSE
+ #endif
+ #ifdef TRUE
+ #undef TRUE
+ #endif     
+
 /*
  * The NTFS journal $LogFile uses log sequence numbers which are signed 64-bit
  * values.  We define our own type LSN, to allow for type checking and better
