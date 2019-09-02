$NetBSD$

--- libiberty/make-temp-file.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ libiberty/make-temp-file.c
@@ -129,10 +129,10 @@ choose_tmpdir (void)
 	base = try_dir (P_tmpdir, base);
 #endif
 
-      /* Try /var/tmp, /usr/tmp, then /tmp.  */
+      /* Try /tmp, /var/tmp, then /usr/tmp.  */
+      base = try_dir (tmp, base);
       base = try_dir (vartmp, base);
       base = try_dir (usrtmp, base);
-      base = try_dir (tmp, base);
       
       /* If all else fails, use the current directory!  */
       if (base == 0)
