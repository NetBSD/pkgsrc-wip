$NetBSD$

Add NetBSD support.

--- test/testrunner.tcl.orig	2025-02-18 14:09:33.000000000 +0000
+++ test/testrunner.tcl
@@ -246,6 +246,15 @@ switch -nocase -glob -- $tcl_platform(os
     set TRG(run)         run.sh
     set TRG(runcmd)      "bash run.sh"
   }
+  *netbsd* {
+    set TRG(platform)    linux
+    set TRG(make)        make.sh
+    set TRG(makecmd)     "sh make.sh"
+    set TRG(testfixture) testfixture
+    set TRG(shell)       sqlite3
+    set TRG(run)         run.sh
+    set TRG(runcmd)      "sh run.sh"
+  }
   *openbsd* {
     set TRG(platform)    linux
     set TRG(make)        make.sh
