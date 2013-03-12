$NetBSD: patch-src_bin_e__init.c,v 1.1 2013/03/12 07:54:06 roelants Exp $

Explicitly exec enlightenment_init, to make sure it becomes the
direct child, and not the shell running it. Else the splash screen
keeps running. (Doesn't happen with bash, which would exec anyway.)

--- src/bin/e_init.c.orig
+++ src/bin/e_init.c
@@ -68,7 +68,7 @@ e_init_show(void)
    else ver = strdup("XvX");
 
    snprintf(buf, sizeof(buf),
-            "%s/enlightenment/utils/enlightenment_init \'%s\' \'%i\' \'%s\' \'%s\'",
+            "exec %s/enlightenment/utils/enlightenment_init \'%s\' \'%i\' \'%s\' \'%s\'",
             e_prefix_lib_get(), theme,
             e_config->font_hinting, tit, ver);
    printf("RUN INIT: %s\n", buf);
