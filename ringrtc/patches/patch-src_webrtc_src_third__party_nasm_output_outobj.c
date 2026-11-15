$NetBSD$

* Import from chromium

--- src/webrtc/src/third_party/nasm/output/outobj.c.orig	2026-11-10 15:47:11.659000000 +0000
+++ src/webrtc/src/third_party/nasm/output/outobj.c
@@ -407,7 +407,7 @@ static ObjRecord *obj_name(ObjRecord * o
     orp->used += len + 1;
     if (obj_uppercase)
         while (--len >= 0) {
-            *ptr++ = toupper(*name);
+            *ptr++ = toupper((unsigned char)*name);
             name++;
     } else
         memcpy(ptr, name, len);
