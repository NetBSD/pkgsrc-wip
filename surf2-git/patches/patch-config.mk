$NetBSD$

Use pkg-config for X11{INC,LIB} too.

--- config.mk.orig	2018-10-08 12:22:47.000000000 +0000
+++ config.mk
@@ -9,8 +9,8 @@ MANPREFIX = $(PREFIX)/share/man
 LIBPREFIX = $(PREFIX)/lib
 LIBDIR = $(LIBPREFIX)/surf
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = `pkg-config --cflags x11`
+X11LIB = `pkg-config --libs x11`
 
 GTKINC = `pkg-config --cflags gtk+-3.0 gcr-3 webkit2gtk-4.0`
 GTKLIB = `pkg-config --libs gtk+-3.0 gcr-3 webkit2gtk-4.0`
@@ -18,8 +18,8 @@ WEBEXTINC = `pkg-config --cflags webkit2
 WEBEXTLIBS = `pkg-config --libs webkit2gtk-4.0 webkit2gtk-web-extension-4.0`
 
 # includes and libs
-INCS = -I$(X11INC) $(GTKINC)
-LIBS = -L$(X11LIB) -lX11 $(GTKLIB) -lgthread-2.0
+INCS = $(X11INC) $(GTKINC)
+LIBS = $(X11LIB) $(GTKLIB) -lgthread-2.0
 
 # flags
 CPPFLAGS = -DVERSION=\"$(VERSION)\" -DWEBEXTDIR=\"$(LIBDIR)\" \
