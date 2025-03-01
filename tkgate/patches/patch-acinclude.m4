$NetBSD$

set default PREFIX

--- acinclude.m4.orig	2022-02-15 11:57:56.000000000 +0000
+++ acinclude.m4
@@ -22,6 +22,10 @@ AC_DEFUN([TKG_SET_PREFIX],[
       AC_PREFIX_DEFAULT(/usr/local)
       install_dir=/usr/local
       ;;
+    XNetBSD)
+      AC_PREFIX_DEFAULT(@PREFIX@)
+      install_dir=@PREFIX@/X11
+      ;;
     *)
       AC_PREFIX_DEFAULT(/usr/local)
       install_dir=/usr/local
