$NetBSD$

Convert char type to unsigned char type for tolower(3) to avoid
char-subscript error on NetBSD

--- libhfuzz/memorycmp.c.orig	2018-04-19 13:37:38.000000000 +0000
+++ libhfuzz/memorycmp.c
@@ -44,14 +44,14 @@ static inline int _strcasecmp(const char
     unsigned int v = 0;
 
     size_t i;
-    for (i = 0; tolower(s1[i]) == tolower(s2[i]); i++) {
+    for (i = 0; tolower((unsigned char)s1[i]) == tolower((unsigned char)s2[i]); i++) {
         if (s1[i] == '\0' || s2[i] == '\0') {
             break;
         }
         v++;
     }
     instrumentUpdateCmpMap(addr, v);
-    return (tolower(s1[i]) - tolower(s2[i]));
+    return (tolower((unsigned char)s1[i]) - tolower((unsigned char)s2[i]));
 }
 
 static inline int _strncmp(const char* s1, const char* s2, size_t n, uintptr_t addr) {
@@ -86,8 +86,8 @@ static inline int _strncasecmp(const cha
     int ret = 0;
 
     for (size_t i = 0; i < n; i++) {
-        if (tolower(s1[i]) != tolower(s2[i])) {
-            ret = ret ? ret : (tolower(s1[i]) - tolower(s2[i]));
+        if (tolower((unsigned char)s1[i]) != tolower((unsigned char)s2[i])) {
+            ret = ret ? ret : (tolower((unsigned char)s1[i]) - tolower((unsigned char)s2[i]));
         } else {
             v++;
         }
