$NetBSD$

--- ircd/ircd.c.orig	2017-10-20 22:29:47.000000000 +0000
+++ ircd/ircd.c
@@ -66,6 +66,10 @@
 #include "authproc.h"
 #include "operhash.h"
 
+#include <sys/param.h>
+#include <unistd.h>
+#include <pwd.h>
+
 static void
 ircd_die_cb(const char *str) __attribute__((noreturn));
 
@@ -617,6 +621,22 @@ seed_random(void *unused)
 	srand(seed);
 }
 
+static int
+privdrop(void)
+{
+	struct passwd *pw;
+
+        if ((pw = getpwnam(CHARYBDIS_USER)) == NULL) {
+		fprintf(stderr, "unknown user %s", CHARYBDIS_USER);
+		return -1;
+	}
+
+        if (setgroups(1, &pw->pw_gid) || setegid(pw->pw_gid) || seteuid(pw->pw_gid))
+                return -1;
+
+	return 0;
+}
+
 /*
  * main
  *
@@ -635,8 +655,10 @@ charybdis_main(int argc, char * const ar
 	/* Check to see if the user is running us as root, which is a nono */
 	if(geteuid() == 0)
 	{
-		fprintf(stderr, "Don't run ircd as root!!!\n");
-		return -1;
+		if (privdrop() != 0) {
+			fprintf(stderr, "Don't run ircd as root!!!\n");
+			return -1;
+		}
 	}
 #endif
 
