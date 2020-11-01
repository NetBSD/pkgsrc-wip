$NetBSD$

HOST_NAME_MAX isn't defined on NetBSD.

--- pam.c.orig	2020-02-03 21:41:31.000000000 +0000
+++ pam.c
@@ -271,6 +271,9 @@ pamauth(const char *user, const char *my
 		if (!interactive)
 			errx(1, "Authorization required");
 
+#ifdef __netbsd__
+#define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
+#endif
 		/* doas style prompt for pam */
 		char host[HOST_NAME_MAX + 1];
 		if (gethostname(host, sizeof(host)))
