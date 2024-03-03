$NetBSD$

Remove size of array declarations defined elsewhere

--- yasr/yasr.h.orig	2023-04-08 21:22:57.000000000 +0000
+++ yasr/yasr.h
@@ -304,11 +304,11 @@ extern int cl_synthport;
 extern Opt opt[];
 extern int synthopt;
 extern char *conffile;
-extern unsigned char buf[256];
-extern int kbuf[100];
+extern char buf[];
+extern int kbuf[];
 extern int kbuflen;
-extern char usershell[OPT_STR_SIZE];
-extern char ttsbuf[80];
+extern char usershell[];
+extern char ttsbuf[];
 extern Voices voices;
 extern int special;
 extern char charmap[];
