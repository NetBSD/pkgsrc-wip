$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/nasm/output/outieee.c.orig	2026-07-06 22:58:46.000000000 +0000
+++ third_party/nasm/output/outieee.c
@@ -1245,8 +1245,10 @@ static int32_t ieee_putlr(struct ieeeFix
 static void ieee_unqualified_name(char *dest, char *source)
 {
     if (ieee_uppercase) {
-        while (*source)
-            *dest++ = toupper(*source++);
+        while (*source) {
+            unsigned char ch = *source++;
+            *dest++ = toupper(ch);
+        }
         *dest = 0;
     } else
         strcpy(dest, source);
