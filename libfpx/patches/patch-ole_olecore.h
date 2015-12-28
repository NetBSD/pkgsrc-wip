$NetBSD$

--- ole/olecore.h.orig	2015-12-28 09:38:12.000000000 +0000
+++ ole/olecore.h
@@ -55,7 +55,7 @@ const GUID BlankGUID = { 0, 0, 0, { 0, 0
 #ifdef _WIN32
 #define ORIGINATING_OS_VERSION  0x0002  // 32-bit Windows
 #endif
-#ifdef __unix
+#if defined(_UNIX)
 #define ORIGINATING_OS_VERSION  0x0003  // generic UNIX identifier
 #endif
 #ifndef ORIGINATING_OS_VERSION
