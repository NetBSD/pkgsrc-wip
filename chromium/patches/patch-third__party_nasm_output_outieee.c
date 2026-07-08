$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/nasm/output/outieee.c.orig	2026-07-06 22:58:46.000000000 +0000
+++ third_party/nasm/output/outieee.c
@@ -1246,7 +1246,8 @@ static void ieee_unqualified_name(char *
 {
     if (ieee_uppercase) {
         while (*source)
-            *dest++ = toupper(*source++);
+            unsigned char ch = *source++;
+            *dest++ = toupper(ch);
         *dest = 0;
     } else
         strcpy(dest, source);
