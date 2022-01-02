$NetBSD$

use install prefix

--- mindforger.pro.orig	2020-03-08 19:20:59.000000000 +0000
+++ mindforger.pro
@@ -43,20 +43,20 @@ app.depends = lib
 #IMPORTANT: binfile MUST be specified in app/app.pro (project next to/that builds binary)
 
 docfiles.files += doc/*
-docfiles.path = /usr/share/doc/mindforger/
+docfiles.path = $$(PREFIX)/share/doc/mindforger/
 INSTALLS += docfiles
 
 manfiles.files += man/*
-manfiles.path = /usr/share/man/man1/
+manfiles.path = $$(PREFIX)/man/man1/
 INSTALLS += manfiles
 
 iconfiles.files += app/resources/icons/*
-iconfiles.path = /usr/share/icons/mindforger/
+iconfiles.path = $$(PREFIX)/share/icons/mindforger/
 INSTALLS += iconfiles
 
 # experiment w/ file
 shortcutfiles.files += app/resources/gnome-shell/mindforger.desktop
-shortcutfiles.path = /usr/share/applications/
+shortcutfiles.path = $$(PREFIX)/share/applications/
 INSTALLS += shortcutfiles
 
 # eof
