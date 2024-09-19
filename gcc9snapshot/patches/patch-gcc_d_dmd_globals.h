$NetBSD$

--- gcc/d/dmd/globals.h.orig	2019-01-09 17:59:55.000000000 +0000
+++ gcc/d/dmd/globals.h
@@ -84,6 +84,7 @@ struct Param
     bool isOSX;         // generate code for Mac OSX
     bool isWindows;     // generate code for Windows
     bool isFreeBSD;     // generate code for FreeBSD
+    bool isNetBSD;      // generate code for NetBSD
     bool isOpenBSD;     // generate code for OpenBSD
     bool isSolaris;     // generate code for Solaris
     bool hasObjectiveC; // target supports Objective-C
