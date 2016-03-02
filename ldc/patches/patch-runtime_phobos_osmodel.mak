$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/osmodel.mak.orig	2016-02-13 20:04:46.000000000 +0000
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
