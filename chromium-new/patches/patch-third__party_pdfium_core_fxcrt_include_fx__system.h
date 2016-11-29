$NetBSD$

--- third_party/pdfium/core/fxcrt/include/fx_system.h.orig	2016-11-10 20:03:03.000000000 +0000
+++ third_party/pdfium/core/fxcrt/include/fx_system.h
@@ -40,7 +40,7 @@
 #elif defined(_WIN64)
 #define _FX_OS_ _FX_WIN64_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #define _FX_OS_ _FX_LINUX_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_LINUX_
 #elif defined(__APPLE__)
