$NetBSD$

On NetBSD, use the same method to find HomeDir as OpenBSD.

--- src/App/ApplicationDirectories.cpp.orig	2026-03-25 02:21:55.000000000 +0000
+++ src/App/ApplicationDirectories.cpp
@@ -595,7 +595,7 @@ void ApplicationDirectories::migrateAllP
 }
 
 // TODO: Consider using this for all UNIX-like OSes
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <cstdio>
 #include <cstdlib>
 #include <sys/param.h>
