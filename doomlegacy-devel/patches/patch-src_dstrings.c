$NetBSD$

Print note that this is a patched version to terminal.
https://sourceforge.net/p/doomlegacy/feature-requests/96/

--- src/dstrings.c.orig	2021-09-27 10:05:58.000000000 +0000
+++ src/dstrings.c
@@ -542,6 +542,11 @@ char *text[NUMTEXT] = {
     "get a copy of the original game, call 1-800-IDGAMES or see the readme file.\n"
     "        You will not receive technical support for modified games.\n"
     "                      press enter to continue\n"
+    "===========================================================================\n"
+    "===========================================================================\n"
+    "Note for pkgsrc: This version uses pkgsrc patches for additional features:\n"
+    "- Support for \"-blockmap\" command line option (create blockmap internally,\n"
+    "  Feature request #96)\n"
     "===========================================================================\n",
 
   // SHAREWARE
