$NetBSD$

SYSCONFDIR fix

--- mdep.c.orig	2022-09-20 05:14:53.000000000 +0000
+++ mdep.c
@@ -53,7 +53,7 @@
 #endif
 
 #ifndef RC_DIR
-#define RC_DIR		"/etc"
+#define RC_DIR		"@PKG_SYSCONFDIR@"
 #endif
 
 #define MIDI_BUFSIZE	1024
