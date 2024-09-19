$NetBSD$

--- src/3rdParty/salomesmesh/src/SMDS/SMDS_MemoryLimit.cpp.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_MemoryLimit.cpp
@@ -28,7 +28,7 @@
 // to the system. (PAL16631)
 //
 #ifndef WIN32
-#if !(defined(__MACH__) && defined(__APPLE__))
+#if !(defined(__MACH__) && defined(__APPLE__)) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysinfo.h>
 #endif
 #endif
@@ -39,7 +39,7 @@
 
 int main (int argc, char ** argv)
 {
-#if (defined(__MACH__) && defined(__APPLE__))
+#if (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__) || defined(__NetBSD__)
 	//do nothing
 #else
   // To better understand what is going on here, consult bug [SALOME platform 0019911]
