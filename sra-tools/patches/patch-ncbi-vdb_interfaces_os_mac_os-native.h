$NetBSD$

# Unbreak build under latest Xcode

--- ncbi-vdb/interfaces/os/mac/os-native.h.orig	2025-08-21 18:23:20.418291610 +0000
+++ ncbi-vdb/interfaces/os/mac/os-native.h
@@ -66,6 +66,7 @@ char *strndup ( const char *str, size_t
 }
 #endif
 
+#if defined(__APPLE__) && __ENVIRONMENT_OS_VERSION_MIN_REQUIRED__ < 150000
 /*--------------------------------------------------------------------------
  * strchrnul - implemented inline here
  */
@@ -77,6 +78,7 @@ char *strchrnul ( const char *str, int c
         ( void ) 0;
     return & ( ( char* ) str ) [ i ];
 }
+#endif
 
 /*--------------------------------------------------------------------------
  * memchr - implemented inline here
