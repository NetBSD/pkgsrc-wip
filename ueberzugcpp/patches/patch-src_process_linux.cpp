$NetBSD$

Fix build on NetBSD.

--- src/process/linux.cpp.orig	2025-02-11 15:17:24.790710191 +0000
+++ src/process/linux.cpp
@@ -19,7 +19,7 @@
 #include <fmt/format.h>
 #include <fstream>
 #include <limits>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/types.h>
 #else
 #  include <sys/sysmacros.h>
