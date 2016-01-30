$NetBSD$

Missing ctype(3) casts.

--- lib/nss/nssinit.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/nss/nssinit.c
@@ -1248,25 +1248,25 @@ NSS_VersionCheck(const char *importedVer
 #define NSS_VERSION_VARIABLE __nss_base_version
 #include "verref.h"
 
-    while (isdigit(*ptr)) {
+    while (isdigit((unsigned char)*ptr)) {
         vmajor = 10 * vmajor + *ptr - '0';
         ptr++;
     }
     if (*ptr == '.') {
         ptr++;
-        while (isdigit(*ptr)) {
+        while (isdigit((unsigned char)*ptr)) {
             vminor = 10 * vminor + *ptr - '0';
             ptr++;
         }
         if (*ptr == '.') {
             ptr++;
-            while (isdigit(*ptr)) {
+            while (isdigit((unsigned char)*ptr)) {
                 vpatch = 10 * vpatch + *ptr - '0';
                 ptr++;
             }
             if (*ptr == '.') {
                 ptr++;
-                while (isdigit(*ptr)) {
+                while (isdigit((unsigned char)*ptr)) {
                     vbuild = 10 * vbuild + *ptr - '0';
                     ptr++;
                 }
