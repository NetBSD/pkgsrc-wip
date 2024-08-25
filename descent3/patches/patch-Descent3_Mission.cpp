$NetBSD$

Support *BSD.

--- Descent3/Mission.cpp.orig	2024-08-24 19:30:47.752421171 +0000
+++ Descent3/Mission.cpp
@@ -1691,7 +1691,7 @@ void InitLevelScript() {
     strcat(filename, ".dll");
 #elif defined(MACOSX)
     strcat(filename, ".dylib");
-#elif defined(__LINUX__)
+#elif defined(__LINUX__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     strcat(filename, ".so");
 #else
     #error Unsupported platform!
