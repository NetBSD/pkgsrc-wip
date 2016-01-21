$NetBSD$

--- run-cppcheck.sh.orig	2016-01-18 21:51:38.000000000 +0000
+++ run-cppcheck.sh
@@ -41,6 +41,8 @@ SloccountOutput="sloccount.sc"
 # processors available to a single process.
 if [ `uname` = "FreeBSD" ]; then
 NumProc=`sysctl hw.ncpu | awk '{ print $2+1 }'`
+elif [ `uname` = "NetBSD" ]; then
+NumProc=$(($(getconf NPROCESSORS_ONLN)+1))
 else
 NumProc=$(($(getconf _NPROCESSORS_ONLN)+1))
 fi
@@ -114,4 +116,4 @@ then
 fi
 
 echo Check finished.  Results can be found in: $CppCheckOutputs $SlocCountOutputs
-exit 0
\ No newline at end of file
+exit 0
