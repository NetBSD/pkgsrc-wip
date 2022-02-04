$NetBSD$

Avoid negative array size.

--- include/winnt.h.orig	2022-01-18 20:52:35.000000000 +0000
+++ include/winnt.h
@@ -403,7 +403,7 @@ extern "C" {
 
 /* Compile time assertion */
 
-#define C_ASSERT(e) extern void __C_ASSERT__(int [(e)?1:-1])
+#define C_ASSERT(e) extern void __C_ASSERT__(int [(e)?1:0])
 
 /* Eliminate Microsoft C/C++ compiler warning 4715 */
 #if defined(_MSC_VER) && (_MSC_VER > 1200)
