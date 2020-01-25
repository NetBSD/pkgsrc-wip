$NetBSD$

* don't use kqueue on netbsd since it misses EVFILT_USER

--- vio/viosocket.cc.orig	2019-12-09 19:53:17.000000000 +0000
+++ vio/viosocket.cc
@@ -68,6 +68,10 @@
 
 #include "mysql/psi/mysql_socket.h"
 
+#ifdef __NetBSD__
+#undef HAVE_KQUEUE
+#endif
+
 int vio_errno(Vio *vio MY_ATTRIBUTE((unused))) {
 /* These transport types are not Winsock based. */
 #ifdef _WIN32
