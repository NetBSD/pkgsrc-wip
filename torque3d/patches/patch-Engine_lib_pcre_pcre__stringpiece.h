$NetBSD$

--- Engine/lib/pcre/pcre_stringpiece.h.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/lib/pcre/pcre_stringpiece.h
@@ -43,7 +43,7 @@
 #include <iosfwd>    // for ostream forward-declaration
 
 // Don't use bits/type_traits.h on Linux - Andrew Galante, GG 8/2/2009
-#if !defined(_MSC_VER) && !defined(__CELLOS_LV2__) && !defined(__APPLE__) && !defined(__linux__)
+#if !defined(_MSC_VER) && !defined(__CELLOS_LV2__) && !defined(__APPLE__) && !defined(__linux__) && !defined(__NetBSD__)
 #ifdef __MINGW32__
 #define HAVE_TYPE_TRAITS
 #include <bits/type_traits.h>
