$NetBSD$

Avoid possible NULL dereference typing a line with just an EOF character
(typically via ^D). 

--- src/buffers.c.orig	2015-12-26 19:31:45.000000000 +0000
+++ src/buffers.c
@@ -408,7 +408,7 @@ dotimers:
 
 	if (inputReadLine && isInteractive) {
 		last_rl = readline("");
-		if (*last_rl)
+		if ((last_rl != NULL) && *last_rl)
 			add_history(last_rl);
 		s = (uchar *) last_rl;
 	} else {
