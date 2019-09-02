$NetBSD$

--- gdb/auxv.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/auxv.c
@@ -266,8 +266,12 @@ default_auxv_parse (struct target_ops *o
 
   if (endptr - ptr < sizeof_auxv_field * 2)
     return -1;
-
-  *typep = extract_unsigned_integer (ptr, sizeof_auxv_field, byte_order);
+#ifdef __NetBSD__
+  const int sizeof_auxv_type = 4;
+#else
+  const int sizeof_auxv_type = sizeof_auxv_field;
+#endif
+  *typep = extract_unsigned_integer (ptr, sizeof_auxv_type, byte_order);
   ptr += sizeof_auxv_field;
   *valp = extract_unsigned_integer (ptr, sizeof_auxv_field, byte_order);
   ptr += sizeof_auxv_field;
