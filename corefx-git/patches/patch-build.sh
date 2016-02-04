$NetBSD$

--- build.sh.orig	2016-02-04 18:43:38.000000000 +0000
+++ build.sh
@@ -236,6 +236,7 @@ __BuildOS=$__HostOS
 __BuildType=Debug
 __CMakeArgs=DEBUG
 
+if [ "x$MONOROOTDIR" = "x" ]; then
 case $__HostOS in
     FreeBSD)
         __monoroot=/usr/local
@@ -247,6 +248,9 @@ case $__HostOS in
         __monoroot=/usr
         ;;
 esac
+else
+__monoroot="$MONOROOTDIR"
+fi
 
 __referenceassemblyroot=$__monoroot/lib/mono/xbuild-frameworks
 BUILDERRORLEVEL=0
