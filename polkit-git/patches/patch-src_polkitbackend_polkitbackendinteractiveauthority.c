$NetBSD: patch-src_polkitbackend_polkitbackendinteractiveauthority.c,v 1.1 2015/06/06 23:10:23 krytarowski Exp $

* for *BSD netgroup functions

--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2013-04-04 18:16:50.000000000 +0000
+++ src/polkitbackend/polkitbackendinteractiveauthority.c
@@ -23,7 +23,12 @@
 #include <errno.h>
 #include <pwd.h>
 #include <grp.h>
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#define BSD_NETGROUP
+#else
 #include <netdb.h>
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
@@ -2113,15 +2118,23 @@ get_users_in_net_group (PolkitIdentity  
   ret = NULL;
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
+#ifdef BSD_NETGROUP
+  setnetgrent (name);
+#else
   if (setnetgrent (name) == 0)
     {
       g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
       goto out;
     }
+#endif
 
   for (;;)
     {
+#ifdef BSD_NETGROUP
+      const char *hostname, *username, *domainname;
+#else
       char *hostname, *username, *domainname;
+#endif
       PolkitIdentity *user;
       GError *error = NULL;
 
