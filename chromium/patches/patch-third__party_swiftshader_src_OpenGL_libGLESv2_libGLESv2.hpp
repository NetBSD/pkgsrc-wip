$NetBSD$

--- third_party/swiftshader/src/OpenGL/libGLESv2/libGLESv2.hpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ third_party/swiftshader/src/OpenGL/libGLESv2/libGLESv2.hpp
@@ -286,7 +286,7 @@ private:
 				#endif
 			#elif defined(__ANDROID__)
 				const char *libGLESv2_lib[] = {"libGLESv2_swiftshader.so", "libGLESv2_swiftshader.so"};
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__))
 				#if defined(__LP64__)
 					const char *libGLESv2_lib[] = {"lib64GLES_V2_translator.so", "libGLESv2.so.2", "libGLESv2.so"};
 				#else
