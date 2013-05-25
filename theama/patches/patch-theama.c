$NetBSD: patch-theama.c,v 1.1 2013/05/25 13:47:33 francksys Exp $

/* Replace Phrases file with package one */
--- theama.c.orig	2013-05-19 22:56:42.000000000 +0000
+++ theama.c
@@ -29,7 +29,7 @@
 #include <fcntl.h>
 
 /* Phrases file */
-#define PDB		"/usr/local/share/theama/phrases/english.txt"
+#define PDB		"/usr/pkg/share/theama/phrases/english.txt"
 
 #define HIDECH		'_'		/* Hidden chars symbol */
 #define MAXERR		30		/* Max error before lost */
