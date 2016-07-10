$NetBSD$

--- src/VBox/GuestHost/OpenGL/spu_loader/glloader.py.orig	2016-03-04 19:29:21.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/spu_loader/glloader.py
@@ -34,10 +34,12 @@ print """
 #  define SYSTEM_AGL "AGL"
 # endif
 #include <string.h> /* VBOX */
-#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1)
+#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSDOB) || defined(AIX) || defined(SunOS) || defined(OSF1) || defined(__NetBSD__)
 #include <string.h>
 #if defined(AIX)
 #define SYSTEM_GL "libGL.o"
+#elif defined(__NetBSD__)
+#define SYSTEM_GL "libGL.so.2"
 #else
 #define SYSTEM_GL "libGL.so.1"
 #endif
@@ -150,7 +152,7 @@ __findSystemLib( const char *provided_sy
 		}*/
 #endif
 	}
-#if !defined(__linux__) && !defined(SunOS) && !defined(__FreeBSD__)
+#if !defined(__linux__) && !defined(SunOS) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 	crStrcat( system_path, "/" );
 #endif
 #if !defined(CR_NO_GL_SYSTEM_PATH)
@@ -601,4 +603,3 @@ int crLoadOSMesa( OSMesaContext (**creat
 #endif
 
 """
-
