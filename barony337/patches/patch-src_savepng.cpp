$NetBSD$

From pull request https://github.com/TurningWheel/Barony/pull/582.

From c07db95221606e88b58908fee314cf1e8d14bb6a Mon Sep 17 00:00:00 2001
From: Sylvain
Date: Sat, 10 Apr 2021 21:33:29 +0200
Subject: [PATCH 1/3] Fixed bug 580 - Use 'userdata' instead of 'refcount'
 'refcount' is a private SDL_Surface field

diff --git a/src/savepng.cpp b/src/savepng.cpp
index fa7a5d4e2..59e052a5c 100644
--- src/savepng.cpp
+++ src/savepng.cpp
@@ -59,7 +59,7 @@ SDL_Surface* SDL_PNGFormatAlpha(SDL_Surface* src)
 	/* NO-OP for images < 32bpp and 32bpp images that already have Alpha channel */
 	if (src->format->BitsPerPixel <= 24 || src->format->Amask)
 	{
-		src->refcount++;
+		src->userdata = (void *)((long int) src->userdata + 1);
 		return src;
 	}
 
