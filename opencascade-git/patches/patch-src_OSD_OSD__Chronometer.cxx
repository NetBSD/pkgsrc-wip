$NetBSD$

Add NetBSD support.

--- src/OSD/OSD_Chronometer.cxx.orig	2021-10-30 11:13:54.000000000 +0000
+++ src/OSD/OSD_Chronometer.cxx
@@ -51,7 +51,7 @@
 void OSD_Chronometer::GetProcessCPU (Standard_Real& theUserSeconds,
                                      Standard_Real& theSystemSeconds)
 {
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__ANDROID__) || defined(__QNX__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__ANDROID__) || defined(__QNX__) || defined(__EMSCRIPTEN__)
   static const long aCLK_TCK = sysconf(_SC_CLK_TCK);
 #else
   static const long aCLK_TCK = CLK_TCK;
