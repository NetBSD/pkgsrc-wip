$NetBSD$

--- src/VBox/GuestHost/OpenGL/include/cr_dll.h.orig	2016-03-04 19:29:19.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/include/cr_dll.h
@@ -22,7 +22,7 @@ typedef struct {
 	char *name;
 #if defined(WINDOWS)
 	HINSTANCE hinstLib;
-#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1)
+#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1) || defined(__NetBSD__)
 	void *hinstLib;
 #elif defined(DARWIN)
 	void *hinstLib;		/* void to avoid including the headers */
