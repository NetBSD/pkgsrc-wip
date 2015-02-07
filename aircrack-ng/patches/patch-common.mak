$NetBSD: patch-common.mak,v 1.1 2015/02/07 01:35:39 tnn2 Exp $

--- common.mak.orig	2014-07-24 23:39:05.000000000 +0000
+++ common.mak
@@ -121,11 +121,11 @@ OPTFLAGS        = -D_FILE_OFFSET_BITS=64
 CFLAGS          ?= -g -W -Wall -O3
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
