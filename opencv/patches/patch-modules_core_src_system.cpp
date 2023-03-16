$NetBSD: patch-modules_core_src_system.cpp,v 1.1 2013/04/29 21:31:12 joerg Exp $

--- modules/core/src/system.cpp.orig	2022-12-28 14:31:52.000000000 +0000
+++ modules/core/src/system.cpp
@@ -243,6 +243,7 @@ std::wstring GetTempFileNameWinRT(std::w
 #endif
 #include <sys/time.h>
 #include <time.h>
+#include <unistd.h>
 
 #if defined __MACH__ && defined __APPLE__
 #include <mach/mach.h>
