$NetBSD: patch-src_hotspot_share_libadt_dict.cpp,v 1.1 2020/03/21 10:46:57 rillig Exp $

Fix for -Werror=char-subscripts:

> dict.cpp:15:28: warning: array subscript has type ‘char’ [-Wchar-subscripts]
>      sum += c + (c<<shft[k++]);  // Universal hash function
>                             ^
> dict.cpp:17:27: warning: array subscript has type ‘char’ [-Wchar-subscripts]
>    return (int)((sum+xsum[k]) >> 1); // Hash key, un-modulo'd table size

The variable k only ever gets values between 0 and MAXID - 1, which is
20. Therefore changing the type doesn't affect the result of the
function. At optimization levels > 0, GCC 5.5.0 compiles to the same
code, no matter whether the variable type is signed char or unsigned int.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=94247

--- src/hotspot/share/libadt/dict.cpp.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/hotspot/share/libadt/dict.cpp	2021-06-10 13:36:07.173761696 -0400
@@ -235,7 +235,8 @@
 // limited to MAXID characters in length.  Experimental evidence on 150K of
 // C text shows excellent spreading of values for any size hash table.
 int hashstr(const void* t) {
-  char c, k = 0;
+  char c = 0;
+  unsigned char k = 0;
   int32_t sum = 0;
   const char* s = (const char*)t;
 
