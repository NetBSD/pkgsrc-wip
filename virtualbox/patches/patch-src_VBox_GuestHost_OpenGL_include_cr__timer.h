$NetBSD$

--- src/VBox/GuestHost/OpenGL/include/cr_timer.h.orig	2016-03-04 19:29:19.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/include/cr_timer.h
@@ -35,7 +35,7 @@ typedef struct Timer 
 #elif defined(WINDOWS)
 	LARGE_INTEGER performance_counter, performance_frequency;
 	double one_over_frequency;
-#elif defined( Linux ) || defined( FreeBSD ) || defined(DARWIN) || defined(AIX) || defined (SunOS) || defined(OSF1)
+#elif defined( Linux ) || defined( FreeBSD ) || defined(DARWIN) || defined(AIX) || defined (SunOS) || defined(OSF1) || defined(__NetBSD__)
 	struct timeval timeofday;
 #endif
 } CRTimer;
