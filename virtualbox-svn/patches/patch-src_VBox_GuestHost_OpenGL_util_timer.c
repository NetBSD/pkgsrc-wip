$NetBSD$

--- src/VBox/GuestHost/OpenGL/util/timer.c.orig	2016-03-04 19:29:23.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/util/timer.c
@@ -35,7 +35,7 @@ static double crTimerGetTime( CRTimer *t
 #elif defined( WINDOWS )
 	QueryPerformanceCounter( &t->performance_counter );
 	return ((double) t->performance_counter.QuadPart)*t->one_over_frequency;
-#elif defined( Linux ) || defined( FreeBSD ) || defined(DARWIN) || defined(AIX) || defined(SunOS) || defined(OSF1)
+#elif defined( Linux ) || defined( FreeBSD ) || defined(DARWIN) || defined(AIX) || defined(SunOS) || defined(OSF1) || defined(__NetBSD__)
 	gettimeofday( &t->timeofday, NULL );	
 	return t->timeofday.tv_sec + t->timeofday.tv_usec / 1000000.0;
 #else
