$NetBSD$

--- pre-process.c.orig	2014-02-16 22:44:57.000000000 +0000
+++ pre-process.c
@@ -933,7 +933,8 @@ static int handle_include_path(struct st
 	if (do_include_path(path, list, token, filename, flen))
 		return 0;
 out:
-	error_die(token->pos, "unable to open '%s'", filename);
+	sparse_error(token->pos, "unable to open '%s'", filename);
+	return -1;
 }
 
 static int handle_include(struct stream *stream, struct token **list, struct token *token)
