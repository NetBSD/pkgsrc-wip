$NetBSD: patch-config.mk,v 1.1 2015/05/26 11:10:47 f8l Exp $

Allows overriding PREFIX and MANDIR.

Imported from http://cvsweb.openbsd.org/cgi-bin/cvsweb/~checkout~/ports/www/dwb/patches/patch-config_mk?rev=1.2

Drop -DGTK_DISABLE_DEPRECATED to build with gtk>=3.14.

--- config.mk.orig	2014-03-07 11:39:43.000000000 +0000
+++ config.mk
@@ -49,14 +49,14 @@ TARGET = $(REAL_NAME)
 
 
 # target directories
-PREFIX=/usr
+PREFIX?=/usr
 BINDIR=$(PREFIX)/bin
 DATAROOTDIR=$(PREFIX)/share
 DATADIR=$(DATAROOTDIR)
 
 # manpages
 MANFILE=$(REAL_NAME).1
-MANDIR=$(DATAROOTDIR)/man
+MANDIR?=$(DATAROOTDIR)/man
 MAN1DIR=$(MANDIR)/man1
 MAN7DIR=$(MANDIR)/man7
 MANAPI=dwb-js.7
@@ -146,12 +146,10 @@ BASE_SCRIPT=base.js
 CFLAGS := $(CFLAGS)
 CFLAGS += -Wall 
 CFLAGS += -Werror=format-security 
-CFLAGS += -pipe
-CFLAGS += --ansi
+CFLAGS += -Wno-variadic-macros
+CFLAGS += -ansi
 CFLAGS += -std=c99
 CFLAGS += -D_POSIX_C_SOURCE='200112L'
-CFLAGS += -O2
-CFLAGS += -g
 CFLAGS += -D_BSD_SOURCE
 CFLAGS += -D_NETBSD_SOURCE
 CFLAGS += -D__BSD_VISIBLE
@@ -159,21 +157,21 @@ CFLAGS += -D__BSD_VISIBLE
 CFLAGS += $(shell pkg-config --cflags $(LIBS))
 
 ifeq ($(shell pkg-config --exists '$(LIBSOUP) >= 2.38' && echo 1), 1)
-M4FLAGS += -DWITH_LIBSOUP_2_38=1 -G
+M4FLAGS += -DWITH_LIBSOUP_2_38=1
 CFLAGS += -DWITH_LIBSOUP_2_38=1
 endif
 
 ifeq (${DISABLE_HSTS}, 1)
 CFLAGS += -DDISABLE_HSTS
 else 
-M4FLAGS += -DWITH_HSTS=1 -G 
+M4FLAGS += -DWITH_HSTS=1 
 endif
 
 CFLAGS_OPTIONS := $(CFLAGS)
 
 ifeq (${USEGTK3}, 1) 
 CPPFLAGS+=-DGTK_DISABLE_SINGLE_INCLUDES
-CPPFLAGS+=-DGTK_DISABLE_DEPRECATED
+#CPPFLAGS+=-DGTK_DISABLE_DEPRECATED
 CPPFLAGS+=-DGDK_DISABLE_DEPRECATED
 CPPFLAGS+=-DGSEAL_ENABLE
 M4FLAGS += -DWITH_GTK3=1
