$NetBSD$

--- gdb/gdbserver/regcache.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/gdbserver/regcache.c
@@ -198,7 +198,7 @@ regcache_cpy (struct regcache *dst, stru
 
 /* Return a reference to the description of register N.  */
 
-static const struct reg &
+static const struct xreg &
 find_register_by_number (const struct target_desc *tdesc, int n)
 {
   return tdesc->reg_defs[n];
@@ -251,8 +251,10 @@ find_regno (const struct target_desc *td
 {
   for (int i = 0; i < tdesc->reg_defs.size (); ++i)
     {
-      if (strcmp (name, find_register_by_number (tdesc, i).name) == 0)
+      if (strcmp (name, find_register_by_number (tdesc, i).name) == 0) {
+        printf("%s(): regno='%s' i=%d\n", __func__, name, i);
 	return i;
+      }
     }
   internal_error (__FILE__, __LINE__, "Unknown register %s requested",
 		  name);
