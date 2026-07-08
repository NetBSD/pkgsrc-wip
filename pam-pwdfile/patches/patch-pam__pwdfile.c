$NetBSD$

NetBSD support

--- pam_pwdfile.c.orig	2024-06-17 10:17:40.000000000 +0000
+++ pam_pwdfile.c
@@ -50,6 +50,11 @@
 #endif
 #endif
 
+#ifdef __NetBSD__
+#define _NETBSD_SOURCE
+#include <fcntl.h>
+#endif
+
 #include <syslog.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -66,7 +71,17 @@
 
 #define PAM_SM_AUTH
 #include <security/pam_modules.h>
+#ifdef __Linux__
 #include <security/pam_ext.h>
+#endif
+
+#ifdef __NetBSD__
+#define PWDFILE_SYSLOG(pamh, priority, fmt, ...) \
+    syslog((priority), (fmt), ##__VA_ARGS__)
+#else
+#define PWDFILE_SYSLOG(pamh, priority, fmt, ...) \
+    pam_syslog((pamh), (priority), (fmt), ##__VA_ARGS__)
+#endif
 
 static int lock_fd(int fd) {
     int delay;
@@ -123,29 +138,29 @@ PAM_EXTERN int pam_sm_authenticate(pam_h
     
 #ifdef HAVE_PAM_FAIL_DELAY
     if (use_delay) {
-	if (debug) pam_syslog(pamh, LOG_DEBUG, "setting fail delay");
+	if (debug) PWDFILE_SYSLOG(pamh, LOG_DEBUG, "setting fail delay");
 	(void) pam_fail_delay(pamh, 2000000);   /* 2 sec */
     }
 #endif
     
     if (!pwdfilename) {
-	pam_syslog(pamh, LOG_ERR, "password file name not specified");
+	PWDFILE_SYSLOG(pamh, LOG_ERR, "password file name not specified");
 	return PAM_AUTHINFO_UNAVAIL;
     }
     
     if (pam_get_user(pamh, &name, NULL) != PAM_SUCCESS) {
-	pam_syslog(pamh, LOG_ERR, "couldn't get username from PAM stack");
+	PWDFILE_SYSLOG(pamh, LOG_ERR, "couldn't get username from PAM stack");
 	return PAM_AUTH_ERR;
     }
-    if (debug) pam_syslog(pamh, LOG_DEBUG, "username is %s", name);
+    if (debug) PWDFILE_SYSLOG(pamh, LOG_DEBUG, "username is %s", name);
     
     if (!(pwdfile = fopen(pwdfilename, "r"))) {
-	pam_syslog(pamh, LOG_ALERT, "couldn't open password file %s", pwdfilename);
+	PWDFILE_SYSLOG(pamh, LOG_ALERT, "couldn't open password file %s", pwdfilename);
 	return PAM_AUTHINFO_UNAVAIL;
     }
     
     if (use_flock && lock_fd(fileno(pwdfile)) == -1) {
-	pam_syslog(pamh, LOG_ALERT, "couldn't lock password file %s", pwdfilename);
+	PWDFILE_SYSLOG(pamh, LOG_ALERT, "couldn't lock password file %s", pwdfilename);
 	fclose(pwdfile);
 	return PAM_AUTHINFO_UNAVAIL;
     }
@@ -172,16 +187,16 @@ PAM_EXTERN int pam_sm_authenticate(pam_h
     /* we keep linebuf (allocated by getline), stored_crypted_password is pointing into it */
 
     if (!stored_crypted_password)
-	if (debug) pam_syslog(pamh, LOG_ERR, "user not found in password database");
+	if (debug) PWDFILE_SYSLOG(pamh, LOG_ERR, "user not found in password database");
     
     if (stored_crypted_password && !strlen(stored_crypted_password)) {
-	if (debug) pam_syslog(pamh, LOG_DEBUG, "user has empty password field");
+	if (debug) PWDFILE_SYSLOG(pamh, LOG_DEBUG, "user has empty password field");
 	free(linebuf);
 	return flags & PAM_DISALLOW_NULL_AUTHTOK ? PAM_AUTH_ERR : PAM_SUCCESS;
     }
     
     if (pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL) != PAM_SUCCESS) {
-	pam_syslog(pamh, LOG_ERR, "couldn't get password from PAM stack");
+	PWDFILE_SYSLOG(pamh, LOG_ERR, "couldn't get password from PAM stack");
 	free(linebuf);
 	return PAM_AUTH_ERR;
     }
@@ -191,7 +206,7 @@ PAM_EXTERN int pam_sm_authenticate(pam_h
 	return PAM_USER_UNKNOWN;
     }
     
-    if (debug) pam_syslog(pamh, LOG_DEBUG, "got crypted password == '%s'", stored_crypted_password);
+    if (debug) PWDFILE_SYSLOG(pamh, LOG_DEBUG, "got crypted password == '%s'", stored_crypted_password);
     
 #ifdef USE_CRYPT_R
     crypt_buf.initialized = 0;
@@ -200,18 +215,18 @@ PAM_EXTERN int pam_sm_authenticate(pam_h
     if (!(crypted_password = crypt(password, stored_crypted_password)))
 #endif
     {
-	pam_syslog(pamh, LOG_ERR, "crypt() failed");
+	PWDFILE_SYSLOG(pamh, LOG_ERR, "crypt() failed");
 	free(linebuf);
 	return PAM_AUTH_ERR;
     }
     
     if (strcmp(crypted_password, stored_crypted_password)) {
-	pam_syslog(pamh, LOG_NOTICE, "wrong password for user %s", name);
+	PWDFILE_SYSLOG(pamh, LOG_NOTICE, "wrong password for user %s", name);
 	free(linebuf);
 	return PAM_AUTH_ERR;
     }
     
-    if (debug) pam_syslog(pamh, LOG_DEBUG, "passwords match");
+    if (debug) PWDFILE_SYSLOG(pamh, LOG_DEBUG, "passwords match");
     free(linebuf);
     return PAM_SUCCESS;
 }
