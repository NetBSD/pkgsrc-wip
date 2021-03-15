$NetBSD$

--- src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/libEGL.hpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/OpenGL/libEGL/libEGL.hpp
@@ -100,7 +100,7 @@ private:
 				#endif
 			#elif defined(__ANDROID__)
 				const char *libEGL_lib[] = {"libEGL_swiftshader.so", "libEGL_swiftshader.so"};
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__))
 				#if defined(__LP64__)
 					const char *libEGL_lib[] = {"lib64EGL_translator.so", "libEGL.so.1", "libEGL.so"};
 				#else
