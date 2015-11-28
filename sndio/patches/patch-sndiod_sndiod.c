$NetBSD$

Add NetBSD support.

Patch pending upstream.

--- sndiod/sndiod.c.orig	2015-04-24 17:44:06.000000000 +0000
+++ sndiod/sndiod.c
@@ -286,8 +286,18 @@ privdrop(void)
 	if (setpriority(PRIO_PROCESS, 0, SNDIO_PRIO) < 0)
 		err(1, "setpriority");
 	if (setgroups(1, &pw->pw_gid) ||
-	    setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) ||
-	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid))
+#if HAVE_SETRESGID
+	    setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid)
+#else
+	    setegid(pw->pw_gid)
+#endif
+	    ||
+#if HAVE_SETRESUID
+	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid)
+#else
+	    seteuid(pw->pw_gid)
+#endif
+	    )
 		err(1, "cannot drop privileges");
 }
 
