$NetBSD$

$host_os is "netbsd" (all lowercase) according to config.log

--- config.m4.orig	2016-08-29 19:02:44.000000000 +0000
+++ config.m4
@@ -3,5 +3,5 @@ dnl config.m4 for extension gnupg
 AC_CANONICAL_HOST
 case $host_os in
-   *BSD*)
+   *BSD* | *bsd)
         GNUPG_DL=""
         ;;
