$NetBSD$

--- src/ToolBox/SOS/Strike/strike.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/strike.h
@@ -76,6 +76,21 @@
 #ifndef PAL_STDCPP_COMPAT
 #include <malloc.h>
 #endif
+
+#if defined(_MSC_VER)
+#define alloca _alloca
+#elif defined(PLATFORM_UNIX)
+#define _alloca alloca
+#else
+// MingW
+#define _alloca __builtin_alloca
+#define alloca __builtin_alloca
+#endif //_MSC_VER
+
+#if defined(__GNUC__) && defined(PLATFORM_UNIX)
+#define alloca  __builtin_alloca                                                                                                                             
+#endif // __GNUC__
+
 #include <stddef.h>
 
 #ifndef FEATURE_PAL
@@ -128,4 +143,3 @@ HRESULT SetNGENCompilerFlags(DWORD flags
 
 
 #endif // __strike_h__
-
