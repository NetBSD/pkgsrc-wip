$NetBSD$

--- include/common.hpp.orig	2024-10-03 22:11:28 UTC
+++ include/common.hpp
@@ -116,9 +116,9 @@ template <typename T, size_t N> char( &ArraySizeHelper
 	// Use the environments endian definitions
 	#include <endian.h>
 
-	#define BIG_ENDIAN		__BIG_ENDIAN
-	#define LITTLE_ENDIAN	__LITTLE_ENDIAN
-	#define BYTE_ORDER		__BYTE_ORDER
+	//#define BIG_ENDIAN		__BIG_ENDIAN
+	//#define LITTLE_ENDIAN	__LITTLE_ENDIAN
+	//#define BYTE_ORDER		__BYTE_ORDER
 
 #endif
 
