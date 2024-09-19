$NetBSD$

There's no reason to not always include assert.h when using assert.

--- idlib/Str.h.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/Str.h
@@ -17,9 +17,7 @@
 #ifndef __STR_H__
 #define __STR_H__
 
-#ifdef __linux__
 #include <cassert>
-#endif
 
 #define ASSERT_ENUM_STRING( string, index )		( 1 / (int)!( string - index ) ) ? #string : ""
 
