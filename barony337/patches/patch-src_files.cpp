$NetBSD$

From pull request https://github.com/TurningWheel/Barony/pull/582.

From c07db95221606e88b58908fee314cf1e8d14bb6a Mon Sep 17 00:00:00 2001
From: Sylvain
Date: Sat, 10 Apr 2021 21:33:29 +0200
Subject: [PATCH 1/3] Fixed bug 580 - Use 'userdata' instead of 'refcount'
 'refcount' is a private SDL_Surface field

diff --git a/src/files.cpp b/src/files.cpp
index 2beb9a6b9..389ade6d1 100644

From cf95fc1519465d0391d55e86624f10f8d0cf65de Mon Sep 17 00:00:00 2001
From: Sylvain
Date: Sat, 10 Apr 2021 21:34:27 +0200
Subject: [PATCH 2/3] Fixed bug 580 - use 'imgref' and not 'imgref + 1'

diff --git a/src/files.cpp b/src/files.cpp
index 389ade6d1..d37f98398 100644

--- src/files.cpp
+++ src/files.cpp
@@ -591,7 +591,7 @@ SDL_Surface* loadImage(char const * const filename)
 
 	// load the new surface as a GL texture
 	allsurfaces[imgref] = newSurface;
-	allsurfaces[imgref]->refcount = imgref + 1;
+	allsurfaces[imgref]->userdata = (void *)(imgref);
 	glLoadTexture(allsurfaces[imgref], imgref);
 
 	// free the translated surface
