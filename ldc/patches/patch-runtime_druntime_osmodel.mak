$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/osmodel.mak.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/osmodel.mak
@@ -15,6 +15,9 @@ ifeq (,$(OS))
   ifeq (OpenBSD,$(uname_S))
     OS:=openbsd
   endif
+  ifeq (NetBSD,$(uname_S))
+    OS:=netbsd
+  endif
   ifeq (Solaris,$(uname_S))
     OS:=solaris
   endif
