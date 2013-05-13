$NetBSD: patch-Source_Core_Common_Src_MemArena.cpp,v 1.1 2013/05/13 00:23:02 othyro Exp $

Add FreeBSD and NetBSD support.

--- Source/Core/Common/Src/MemArena.cpp.orig	2012-12-24 20:29:24.000000000 +0000
+++ Source/Core/Common/Src/MemArena.cpp
@@ -29,7 +29,7 @@
 #include <cstring>
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined (__FreeBSD__) || defined (__NetBSD__)
 static const char* ram_temp_file = "/tmp/gc_mem.tmp";
 #elif !defined(_WIN32) // non OSX unixes
 static const char* ram_temp_file = "/dev/shm/gc_mem.tmp";
