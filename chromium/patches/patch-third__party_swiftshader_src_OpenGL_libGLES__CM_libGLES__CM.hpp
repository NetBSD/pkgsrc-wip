$NetBSD$

--- third_party/swiftshader/src/OpenGL/libGLES_CM/libGLES_CM.hpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ third_party/swiftshader/src/OpenGL/libGLES_CM/libGLES_CM.hpp
@@ -261,7 +261,7 @@ private:
 				#endif
 			#elif defined(__ANDROID__)
 				const char *libGLES_CM_lib[] = {"libGLESv1_CM_swiftshader.so", "libGLESv1_CM_swiftshader.so"};
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__))
 				#if defined(__LP64__)
 					const char *libGLES_CM_lib[] = {"lib64GLES_CM_translator.so", "libGLES_CM.so.1", "libGLES_CM.so"};
 				#else
