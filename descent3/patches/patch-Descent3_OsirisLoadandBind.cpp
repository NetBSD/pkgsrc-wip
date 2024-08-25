$NetBSD$

Support *BSD.

--- Descent3/OsirisLoadandBind.cpp.orig	2024-08-24 19:41:44.121690971 +0000
+++ Descent3/OsirisLoadandBind.cpp
@@ -3145,7 +3145,7 @@ int Osiris_ExtractScriptsFromHog(int lib
   const char *script_extension;
 #if defined(MACOSX)
   script_extension = "*.dylib";
-#elif defined(__LINUX__)
+#elif defined(__LINUX__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
   script_extension = "*.so";
 #elif defined(WIN32)
   script_extension = "*.dll";
