$NetBSD: patch-todo.sh,v 1.1 2014/05/13 11:43:34 ttys Exp $

Change the path for bash.

--- todo.sh.orig	2012-03-26 18:56:04.000000000 +0000
+++ todo.sh
@@ -1,4 +1,4 @@
-#! /bin/bash
+#! /usr/pkg/bin/bash
 
 # === HEAVY LIFTING ===
 shopt -s extglob extquote
