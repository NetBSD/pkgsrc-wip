$NetBSD: patch-src_process.c,v 1.1 2013/06/06 15:31:07 makoto Exp $

Avoid following problem:
  process.c:6169:58: error: 'WCONTINUED' undeclared (first use in this function)
This  would probably be the same as following part in in <sys/wait.h>:
+----
| #define WALLSIG         0x00000008      /* wait for processes that exit
|                                            with any signal, i.e. SIGCHLD
|                                           and alternates */
+----

--- src/process.c.orig	2013-06-06 21:19:28.000000000 +0900
+++ src/process.c	2013-06-06 21:20:14.000000000 +0900
@@ -32,6 +32,11 @@ along with GNU Emacs.  If not, see <http
 #include <fcntl.h>
 
 #include "lisp.h"
+
+/* see include/sys/wait.h (and also emacsclient.c) */
+# ifndef WCONTINUED
+#  define WCONTINUED 8
+# endif
 
 /* Only MS-DOS does not define `subprocesses'.  */
 #ifdef subprocesses
