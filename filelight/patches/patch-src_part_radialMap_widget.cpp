$NetBSD: patch-src_part_radialMap_widget.cpp,v 1.1 2011/02/17 10:10:20 mwdavies Exp $

Fix build with gcc4.5

--- src/part/radialMap/widget.cpp.orig	2009-05-29 18:35:06.000000000 +0000
+++ src/part/radialMap/widget.cpp
@@ -64,7 +64,7 @@ RadialMap::Widget::path() const
 KUrl
 RadialMap::Widget::url(File const * const file) const
 {
-    return KUrl::KUrl(file ? file->fullPath() : m_tree->fullPath());
+    return KUrl(file ? file->fullPath() : m_tree->fullPath());
 }
 
 void
