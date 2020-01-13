$NetBSD$

* Solaris has FIONREAD in sys/filio.h

--- src/lib/util/watch_socket.cc.orig	2019-11-19 14:50:43.000000000 +0000
+++ src/lib/util/watch_socket.cc
@@ -18,6 +18,10 @@
 #include <sys/ioctl.h>
 #include <unistd.h>
 
+#ifdef HAVE_SYS_FILIO_H
+#include <sys/filio.h>
+#endif
+
 namespace isc {
 namespace util {
 
