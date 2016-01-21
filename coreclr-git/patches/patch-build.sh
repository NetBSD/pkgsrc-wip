$NetBSD$

--- build.sh.orig	2016-01-21 18:24:09.000000000 +0000
+++ build.sh
@@ -129,6 +129,8 @@ build_coreclr()
     # processors available to a single process.
     if [ `uname` = "FreeBSD" ]; then
         NumProc=`sysctl hw.ncpu | awk '{ print $2+1 }'`
+    elif [ `uname` = "NetBSD" ]; then
+        NumProc=$(($(getconf NPROCESSORS_ONLN)+1))
     else
         NumProc=$(($(getconf _NPROCESSORS_ONLN)+1))
     fi
