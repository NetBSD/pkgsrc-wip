$NetBSD$

Setup for SUBST to use the pkgsrc go bulid command

--- build.sh.orig	2025-12-26 16:08:24.000000000 +0000
+++ build.sh
@@ -185,10 +185,10 @@ function build_one_dir() {
   else
     if [ "$special_binary_name" != "" ]
     then
-      go build -o $special_binary_name -ldflags "$ldflags" $go_build_flags $dir
+      @GO_CMD@ -o $special_binary_name $dir
       echo "  note: building $dir as $binary_name"
     else
-      go build -ldflags "$ldflags" $go_build_flags $dir
+      @GO_CMD@ $dir
     fi
   fi
 
