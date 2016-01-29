$NetBSD$

--- src/pal/inc/pal_char16.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/inc/pal_char16.h
@@ -28,8 +28,8 @@ This file is used to define the wchar_t 
 
 #ifndef PAL_STDCPP_COMPAT
 #if defined (PLATFORM_UNIX) && defined(__GNUC__)
-#undef wchar_t
-#define wchar_t __wchar_16_cpp__
+//#undef wchar_t
+//#define wchar_t __wchar_16_cpp__
 #endif // PLATFORM_UNIX
 
 // Set up the wchar_t type (which got preprocessed to __wchar_16_cpp__).
@@ -49,4 +49,3 @@ typedef unsigned short wchar_t;
 #endif // !_WCHAR_T_DEFINED
 #endif // !_WCHAR_T_DEFINED || !_MSC_VER
 #endif // !PAL_STDCPP_COMPAT
-
