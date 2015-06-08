$NetBSD: patch-include_atalk_ldapconfig.h,v 1.2 2015/06/08 17:38:56 fhajny Exp $

--- include/atalk/ldapconfig.h.orig	2013-10-28 13:43:14.000000000 +0000
+++ include/atalk/ldapconfig.h
@@ -1,4 +1,5 @@
 #ifdef HAVE_LDAP
+#ifdef HAVE_ACLS
 
 #ifndef LDAPCONFIG_H
 #define LDAPCONFIG_H
@@ -53,5 +54,5 @@ extern struct pref_array prefs_array[];
 extern int ldap_config_valid;
 
 #endif /* LDAPCONFIG_H */
-
+#endif /* HAVE_ACLS */
 #endif /* HAVE_LDAP */
