$NetBSD$

--- include/lldb/Host/Editline.h.orig	2016-05-01 10:39:36.000000000 +0000
+++ include/lldb/Host/Editline.h
@@ -27,11 +27,12 @@
 
 #include <sstream>
 #include <vector>
+#include <locale>
 
 // components needed to handle wide characters ( <codecvt>, codecvt_utf8, libedit built with '--enable-widec' )
 // are not consistenly available on non-OSX platforms.  The wchar_t versions of libedit functions will only be
 // used in cases where this is true.  This is a compile time dependecy, for now selected per target Platform
-#if defined (__APPLE__)
+#if defined (__APPLE__) || defined(__NetBSD__)
 #define LLDB_EDITLINE_USE_WCHAR 1
 #include <codecvt>
 #else
