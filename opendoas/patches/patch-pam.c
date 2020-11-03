$NetBSD$

Use _POSIX_HOST_NAME_MAX if HOST_NAME_MAX is unavailable.

--- pam.c.orig	2020-11-02 13:01:52.000000000 +0000
+++ pam.c
@@ -271,6 +271,9 @@ pamauth(const char *user, const char *my
 		if (!interactive)
 			errx(1, "Authorization required");
 
+#ifndef HOST_NAME_MAX
+#define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
+#endif
 		/* doas style prompt for pam */
 		char host[HOST_NAME_MAX + 1];
 		if (gethostname(host, sizeof(host)))
