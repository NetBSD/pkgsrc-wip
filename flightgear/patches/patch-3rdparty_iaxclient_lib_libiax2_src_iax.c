$NetBSD$

--- 3rdparty/iaxclient/lib/libiax2/src/iax.c.orig	2015-02-15 20:01:07.000000000 +0000
+++ 3rdparty/iaxclient/lib/libiax2/src/iax.c
@@ -75,7 +75,7 @@
 // FlightGear: Modified to include FreeBSD
 #if !defined(MACOSX) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <malloc.h>
-#if !defined(SOLARIS)
+#if !defined(SOLARIS) && !defined(__NetBSD__)
 #include <error.h>
 #endif
 #endif
