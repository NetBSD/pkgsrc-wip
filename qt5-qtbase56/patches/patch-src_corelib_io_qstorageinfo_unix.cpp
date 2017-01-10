$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.6 2016/12/04 21:46:54 marino Exp $

* fix build on SunOS

--- src/corelib/io/qstorageinfo_unix.cpp.orig	2016-12-01 08:17:04.000000000 +0000
+++ src/corelib/io/qstorageinfo_unix.cpp
@@ -94,7 +94,7 @@
 #  if !defined(ST_RDONLY)
 #    define ST_RDONLY 1 // hack for missing define on Android
 #  endif
-#elif defined(Q_OS_HAIKU)
+#elif defined(Q_OS_HAIKU) || defined(Q_OS_SOLARIS)
 #  define QT_STATFSBUF struct statvfs
 #  define QT_STATFS    ::statvfs
 #else
