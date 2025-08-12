$NetBSD$

--- modules/javafx.graphics/src/main/native-prism-es2/PrismES2Defs.h.orig	2024-08-20 17:07:03.000000000 +0000
+++ modules/javafx.graphics/src/main/native-prism-es2/PrismES2Defs.h
@@ -26,7 +26,7 @@
 #ifndef _Prism_es2_defs_h_
 #define _Prism_es2_defs_h_
 
-#if defined(SOLARIS) || defined(LINUX) || defined(ANDROID_NDK) /* SOLARIS || LINUX */
+#if defined(SOLARIS) || defined(LINUX) || defined(ANDROID_NDK) || defined(NETBSD) /* SOLARIS || LINUX */
 #define GLX_GLEXT_PROTOTYPES
 #define GLX_GLXEXT_PROTOTYPES
 #define UNIX
