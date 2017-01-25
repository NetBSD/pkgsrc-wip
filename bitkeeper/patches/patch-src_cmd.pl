$NetBSD$

--- src/cmd.pl.orig	2016-07-15 19:21:30.000000000 +0000
+++ src/cmd.pl
@@ -63,7 +63,7 @@ typedef struct CMD {
 	u8	remote:1;	/* always allowed as a remote command */
 } CMD;
 
-CMD	*cmd_lookup(const char *str, unsigned int len);
+CMD	*cmd_lookup(const char *str, size_t len);
 
 END
 
