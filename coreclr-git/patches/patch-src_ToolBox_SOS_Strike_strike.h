$NetBSD$

--- src/ToolBox/SOS/Strike/strike.h.orig	2016-04-08 23:29:23.000000000 +0000
+++ src/ToolBox/SOS/Strike/strike.h
@@ -42,8 +42,13 @@
 #define _wcscspn    wcscspn
 #define _wcscat     wcscat
 #define _wcsstr     wcsstr
+#define _wcsstr     wcsstr
 #endif // !PAL_STDCPP_COMPAT
 
+#ifdef PLATFORM_UNIX
+#define  _vsnprintf vsnprintf
+#endif
+
 #define ___in       _SAL1_Source_(__in, (), _In_)
 #define ___out      _SAL1_Source_(__out, (), _Out_)
 
