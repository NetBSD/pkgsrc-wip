$NetBSD$

From pull request https://github.com/TurningWheel/Barony/pull/582.

From c07db95221606e88b58908fee314cf1e8d14bb6a Mon Sep 17 00:00:00 2001
From: Sylvain
Date: Sat, 10 Apr 2021 21:33:29 +0200
Subject: [PATCH 1/3] Fixed bug 580 - Use 'userdata' instead of 'refcount'
 'refcount' is a private SDL_Surface field

diff --git a/src/draw.cpp b/src/draw.cpp
index 08f95343f..4e62c751a 100644
--- src/draw.cpp
+++ src/draw.cpp
@@ -443,7 +443,7 @@ void drawImageRotatedAlpha( SDL_Surface* image, SDL_Rect* src, SDL_Rect* pos, re
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	glColor4f(1, 1, 1, alpha / 255.1);
 	glBegin(GL_QUADS);
 	glTexCoord2f(1.0 * ((real_t)src->x / image->w), 1.0 * ((real_t)src->y / image->h));
@@ -492,7 +492,7 @@ void drawImageColor( SDL_Surface* image, SDL_Rect* src, SDL_Rect* pos, Uint32 co
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	real_t r = ((Uint8)(color >> mainsurface->format->Rshift)) / 255.f;
 	real_t g = ((Uint8)(color >> mainsurface->format->Gshift)) / 255.f;
 	real_t b = ((Uint8)(color >> mainsurface->format->Bshift)) / 255.f;
@@ -546,7 +546,7 @@ void drawImageAlpha( SDL_Surface* image, SDL_Rect* src, SDL_Rect* pos, Uint8 alp
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	glColor4f(1, 1, 1, alpha / 255.1);
 	glPushMatrix();
 	glBegin(GL_QUADS);
@@ -596,7 +596,7 @@ void drawImage( SDL_Surface* image, SDL_Rect* src, SDL_Rect* pos )
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	glColor4f(1, 1, 1, 1);
 	glPushMatrix();
 	glBegin(GL_QUADS);
@@ -646,7 +646,7 @@ void drawImageRing(SDL_Surface* image, SDL_Rect* src, int radius, int thickness,
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	glColor4f(1, 1, 1, alpha / 255.f);
 	glPushMatrix();
 
@@ -771,7 +771,7 @@ void drawImageScaled( SDL_Surface* image, SDL_Rect* src, SDL_Rect* pos )
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	glColor4f(1, 1, 1, 1);
 	glPushMatrix();
 	glBegin(GL_QUADS);
@@ -826,7 +826,7 @@ void drawImageScaledPartial(SDL_Surface* image, SDL_Rect* src, SDL_Rect* pos, fl
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	glColor4f(1, 1, 1, 1);
 	glPushMatrix();
 	glBegin(GL_QUADS);
@@ -889,7 +889,7 @@ void drawImageScaledColor(SDL_Surface* image, SDL_Rect* src, SDL_Rect* pos, Uint
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	real_t r = ((Uint8)(color >> mainsurface->format->Rshift)) / 255.f;
 	real_t g = ((Uint8)(color >> mainsurface->format->Gshift)) / 255.f;
 	real_t b = ((Uint8)(color >> mainsurface->format->Bshift)) / 255.f;
@@ -985,7 +985,7 @@ void drawImageFancy( SDL_Surface* image, Uint32 color, real_t angle, SDL_Rect* s
 	}
 
 	// draw a textured quad
-	glBindTexture(GL_TEXTURE_2D, texid[image->refcount]);
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)image->userdata]);
 	real_t r = ((Uint8)(color >> mainsurface->format->Rshift)) / 255.f;
 	real_t g = ((Uint8)(color >> mainsurface->format->Gshift)) / 255.f;
 	real_t b = ((Uint8)(color >> mainsurface->format->Bshift)) / 255.f;
@@ -2186,7 +2186,7 @@ void drawWindowFancy(int x1, int y1, int x2, int y2)
 	glVertex2f(x2 - 1, yres - y1 - 1);
 	glEnd();
 	glColor3f(.75, .75, .75);
-	glBindTexture(GL_TEXTURE_2D, texid[fancyWindow_bmp->refcount]); // wood texture
+	glBindTexture(GL_TEXTURE_2D, texid[(long int)fancyWindow_bmp->userdata]); // wood texture
 	glBegin(GL_QUADS);
 	glTexCoord2f(0, 0);
 	glVertex2f(x1 + 2, yres - y1 - 2);
@@ -2322,7 +2322,7 @@ SDL_Rect ttfPrintTextColor( TTF_Font* font, int x, int y, Uint32 color, bool out
 		SDL_BlitSurface(textSurf, NULL, surf, &pos);
 		// load the text outline surface as a GL texture
 		allsurfaces[imgref] = surf;
-		allsurfaces[imgref]->refcount = imgref;
+		allsurfaces[imgref]->userdata = (void*) imgref;
 		glLoadTexture(allsurfaces[imgref], imgref);
 		imgref++;
 		// store the surface in the text surface cache
