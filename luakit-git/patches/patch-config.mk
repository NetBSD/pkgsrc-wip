$NetBSD$

Improve DESTDIR support and use it only in install and deinstall target.
The various paths are used in buildopts.h and there having the
DESTDIR is not desiderable.

--- config.mk.orig	2018-09-22 23:42:41.000000000 +0000
+++ config.mk
@@ -25,14 +25,6 @@ PIXMAPDIR  ?= $(PREFIX)/share/pixmaps
 APPDIR     ?= $(PREFIX)/share/applications
 LIBDIR     ?= $(PREFIX)/lib/luakit
 
-INSTALLDIR := $(DESTDIR)$(PREFIX)
-MANPREFIX  := $(DESTDIR)$(MANPREFIX)
-DOCDIR     := $(DESTDIR)$(DOCDIR)
-XDGPREFIX  := $(DESTDIR)$(XDGPREFIX)
-PIXMAPDIR  := $(DESTDIR)$(PIXMAPDIR)
-APPDIR     := $(DESTDIR)$(APPDIR)
-LIBDIR     := $(DESTDIR)$(LIBDIR)
-
 # Should luakit be built to load relative config paths (./lib ./config) ?
 # (Useful when running luakit from it's source directory, disable otherwise).
 ifneq ($(DEVELOPMENT_PATHS),0)
