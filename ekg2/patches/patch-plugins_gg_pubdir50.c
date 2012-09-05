$NetBSD: patch-plugins_gg_pubdir50.c,v 1.2 2012/09/05 08:48:22 shindenmorr Exp $

--- plugins/gg/pubdir50.c.orig	2011-03-17 17:08:11.000000000 +0000
+++ plugins/gg/pubdir50.c
@@ -36,6 +36,7 @@
 COMMAND(gg_command_find)
 {
 	gg_private_t *g = session_private_get(session);
+	userlist_t *u = userlist_find(session, target);
 	char **argv = NULL;
 	char **uargv = NULL;
 	gg_pubdir50_t req;
@@ -72,7 +73,7 @@ COMMAND(gg_command_find)
 		return -1;
 	}
 
-	if (target[0] != '-' || !params[0]) {		/* if window_current->target is even --blah use it. it's quite stupid hovewer. */
+	if (target[0] != '-' || !params[0] || u) {		/* if window_current->target is even --blah use it. it's quite stupid hovewer. */
 		const char *uid = get_uid(session, target);
 
 		if (!uid) {
