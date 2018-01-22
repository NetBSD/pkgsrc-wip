$NetBSD$

Ensure QT bindir is on path

--- startkde/startkde.cmake.orig	2018-01-02 13:12:27.516501002 +0000
+++ startkde/startkde.cmake
@@ -7,6 +7,12 @@
 # because we still need to do some cleanup.
 trap 'echo GOT SIGHUP' HUP
 
+qtbindir=@QTDIR@/bin
+case $PATH in
+  $qtbindir|$qtbindir:*|*:$qtbindir|*:$qtbindir:*) ;;
+  *) PATH=$qtbindir:$PATH; export PATH;;
+esac
+
 # Check if a Plasma session already is running and whether it's possible to connect to X
 kcheckrunning
 kcheckrunning_result=$?
