$NetBSD: patch-third__party_angle_src_compiler_osinclude.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/angle/src/compiler/osinclude.h.orig	2011-04-13 08:13:40.000000000 +0000
+++ third_party/angle/src/compiler/osinclude.h
@@ -15,7 +15,8 @@
 #if defined(_WIN32) || defined(_WIN64)
 #define ANGLE_OS_WIN
 #elif defined(__APPLE__) || defined(__linux__) || \
-      defined(__FreeBSD__) || defined(__OpenBSD__) || \
+      defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__) || \
       defined(__sun)
 #define ANGLE_OS_POSIX
 #else
