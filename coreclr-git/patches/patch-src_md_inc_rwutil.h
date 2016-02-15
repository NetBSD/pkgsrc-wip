$NetBSD$

--- src/md/inc/rwutil.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/md/inc/rwutil.h
@@ -23,7 +23,7 @@ class UTSemReadWrite;
         else                                                \
         {                                                   \
             int cbBuffer = ((int)wcslen(wszInput) * 3) + 1; \
-            (szOutput) = (char *)_alloca(cbBuffer);         \
+            (szOutput) = (char *)Alloca(cbBuffer);         \
             Unicode2UTF((wszInput), (szOutput), cbBuffer);  \
         }                                                   \
     } while (0)
