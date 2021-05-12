$NetBSD$

* don't use kqueue on older NetBSD which misses EVFILT_USER

$NetBSD$

--- vio/viosocket.cc.orig	2021-03-22 08:44:50.000000000 +0000
+++ vio/viosocket.cc
@@ -70,6 +70,10 @@
 
 #include "mysql/psi/mysql_socket.h"
 
+#if defined(HAVE_QUEUE) && !defined(EVFILT_USER)
+#undef HAVE_KQUEUE
+#endif
+
 int vio_errno(Vio *vio MY_ATTRIBUTE((unused))) {
 /* These transport types are not Winsock based. */
 #ifdef _WIN32
