$NetBSD: patch-src_pam__pkcs11_pam__pkcs11.c,v 1.1 2012/11/26 00:49:52 lexort Exp $

NetBSD's pam implements pam_prompt.  configure should be testing for each
function and replacing separately.  For now, adjust for NetBSD.

--- src/pam_pkcs11/pam_pkcs11.c.orig	2012-04-07 16:55:19.000000000 +0000
+++ src/pam_pkcs11/pam_pkcs11.c
@@ -68,10 +68,7 @@ static int is_spaced_str(const char *str
 	return 1;
 }
 
-#ifndef HAVE_SECURITY_PAM_EXT_H
-/*
- * implement pam utilities for older versions of pam.
- */
+#ifdef DONT_ALREADY_IN_NETBSD
 static int pam_prompt(pam_handle_t *pamh, int style, char **response, char *fmt, ...)
 {
   int rv;
@@ -108,7 +105,12 @@ static int pam_prompt(pam_handle_t *pamh
   free(&resp[0]);
   return PAM_SUCCESS;
 }
+#endif
 
+#ifndef HAVE_SECURITY_PAM_EXT_H
+/*
+ * implement pam utilities for older versions of pam.
+ */
 static void
 pam_syslog(pam_handle_t *pamh, int priority, const char *fmt, ...)
 {
