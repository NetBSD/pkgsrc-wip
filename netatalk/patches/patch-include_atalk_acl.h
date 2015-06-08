$NetBSD: patch-include_atalk_acl.h,v 1.1 2015/06/08 20:03:14 fhajny Exp $

--- include/atalk/acl.h.orig	2014-07-03 05:16:05.000000000 +0000
+++ include/atalk/acl.h
@@ -61,6 +61,7 @@ extern int remove_acl_vfs(const char *na
 #else /* HAVE_ACLS=no */
 
 #define O_NETATALK_ACL 0
+#define O_IGNORE 0
 #define chmod_acl chmod
 
 #endif /* HAVE_ACLS */
