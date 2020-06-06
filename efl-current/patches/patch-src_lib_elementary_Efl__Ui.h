$NetBSD$

* NetBSD support

--- src/lib/elementary/Efl_Ui.h.orig	2020-05-11 11:32:41.000000000 +0000
+++ src/lib/elementary/Efl_Ui.h
@@ -51,7 +51,7 @@
 # define WIN32_LEAN_AND_MEAN
 # include <winsock2.h>
 # undef WIN32_LEAN_AND_MEAN
-#elif defined (__FreeBSD__) || defined (__OpenBSD__)
+#elif defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
 # include <sys/select.h>
 # include <signal.h>
 #elif defined (__ANDROID__)
