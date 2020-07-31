$NetBSD$

* NetBSD support

--- src/bin/system/e_system_main.c.orig	2020-07-26 16:39:12.083981300 +0000
+++ src/bin/system/e_system_main.c
@@ -33,7 +33,11 @@ _etc_enlightenment_system_conf_check(con
    gid_t gl[MAXGROUPS];
    char type[32], usergroup[256], cmd[32], glob[256], buf[1024];
    Eina_Bool in_usergroup;
+#if defined (__NetBSD__)
+   FILE *f = fopen("/usr/pkg/etc/enlightenment/system.conf", "r");
+#else
    FILE *f = fopen("/etc/enlightenment/system.conf", "r");
+#endif
    if (!f) return 1; // if the config doesn't exist - allow by policy
 
    gn = getgroups(MAXGROUPS, gl);
