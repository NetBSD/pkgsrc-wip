$NetBSD$

--- src/arch/netbsd/mcontext/context.d.orig	2017-11-02 06:34:51.954526149 +0000
+++ src/arch/netbsd/mcontext/context.d
@@ -0,0 +1,2 @@
+context.o: context.c ../../../../src/include/config.h mcontext.h \
+  amd64-ucontext.h
