$NetBSD$

Must include sys/wait.h for WEXITSTATUS

--- mu/mu-cmd-find.cc.orig	2024-04-08 20:22:35.000000000 +0000
+++ mu/mu-cmd-find.cc
@@ -27,6 +27,9 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
+#if defined(__NetBSD__)
+#include <sys/wait.h>
+#endif
 
 #include "message/mu-message.hh"
 #include "mu-maildir.hh"
