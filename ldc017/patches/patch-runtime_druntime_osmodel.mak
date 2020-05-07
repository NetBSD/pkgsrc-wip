$NetBSD$

--- runtime/druntime/osmodel.mak.orig	2018-08-23 23:29:55.000000000 +0000
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
