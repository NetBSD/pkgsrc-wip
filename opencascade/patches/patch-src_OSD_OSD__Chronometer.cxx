$NetBSD$

--- src/OSD/OSD_Chronometer.cxx.orig	2016-04-04 14:58:12.000000000 +0000
+++ src/OSD/OSD_Chronometer.cxx
@@ -57,7 +57,7 @@
 //=======================================================================
 void OSD_Chronometer::GetProcessCPU (Standard_Real& UserSeconds, Standard_Real& SystemSeconds)
 {
-#if defined(__linux__) || defined(linux) || defined(__FreeBSD__) || defined(__ANDROID__) || defined(__QNX__)
+#if defined(__linux__) || defined(linux) || defined(__FreeBSD__) || defined(__ANDROID__) || defined(__QNX__) || defined(__NetBSD__)
   static const long aCLK_TCK = sysconf(_SC_CLK_TCK);
 #else
   static const long aCLK_TCK = CLK_TCK;
