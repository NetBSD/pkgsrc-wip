$NetBSD$
--- ./src/posix/OSPosix.cpp.orig	2016-01-19 02:28:31.000000000 -0800
+++ ./src/posix/OSPosix.cpp	2016-01-19 02:29:40.000000000 -0800
@@ -107,7 +107,7 @@
 	}
 
 	char infoString[2048];
-#if defined(__APPLE__)
+#if !defined(_GNU_SOURCE)
 	snprintf(infoString, 2048, "System Name: %s\nHost Name: %s\nRelease(Kernel) Version: %s\nKernel Build Timestamp: %s\nMachine Arch: %s\n",
 		uts.sysname, uts.nodename, uts.release, uts.version, uts.machine);
 #else
