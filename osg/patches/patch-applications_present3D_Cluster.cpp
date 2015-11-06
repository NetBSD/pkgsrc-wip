$NetBSD: patch-applications_present3D_Cluster.cpp,v 1.2 2012/05/20 19:28:19 marino Exp $

Support more platforms.

--- applications/present3D/Cluster.cpp.orig	2015-04-13 10:43:56.000000000 +0000
+++ applications/present3D/Cluster.cpp
@@ -33,7 +33,7 @@
 #if defined(__linux)
     #include <unistd.h>
     #include <linux/sockios.h>
-#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     #include <unistd.h>
     #include <sys/sockio.h>
 #elif defined(__sgi)
@@ -338,7 +338,7 @@ void Receiver::sync( void )
     }
 
 #if defined(__linux) || defined(__FreeBSD__) || defined( __APPLE__ ) || \
-    defined(__DragonFly__)
+    defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     socklen_t
 #else
     int
