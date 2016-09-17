$NetBSD$

--- common.mak.orig	2015-12-31 19:42:10.000000000 +0000
+++ common.mak
@@ -207,11 +207,11 @@ CXXFLAGS	= $(CFLAGS) $(ASMFLAG) -fdata-s
 
 CFLAGS          += $(OPTFLAGS) $(REVFLAGS) $(COMMON_CFLAGS)
 
-prefix          = /usr/local
+prefix          = ${PREFIX}
 bindir          = $(prefix)/bin
 sbindir         = $(prefix)/sbin
-mandir          = $(prefix)/share/man/man1
-smandir         = $(prefix)/share/man/man8
+mandir          = $(prefix)/${PKGMANDIR}/man1
+smandir         = $(prefix)/${PKGMANDIR}/man8
 datadir         = $(prefix)/share
 docdir          = $(datadir)/doc/aircrack-ng
 libdir		= $(prefix)/lib
