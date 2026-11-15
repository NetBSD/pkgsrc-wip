$NetBSD$

* Import from chromium

--- src/webrtc/src/third_party/nasm/output/outieee.c.orig	2026-11-10 15:47:11.650000000 +0000
+++ src/webrtc/src/third_party/nasm/output/outieee.c
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
