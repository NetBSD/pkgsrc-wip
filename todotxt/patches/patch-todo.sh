$NetBSD: patch-todo.sh,v 1.2 2014/05/13 14:01:03 ttys Exp $

Change the path for bash.

--- todo.sh.orig	2014-05-13 12:31:26.000000000 +0000
+++ todo.sh
@@ -1,4 +1,4 @@
-#! /bin/bash
+#! /usr/pkg/bin/bash
 
 # === HEAVY LIFTING ===
 shopt -s extglob extquote
