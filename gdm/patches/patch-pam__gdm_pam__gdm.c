$NetBSD$

Include only supported pam headers

--- pam_gdm/pam_gdm.c.orig	2021-03-30 13:25:30.000000000 +0000
+++ pam_gdm/pam_gdm.c
@@ -21,11 +21,13 @@
 
 #include <unistd.h>
 
+#include <security/pam_modules.h>
+#ifndef OPENPAM
 #include <security/_pam_macros.h>
 #include <security/pam_ext.h>
 #include <security/pam_misc.h>
-#include <security/pam_modules.h>
 #include <security/pam_modutil.h>
+#endif
 
 #ifdef HAVE_KEYUTILS
 #include <keyutils.h>
