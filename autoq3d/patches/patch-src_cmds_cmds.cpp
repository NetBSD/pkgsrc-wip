$NetBSD: patch-src_cmds_cmds.cpp,v 1.1 2012/09/26 22:45:13 othyro Exp $

QColor needs to be called directly.

--- src/cmds/cmds.cpp.orig	2010-06-06 21:25:30.000000000 +0000
+++ src/cmds/cmds.cpp
@@ -89,9 +89,9 @@ cmds::cmds( QWidget* parent)
 
 
 	QPalette newPalette = QPalette();
-	newPalette.setColor(QPalette::Background, QColor::QColor(170,170,255));
-	newPalette.setColor(QPalette::Foreground, QColor::QColor(0,0,0));
-	newPalette.setColor(QPalette::Base, QColor::QColor(170,170,255));
+	newPalette.setColor(QPalette::Background, QColor(170,170,255));
+	newPalette.setColor(QPalette::Foreground, QColor(0,0,0));
+	newPalette.setColor(QPalette::Base, QColor(170,170,255));
 
 	setPalette(newPalette);
 	
