$NetBSD$

Fix readline.h location

--- utils/client/kresc.c.orig	2024-08-26 10:16:43.040999797 +0000
+++ utils/client/kresc.c
@@ -3,7 +3,7 @@
  */
 #include <arpa/inet.h>
 #include <contrib/ccan/asprintf/asprintf.h>
-#include <editline/readline.h>
+#include <readline.h>
 #include <errno.h>
 #include <histedit.h>
 #include <stdbool.h>
