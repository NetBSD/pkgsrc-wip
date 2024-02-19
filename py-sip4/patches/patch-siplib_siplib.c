$NetBSD$

--- siplib/siplib.c.orig	2023-04-09 02:03:57.802590100 +0000
+++ siplib/siplib.c
@@ -13747,7 +13747,11 @@ static struct _frame *sip_api_get_frame(
 
     while (frame != NULL && depth > 0)
     {
+#if (PY_VERSION_HEX >= 0x3b0f0) // 3.11.0
+        frame = PyFrame_GetBack(frame);
+#else
         frame = frame->f_back;
+#endif
         --depth;
     }
 
