$NetBSD$

Convert char type to unsigned char type for isdigit(3) to avoid
char-subscript error on NetBSD

--- libhfcommon/util.c.orig	2018-04-19 13:37:38.000000000 +0000
+++ libhfcommon/util.c
@@ -284,11 +284,11 @@ int64_t fastArray64Search(uint64_t* arra
 }
 
 bool util_isANumber(const char* s) {
-    if (!isdigit(s[0])) {
+    if (!isdigit((unsigned char)s[0])) {
         return false;
     }
     for (int i = 0; s[i]; s++) {
-        if (!isdigit(s[i]) && s[i] != 'x') {
+        if (!isdigit((unsigned char)s[i]) && s[i] != 'x') {
             return false;
         }
     }
