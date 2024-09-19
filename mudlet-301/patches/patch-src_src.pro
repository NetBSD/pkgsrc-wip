$NetBSD$
Swap out /usr/local with @PREFIX@
--- src/src.pro.orig	2017-07-11 00:01:53.000000000 +0000
+++ src/src.pro
@@ -90,17 +90,17 @@ DEFINES += APP_TARGET=\\\"$${TARGET}$${T
 unix:!macx {
 # Distribution packagers would be using PREFIX = /usr but this is accepted
 # destination place for local builds for software for all users:
-    isEmpty( PREFIX ) PREFIX = /usr/local
+    isEmpty( PREFIX ) PREFIX = @PREFIX@
     isEmpty( DATAROOTDIR ) DATAROOTDIR = $${PREFIX}/share
     isEmpty( DATADIR ) DATADIR = $${DATAROOTDIR}/mudlet
-# According to Linux FHS /usr/local/games is an alternative location for leasure time BINARIES 8-):
+# According to Linux FHS @PREFIX@/games is an alternative location for leasure time BINARIES 8-):
     isEmpty( BINDIR ) BINDIR = $${PREFIX}/bin
-# Again according to FHS /usr/local/share/games is the corresponding place for locally built games documentation:
+# Again according to FHS @PREFIX@/share/games is the corresponding place for locally built games documentation:
     isEmpty( DOCDIR ) DOCDIR = $${DATAROOTDIR}/doc/mudlet
     LIBS += -lpcre \
         -llua5.1 \
         -lhunspell \
-        -L/usr/local/lib/ \
+        -L@PREFIX@/lib/ \
         -lyajl \
         -lGLU \
         -lzip \
@@ -147,7 +147,7 @@ macx {
     QT_CONFIG -= no-pkg-config
     CONFIG += link_pkgconfig
     PKGCONFIG += hunspell lua5.1 yajl libpcre libzip
-    INCLUDEPATH += /usr/local/include
+    INCLUDEPATH += @PREFIX@/include
 }
 
 # There does not seem to be an obvious pkg-config option for these two
