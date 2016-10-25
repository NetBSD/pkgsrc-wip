$NetBSD$

--- gdb/config/djgpp/djconfig.sh.orig	2016-10-25 00:44:13.511325574 +0000
+++ gdb/config/djgpp/djconfig.sh
@@ -92,7 +92,7 @@ TMPFILE="${TMPDIR-.}/cfg.tmp"
 
 # We need to skip the build directory if it is a subdirectory of $srcdir,
 # otherwise we will have an infinite recursion on our hands...
-if test "`pwd`" == "${srcdir}" ; then
+if test "`pwd`" = "${srcdir}" ; then
   SKIPDIR=""
   SKIPFILES=""
 else
