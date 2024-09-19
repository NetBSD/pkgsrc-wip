$NetBSD$

NetBSD doesn't support "WCHAR_T" so set Iconv::GdWchar to "UCS-4LE" codeset.

Set inBuf to const char type because it's a second argument to iconv function,
which on NetBSD has type const char.

--- iconv.cc	2016-04-26 16:32:50.000000000 +0000
+++ iconv.cc
@@ -6,7 +6,7 @@
 #include <errno.h>
 #include <string.h>
 
-#ifdef __WIN32
+#if defined (__WIN32) || defined (__NetBSD__)
 char const * const Iconv::GdWchar = "UCS-4LE";
 #else
 char const * const Iconv::GdWchar = "WCHAR_T";
@@ -45,10 +45,11 @@ Iconv::Result Iconv::convert( void const
 {
   size_t result = iconv( state,
 //                         #ifdef __WIN32
-//                         (char const **)&inBuf,
-//                         #else
+		  				 #if defined(__NetBSD__)
+                         (char const **)&inBuf,
+                         #else
                          (char **)&inBuf,
-//                         #endif
+                         #endif
                                            &inBytesLeft,
                          (char **)&outBuf, &outBytesLeft );
 
