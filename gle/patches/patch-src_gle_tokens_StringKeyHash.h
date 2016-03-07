$NetBSD$

Fix build with libc++, clean up macro checks.

in file included from ./../tokens/Tokenizer.h:51:
./../tokens/StringKeyHash.h:79:18: error: expected namespace name 
        using namespace __gnu_cxx;  // using gnu extensions such as "hash"

See also https://trac.macports.org/ticket/41760

--- src/gle/tokens/StringKeyHash.h.orig	2015-08-16 07:51:24.000000000 +0000
+++ src/gle/tokens/StringKeyHash.h
@@ -46,21 +46,19 @@
 	#pragma warning( disable : 4996 )
 #endif
 
-#define EXT_HASH
-#ifdef _MSC_VER
-	#undef EXT_HASH
-#endif
-#ifdef GCC2
-	#undef EXT_HASH
+#ifdef __GLIBCXX__
+	#define EXT_HASH
 #endif
+
 #ifdef EXT_HASH
-//	#include <ext/hash_map>
+	#include <ext/hash_map>
 #else
 	#ifdef _MSC_VER
 	#include <hash_map>
 	using namespace stdext;
 //	typedef hash _Hash;
-	#else
+	#endif
+	#ifdef __GLIBCXX__
 	#include <hash_map.h>
 	#endif
 #endif
@@ -74,7 +72,7 @@
 
 using namespace std;
 
-#ifndef GCC2
+#ifdef __GLIBCXX__
 #ifndef _MSC_VER
 	using namespace __gnu_cxx;  // using gnu extensions such as "hash"
 #endif
