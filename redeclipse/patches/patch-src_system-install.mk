# $NetBSD$
--- src/system-install.mk.orig	2015-10-11 12:31:08.000000000 -0700
+++ src/system-install.mk	2015-10-13 21:01:16.000000000 -0700
@@ -5,19 +5,20 @@
 appclient=$(APPCLIENT)$(APPMODIFIER)$(BIN_SUFFIX)
 appserver=$(APPSERVER)$(APPMODIFIER)$(BIN_SUFFIX)
 
-prefix=/usr/local
+PREFIX?=/usr/local
 games=
 gamesbin=/bin
-bindir=$(DESTDIR)$(prefix)/bin
-gamesbindir=$(DESTDIR)$(prefix)$(gamesbin)
-libexecdir=$(DESTDIR)$(prefix)/lib$(games)
-datadir=$(DESTDIR)$(prefix)/share$(games)
-docdir=$(DESTDIR)$(prefix)/share/doc
-mandir=$(DESTDIR)$(prefix)/share/man
-menudir=$(DESTDIR)$(prefix)/share/applications
-icondir=$(DESTDIR)$(prefix)/share/icons/hicolor
-pixmapdir=$(DESTDIR)$(prefix)/share/pixmaps
-appdatadir=$(DESTDIR)$(prefix)/share/appdata
+bindir=$(DESTDIR)$(PREFIX)/bin
+gamesbindir=$(DESTDIR)$(PREFIX)$(gamesbin)
+libexecdir=$(DESTDIR)$(PREFIX)/lib$(games)
+datadir=$(DESTDIR)$(PREFIX)/share$(games)
+docdir=$(DESTDIR)$(PREFIX)/share/doc
+MANDIR?=/share/man
+mandir=$(DESTDIR)$(PREFIX)$(MANDIR)
+menudir=$(DESTDIR)$(PREFIX)/share/applications
+icondir=$(DESTDIR)$(PREFIX)/share/icons/hicolor
+pixmapdir=$(DESTDIR)$(PREFIX)/share/pixmaps
+appdatadir=$(DESTDIR)$(PREFIX)/share/appdata
 
 ICONS= \
 	install/nix/$(appsrcname)_x16.png \
