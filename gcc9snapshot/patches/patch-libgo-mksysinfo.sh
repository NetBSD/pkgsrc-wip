$NetBSD$

--- libgo/mksysinfo.sh.orig	2019-03-19 14:00:59.000000000 +0000
+++ libgo/mksysinfo.sh	2019-04-28 21:05:47.652698233 +0000
@@ -1127,7 +1127,7 @@
 # Prefer largefile variant if available.
 # CentOS 5 does not have f_flags, so pull from f_spare.
 statfs=`grep '^type _statfs64 ' gen-sysinfo.go || true`
-if test "$statfs" == ""; then
+if test "$statfs" = ""; then
   statfs=`grep '^type _statfs ' gen-sysinfo.go || true`
 fi
 if ! echo "$statfs" | grep f_flags; then
