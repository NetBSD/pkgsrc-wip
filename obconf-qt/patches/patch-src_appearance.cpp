$NetBSD: patch-src_appearance.cpp,v 1.1 2015/05/23 11:43:24 krytarowski Exp $

Cherry-picked upstream patch adding Qt5 support
https://github.com/lxde/obconf-qt/commit/49a4067c58711130848cf4a30a0c4eedead405ac

--- src/appearance.cpp.orig	2014-05-07 05:42:53.000000000 +0000
+++ src/appearance.cpp
@@ -79,7 +79,7 @@ void MainDialog::on_title_layout_textCha
   QByteArray layout;
   // omit unknown chars
   for(int i = 0; i < text.length(); ++i) {
-    char ch = text.at(i).toUpper().toAscii();
+    char ch = text.at(i).toUpper().toLatin1();
     if(strchr("NDSLIMC", ch))
       layout += ch;
   }
