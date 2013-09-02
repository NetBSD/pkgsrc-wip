$NetBSD: patch-common_integer__t.hpp,v 1.1 2013/09/02 19:08:24 thomasklausner Exp $

Use standard sized integer types

--- common/integer_t.hpp.orig	2010-10-27 12:30:16.000000000 +0000
+++ common/integer_t.hpp
@@ -50,15 +50,8 @@
 #include <netinet/in.h>
 #endif
 
-// Define the Integer 64 bits and Unsigned Integer 64 bits types 
-// depending on platform capability
-#if LONG_LONG_MAX<9223372036854775807LL
-#error "long long type definition is not 64 bits"
-#else
-
-// long long is coded on 8 bytes use it for Integer64 types
-typedef unsigned long long T_UnsignedInteger64, *T_pUnsignedInteger64;
-typedef long long          T_Integer64, *T_pInteger64;
+typedef uint64_t T_UnsignedInteger64, *T_pUnsignedInteger64;
+typedef int64_t T_Integer64, *T_pInteger64;
 
 #define strtoull_f strtoull
 #define strtoll_f  strtoll
@@ -66,11 +59,9 @@ typedef long long          T_Integer64, 
 #define ntohll_f ntohll
 #define htonll_f htonll
 
-#endif // LONG_LONG_MAX
-
 // Define the Integer 32bits and Unsigned Integer 32bits  types
-typedef unsigned long T_UnsignedInteger32, *T_pUnsignedInteger32;
-typedef long          T_Integer32, *T_pInteger32;
+typedef uint32_t T_UnsignedInteger32, *T_pUnsignedInteger32;
+typedef int32_t          T_Integer32, *T_pInteger32;
 
 // Check the size of long type
 #if LONG_MAX==9223372036854775807L
