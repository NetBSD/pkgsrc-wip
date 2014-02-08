$NetBSD: patch-src_process.c,v 1.3 2014/02/08 01:29:38 makoto Exp $

Avoid following problem:
  process.c:6169:58: error: 'WCONTINUED' undeclared (first use in this function)

--- src/process.c.orig	2013-06-06 21:19:28.000000000 +0900
+++ src/process.c	2013-06-06 21:20:14.000000000 +0900
@@ -32,6 +32,11 @@ along with GNU Emacs.  If not, see <http
 #include <fcntl.h>
 
 #include "lisp.h"
+
+/* see include/sys/wait.h (and also emacsclient.c) */
+# ifndef WCONTINUED
+#  define WCONTINUED 0
+# endif
 
 /* Only MS-DOS does not define `subprocesses'.  */
 #ifdef subprocesses
