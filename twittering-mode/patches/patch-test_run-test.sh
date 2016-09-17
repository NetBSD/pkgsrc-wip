$NetBSD$

make test tries to run names listed on emacsen=, 
limit emacs only for pkgsrc

--- test/run-test.sh.orig	2016-03-21 19:03:59.000000000 +0900
+++ test/run-test.sh	2016-10-29 21:27:21.000000000 +0900
@@ -1,6 +1,6 @@
 #!/bin/bash

-emacsen="emacs emacs23 emacs22 emacs21"
+emacsen="emacs"

 continue_on_error=
 if [ $# -gt 0 ]; then
