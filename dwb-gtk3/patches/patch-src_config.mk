$NetBSD: patch-src_config.mk,v 1.1 2015/05/26 11:10:47 f8l Exp $

Imported from http://cvsweb.openbsd.org/cgi-bin/cvsweb/~checkout~/ports/www/dwb/patches/patch-src_config_mk?rev=1.1

--- src/config.mk.orig	2014-03-07 11:39:43.000000000 +0000
+++ src/config.mk
@@ -1,3 +1,3 @@
 ifeq ($(shell $(BASEDIR)/$(TOOLDIR)/check_header.sh execinfo.h $(CC)), 1)
-CFLAGS += -DHAS_EXECINFO
+# CFLAGS += -DHAS_EXECINFO
 endif
