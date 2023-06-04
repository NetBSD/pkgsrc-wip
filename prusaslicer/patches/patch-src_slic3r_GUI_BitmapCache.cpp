$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/BitmapCache.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/BitmapCache.cpp
@@ -68,7 +68,7 @@ wxBitmapBundle* BitmapCache::insert_bndl
     wxVector<wxBitmap> bitmaps;
 
     std::set<double> scales = {1.0};
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
 
 #ifdef __APPLE__
     scales.emplace(m_scale);
@@ -547,7 +547,7 @@ wxBitmapBundle BitmapCache::mksolid(size
     wxVector<wxBitmap> bitmaps;
 
     std::set<double> scales = { 1.0 };
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
 
 #ifdef __APPLE__
     scales.emplace(m_scale);
