$NetBSD$

--- include/lldb/Host/Editline.h.orig	2016-05-12 20:11:40.000000000 +0000
+++ include/lldb/Host/Editline.h
@@ -23,6 +23,15 @@
 
 #ifndef liblldb_Editline_h_
 #define liblldb_Editline_h_
+
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(7,99,28)
+#define NETBSD_USE_WCHAR
+#endif
+#endif
+
+
 #if defined(__cplusplus)
 
 #include <sstream>
@@ -32,7 +41,7 @@
 // components needed to handle wide characters ( <codecvt>, codecvt_utf8, libedit built with '--enable-widec' )
 // are available on some platforms. The wchar_t versions of libedit functions will only be
 // used in cases where this is true.  This is a compile time dependecy, for now selected per target Platform
-#if defined (__APPLE__) || defined(__NetBSD__)
+#if defined (__APPLE__) || defined(NETBSD_USE_WCHAR)
 #define LLDB_EDITLINE_USE_WCHAR 1
 #include <codecvt>
 #else
