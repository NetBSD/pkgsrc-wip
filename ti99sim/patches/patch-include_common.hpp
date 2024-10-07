$NetBSD$

# Locate endian.h on macOS

--- include/common.hpp.orig	2020-05-25 20:52:23.000000000 +0000
+++ include/common.hpp
@@ -111,14 +111,18 @@ template <typename T, size_t N> char( &A
 
 	#endif
 
+#elif defined (OS_MACOSX)
+
+	#include <machine/endian.h>
+
 #else
 
 	// Use the environments endian definitions
 	#include <endian.h>
 
-	#define BIG_ENDIAN		__BIG_ENDIAN
-	#define LITTLE_ENDIAN	__LITTLE_ENDIAN
-	#define BYTE_ORDER		__BYTE_ORDER
+	//#define BIG_ENDIAN		__BIG_ENDIAN
+	//#define LITTLE_ENDIAN	__LITTLE_ENDIAN
+	//#define BYTE_ORDER		__BYTE_ORDER
 
 #endif
 
