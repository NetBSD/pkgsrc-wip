$NetBSD: patch-src_corelib_global_qsystemdetection.h,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Add Interix support

--- src/qt/qtbase/src/corelib/global/qsystemdetection.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/corelib/global/qsystemdetection.h
@@ -68,6 +68,7 @@
      NETBSD   - NetBSD
      OPENBSD  - OpenBSD
      BSDI     - BSD/OS
+     INTERIX  - Interix
      IRIX     - SGI Irix
      OSF      - HP Tru64 UNIX
      SCO      - SCO OpenServer 5
@@ -151,6 +152,9 @@
 #elif defined(__bsdi__)
 #  define Q_OS_BSDI
 #  define Q_OS_BSD4
+#elif defined(__INTERIX)
+#  define Q_OS_INTERIX
+#  define Q_OS_BSD4
 #elif defined(__sgi)
 #  define Q_OS_IRIX
 #elif defined(__osf__)
