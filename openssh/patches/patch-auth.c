$NetBSD: patch-auth.c,v 1.4 2016/01/18 12:53:26 jperkin Exp $

* Replace uid 0 with ROOTUID macro.
* Use login_getpwclass() instead of login_getclass() so that the root
  vs. default login class distinction is made correctly, from FrrrBSD's
  ports.

--- auth.c.orig	2019-05-01 11:28:52.028281617 +0000
+++ auth.c
@@ -472,7 +472,7 @@ check_key_in_hostfiles(struct passwd *pw
 		user_hostfile = tilde_expand_filename(userfile, pw->pw_uid);
 		if (options.strict_modes &&
 		    (stat(user_hostfile, &st) == 0) &&
-		    ((st.st_uid != 0 && st.st_uid != pw->pw_uid) ||
+		    ((st.st_uid != ROOTUID && st.st_uid != pw->pw_uid) ||
 		    (st.st_mode & 022) != 0)) {
 			logit("Authentication refused for %.100s: "
 			    "bad owner or modes for %.200s",
@@ -599,7 +599,7 @@ getpwnamallow(struct ssh *ssh, const cha
 	if (!allowed_user(ssh, pw))
 		return (NULL);
 #ifdef HAVE_LOGIN_CAP
-	if ((lc = login_getclass(pw->pw_class)) == NULL) {
+	if ((lc = login_getpwclass(pw->pw_class)) == NULL) {
 		debug("unable to get login class: %s", user);
 		return (NULL);
 	}
