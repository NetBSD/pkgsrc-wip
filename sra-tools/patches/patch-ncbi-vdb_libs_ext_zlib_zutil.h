$NetBSD$

# Unbreak build under latest Xcode

--- ncbi-vdb/libs/ext/zlib/zutil.h.orig	2025-08-21 18:12:04.202560252 +0000
+++ ncbi-vdb/libs/ext/zlib/zutil.h
@@ -137,7 +137,7 @@ extern z_const char * const z_errmsg[10]
 #  endif
 #endif
 
-#if defined(MACOS) || defined(TARGET_OS_MAC)
+#if (defined(MACOS) || defined(TARGET_OS_MAC)) && (__ENVIRONMENT_OS_VERSION_MIN_REQUIRED__ < 150000)
 #  define OS_CODE  7
 #  ifndef Z_SOLO
 #    if defined(__MWERKS__) && __dest_os != __be_os && __dest_os != __win32_os
