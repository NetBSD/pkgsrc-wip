$NetBSD$

--- src/man.c.orig	2006-05-01 20:34:22.000000000 +0000
+++ src/man.c
@@ -594,7 +594,7 @@ make_roff_command (const char *path, con
		 the current position plus 10 lines.  This plus setpl()
		 gives us a single page that just contains the whole
		 man page. (William Webber, wew@cs.rmit.edu.au) */
-	      strcat(buft, "; echo \".\\\\\\\"\"; echo \".pl \\n(nlu+10\"");
+	      strcat(buft, "; echo \".\\\\\\\"\"; echo \".pl \\\\\\n(n;lu+10\"");
 #if 0
	      /* In case this doesnt work for some reason,
		 michaelkjohnson suggests: I've got a simple
