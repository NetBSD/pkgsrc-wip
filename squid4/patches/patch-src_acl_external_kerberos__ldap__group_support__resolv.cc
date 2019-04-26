$NetBSD$

--- src/acl/external/kerberos_ldap_group/support_resolv.cc.orig	2019-02-19 02:46:22.000000000 +0000
+++ src/acl/external/kerberos_ldap_group/support_resolv.cc
@@ -396,7 +396,7 @@ get_ldap_hostname_list(struct main_args 
 #if (SIZEOF_LONG == 8)
         error("%s| %s: ERROR: Inconsistence message length: %ld!=0\n", LogTime(), PROGRAM, buffer + len - p);
 #else
-        error((char *) "%s| %s: ERROR: Inconsistence message length: %d!=0\n", LogTime(), PROGRAM, buffer + len - p);
+        error((char *) "%s| %s: ERROR: Inconsistence message length: %ld!=0\n", LogTime(), PROGRAM, buffer + len - p);
 #endif
         goto finalise;
     }
