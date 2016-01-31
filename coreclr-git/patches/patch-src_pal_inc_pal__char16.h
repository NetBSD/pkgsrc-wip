$NetBSD$

--- src/pal/inc/pal_char16.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/inc/pal_char16.h
@@ -29,7 +29,9 @@ This file is used to define the wchar_t 
 #ifndef PAL_STDCPP_COMPAT
 #if defined (PLATFORM_UNIX) && defined(__GNUC__)
 #undef wchar_t
-#define wchar_t __wchar_16_cpp__
+#undef __WCHAR_TYPE__
+#define __WCHAR_TYPE__ __wchar_16_cpp__
+#define wchar_t __WCHAR_TYPE__
 #endif // PLATFORM_UNIX
 
 // Set up the wchar_t type (which got preprocessed to __wchar_16_cpp__).
@@ -39,9 +41,13 @@ This file is used to define the wchar_t 
 #if !defined(_WCHAR_T_DEFINED) || !defined(_MSC_VER)
 #if defined (PLATFORM_UNIX)
 #if defined(__cplusplus)
-typedef char16_t wchar_t;
+#undef __WCHAR_TYPE__
+#define __WCHAR_TYPE__ char16_t
+#define wchar_t __WCHAR_TYPE__
 #else
-typedef unsigned short wchar_t;
+#undef __WCHAR_TYPE__
+#define __WCHAR_TYPE__ unsigned short
+#define wchar_t __WCHAR_TYPE__
 #endif // __cplusplus
 #endif // PLATFORM_UNIX
 #ifndef _WCHAR_T_DEFINED
@@ -49,4 +55,3 @@ typedef unsigned short wchar_t;
 #endif // !_WCHAR_T_DEFINED
 #endif // !_WCHAR_T_DEFINED || !_MSC_VER
 #endif // !PAL_STDCPP_COMPAT
-
