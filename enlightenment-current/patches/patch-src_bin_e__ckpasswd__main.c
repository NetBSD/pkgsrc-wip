$NetBSD$

--- src/bin/e_ckpasswd_main.c.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/bin/e_ckpasswd_main.c
@@ -1,4 +1,3 @@
-#include "e_util_suid.h"
 
 #include "config.h"
 
@@ -16,6 +15,7 @@
 #include <Ecore.h>
 #include <Eldbus.h>
 
+#include "e_util_suid.h"
 static uid_t uid = -1; // uid of person running me
 static gid_t gid = -1; // gid of person running me
 static char *user_name = NULL;
@@ -39,7 +39,7 @@ _check_auth(uid_t id, const char *guess)
 
 
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) | defined(__NetBSD__)
 #include <security/pam_constants.h>
 
 static int
