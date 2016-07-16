$NetBSD$

Support SunOS.

--- src/rust-installer/install-template.sh.orig	2016-03-03 01:04:59.000000000 +0000
+++ src/rust-installer/install-template.sh
@@ -324,6 +324,10 @@ get_host_triple() {
     local _ostype
     case $_uname_value in
 
+	SunOS)
+            _ostype=sun-solaris
+            ;;
+
 	Linux)
             _ostype=unknown-linux-gnu
             ;;
