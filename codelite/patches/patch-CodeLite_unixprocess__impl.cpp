$NetBSD: patch-CodeLite_unixprocess__impl.cpp,v 1.1 2016/06/15 22:04:17 kamil Exp $

Add switch for NetBSD to not fall under "other OS".

--- CodeLite/unixprocess_impl.cpp.orig	2019-05-21 17:52:21.000000000 +0300
+++ CodeLite/unixprocess_impl.cpp
@@ -50,6 +50,10 @@
 #include <libutil.h>
 #include <sys/ioctl.h>
 #include <termios.h>
+#elif defined(__NetBSD__)
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <util.h>
 #else
 #include <pty.h>
 #include <utmp.h>
