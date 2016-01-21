$NetBSD$

--- src/pal/src/loader/module.cpp.orig	2016-01-18 21:51:39.000000000 +0000
+++ src/pal/src/loader/module.cpp
@@ -1621,6 +1621,8 @@ static HMODULE LOADLoadLibrary(LPCSTR sh
         shortAsciiName = "libc.dylib";
 #elif defined(__FreeBSD__)
         shortAsciiName = FREEBSD_LIBC;
+#elif defined(__NetBSD__)
+        shortAsciiName = "libc.so";
 #else
         shortAsciiName = LIBC_SO;
 #endif
