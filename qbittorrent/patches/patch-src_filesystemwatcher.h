$NetBSD: patch-src_filesystemwatcher.h,v 1.1 2013/12/12 15:33:22 noud4 Exp $

Use statvfs on NetBSD.

--- src/filesystemwatcher.h.orig	2013-11-19 22:55:00.000000000 +0000
+++ src/filesystemwatcher.h
@@ -16,6 +16,9 @@
 #include <sys/param.h>
 #include <sys/mount.h>
 #include <string.h>
+#elif defined(Q_OS_NETBSD)
+#include <sys/param.h>
+#include <sys/statvfs.h>
 #else
 #include <sys/vfs.h>
 #endif
@@ -63,9 +66,17 @@ private:
     if (!file.endsWith(QDir::separator()))
       file += QDir::separator();
     file += ".";
+#if defined(Q_OS_NETBSD)
+    struct statvfs buf;
+#else
     struct statfs buf;
+#endif
+#if defined(Q_OS_NETBSD)
+    if (!statvfs(file.toLocal8Bit().constData(), &buf)) {
+#else
     if (!statfs(file.toLocal8Bit().constData(), &buf)) {
-#ifdef Q_WS_MAC
+#endif
+#if defined(Q_WS_MAC) || defined(Q_OS_NETBSD)
       // XXX: should we make sure HAVE_STRUCT_FSSTAT_F_FSTYPENAME is defined?
       return (strcmp(buf.f_fstypename, "nfs") == 0 || strcmp(buf.f_fstypename, "cifs") == 0 || strcmp(buf.f_fstypename, "smbfs") == 0);
 #else
