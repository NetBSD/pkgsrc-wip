$NetBSD$

--- gdbserver/regcache.cc.orig	2020-08-18 00:00:07.000000000 +0000
+++ gdbserver/regcache.cc
@@ -251,8 +251,10 @@ find_regno (const struct target_desc *td
 {
   for (int i = 0; i < tdesc->reg_defs.size (); ++i)
     {
-      if (strcmp (name, find_register_by_number (tdesc, i).name) == 0)
+      if (strcmp (name, find_register_by_number (tdesc, i).name) == 0) {
+	printf("%s(): regno='%s' i=%d\n", __func__, name, i);
 	return i;
+      }
     }
   internal_error (__FILE__, __LINE__, "Unknown register %s requested",
 		  name);
