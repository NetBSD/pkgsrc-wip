$NetBSD$
Already upstream
--- lib/angelscript/source/as_config.h.orig	2017-01-06 15:10:11.002193378 +0000
+++ lib/angelscript/source/as_config.h	2017-01-06 15:10:53.782420089 +0000
@@ -923,7 +923,7 @@
 		#endif
 
 	// Free BSD
-	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
 		#define AS_BSD
 		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
 			#undef COMPLEX_MASK
