$NetBSD$

--- runtime/phobos/osmodel.mak.orig	2018-08-23 23:30:04.000000000 +0000
+++ runtime/phobos/osmodel.mak
@@ -12,6 +12,9 @@ ifeq (,$(OS))
   ifeq (FreeBSD,$(uname_S))
     OS:=freebsd
   endif
+  ifeq (NetBSD,$(uname_S))
+    OS:=netbsd
+  endif
   ifeq (OpenBSD,$(uname_S))
     OS:=openbsd
   endif
