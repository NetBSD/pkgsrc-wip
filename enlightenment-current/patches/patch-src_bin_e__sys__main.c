$NetBSD$

* NetBSD support

--- src/bin/e_sys_main.c.orig	2020-07-26 16:39:12.080648000 +0000
+++ src/bin/e_sys_main.c
@@ -565,7 +565,11 @@ auth_etc_enlightenment_sysactions(char *
    int allow = 0;
    int deny = 0;
 
+#if defined (__NetBSD__)
+   snprintf(file, sizeof(file), "@PREFIX@/etc/enlightenment/sysactions.conf");
+#else
    snprintf(file, sizeof(file), "/etc/enlightenment/sysactions.conf");
+#endif
    f = fopen(file, "r");
    if (!f)
      {
