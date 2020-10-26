$NetBSD$

--- driver/video/opengl/bind.h.orig	2020-10-25 12:34:43.000000000 +0000
+++ driver/video/opengl/bind.h
@@ -1,4 +1,4 @@
-#if defined(_WIN32) || defined(__linux__)
+#if defined(_WIN32) || defined(__linux__) || defined(__NetBSD__)
 	PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
 	PFNGLDELETEPROGRAMPROC glDeleteProgram = nullptr;
 	PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
@@ -58,7 +58,7 @@ static bool OpenGLBind() {
 		function = (prototype)glGetProcAddress(#function); \
 		if(function == nullptr) return false
 
-	#if defined(_WIN32) || defined(__linux__)
+	#if defined(_WIN32) || defined(__linux__) || defined(__NetBSD__)
 		bind(PFNGLCREATEPROGRAMPROC, glCreateProgram);
 		bind(PFNGLDELETEPROGRAMPROC, glDeleteProgram);
 		bind(PFNGLUSEPROGRAMPROC, glUseProgram);
