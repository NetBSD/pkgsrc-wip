$NetBSD$

--- src/auth/cellconfig.c.orig	2018-05-07 18:33:21.000000000 +0000
+++ src/auth/cellconfig.c
@@ -993,6 +993,11 @@ afsconf_LookupServer(const char *service
     int pass = 0;
     char *IANAname = (char *) afsconf_FindIANAName(service);
     int tservice = afsconf_FindService(service);
+#ifdef __NetBSD__
+    res_state res;
+#else
+#define res (&_res)
+#endif
 
     realCellName = NULL;
 
