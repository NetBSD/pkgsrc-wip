$NetBSD$

--- src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp
@@ -43,7 +43,7 @@
 using namespace std;
 
 #ifndef WIN32
-#if !(defined(__MACH__) && defined(__APPLE__))
+#if !(defined(__MACH__) && defined(__APPLE__)) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysinfo.h>
 #endif
 #endif
@@ -61,7 +61,7 @@ using namespace std;
 
 int SMDS_Mesh::CheckMemory(const bool doNotRaise) throw (std::bad_alloc)
 {
-#if (defined(__MACH__) && defined(__APPLE__))
+#if (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__) || defined(__NetBSD__)
 	return 1000;
 #else	
 #ifndef WIN32
