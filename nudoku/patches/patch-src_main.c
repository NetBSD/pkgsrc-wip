$NetBSD$

Add missing <locale.h> header, for setlocale.

--- src/main.c.orig	2019-12-12 21:05:55.068322791 +0000
+++ src/main.c
@@ -20,6 +20,7 @@ along with this program. If not, see <ht
 
 /* INCLUDES */
 #include "gettext.h"			/* gettext */
+#include <locale.h>				/* setlocale */
 #include <stdlib.h>				/* rand, srand */
 #include <unistd.h>				/* getopt */
 #include <ncurses.h>			/* ncurses */
