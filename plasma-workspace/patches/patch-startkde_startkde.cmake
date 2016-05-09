$NetBSD$

Ensure QT bindir is on path

--- startkde/startkde.cmake.orig	2016-04-19 11:20:13.000000000 +0000
+++ startkde/startkde.cmake
@@ -17,6 +17,12 @@ trap 'echo GOT SIGHUP' HUP
 # we have to unset this for Darwin since it will screw up KDE's dynamic-loading
 unset DYLD_FORCE_FLAT_NAMESPACE
 
+qtbindir=@QTDIR@/bin
+case $PATH in
+  $qtbindir|$qtbindir:*|*:$qtbindir|*:$qtbindir:*) ;;
+  *) PATH=$qtbindir:$PATH; export PATH;;
+esac
+
 # in case we have been started with full pathname spec without being in PATH
 bindir=`echo "$0" | sed -n 's,^\(/.*\)/[^/][^/]*$,\1,p'`
 if [ -n "$bindir" ]; then
