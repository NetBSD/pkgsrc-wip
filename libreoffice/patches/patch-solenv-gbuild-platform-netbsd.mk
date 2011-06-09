$NetBSD: patch-solenv-gbuild-platform-netbsd.mk,v 1.1 2011/06/09 23:33:11 thomasklausner Exp $

--- solenv/gbuild/platform/netbsd.mk.orig	2011-05-22 09:36:09.000000000 +0000
+++ solenv/gbuild/platform/netbsd.mk
@@ -40,6 +40,6 @@ gb_COMPILERDEFAULTOPTFLAGS := -O2
 
 include $(GBUILDDIR)/platform/unxgcc.mk
 
-gb_CppunitTest_CPPTESTPRECOMMAND := LD_LIBRARY_PATH=$(OUTDIR)/lib:/usr/pkg/lib
+gb_CppunitTest_CPPTESTPRECOMMAND := LD_LIBRARY_PATH=$(OUTDIR)/lib:/usr/pkg/lib:/usr/X11R7/lib
 
 # vim: set noet sw=4:
