$NetBSD$

From pull request https://github.com/TurningWheel/Barony/pull/582.

From c07db95221606e88b58908fee314cf1e8d14bb6a Mon Sep 17 00:00:00 2001
From: Sylvain
Date: Sat, 10 Apr 2021 21:33:29 +0200
Subject: [PATCH 1/3] Fixed bug 580 - Use 'userdata' instead of 'refcount'
 'refcount' is a private SDL_Surface field

diff --git a/src/opengl.cpp b/src/opengl.cpp
index f5b81e77a..3ac225825 100644
--- src/opengl.cpp
+++ src/opengl.cpp
@@ -500,7 +500,7 @@ void glDrawSprite(view_t* camera, Entity* entity, int mode)
 	}
 	if ( mode == REALCOLORS )
 	{
-		glBindTexture(GL_TEXTURE_2D, texid[sprite->refcount]);
+		glBindTexture(GL_TEXTURE_2D, texid[(long int)sprite->userdata]);
 	}
 	else
 	{
@@ -586,7 +586,7 @@ void glDrawSpriteFromImage(view_t* camera, Entity* entity, std::string text, int
 	//int x, y;
 	real_t s = 1;
 	SDL_Surface* image = sprites[0];
-	GLuint textureId = texid[sprites[0]->refcount];
+	GLuint textureId = texid[(long int)sprites[0]->userdata];
 	char textToRetrieve[128];
 
 	if ( text.compare("") == 0 )
@@ -603,7 +603,7 @@ void glDrawSpriteFromImage(view_t* camera, Entity* entity, std::string text, int
 	textToRetrieve[std::min(static_cast<int>(strlen(text.c_str())), 22)] = '\0';
 	if ( (image = ttfTextHashRetrieve(ttfTextHash, textToRetrieve, ttf12, true)) != NULL )
 	{
-		textureId = texid[image->refcount];
+		textureId = texid[(long int)image->userdata];
 	}
 	else
 	{
@@ -627,7 +627,7 @@ void glDrawSpriteFromImage(view_t* camera, Entity* entity, std::string text, int
 		SDL_BlitSurface(textSurf, NULL, image, &pos);
 		// load the text outline surface as a GL texture
 		allsurfaces[imgref] = image;
-		allsurfaces[imgref]->refcount = imgref;
+		allsurfaces[imgref]->userdata = (void *)((long int)imgref);
 		glLoadTexture(allsurfaces[imgref], imgref);
 		imgref++;
 		// store the surface in the text surface cache
@@ -635,7 +635,7 @@ void glDrawSpriteFromImage(view_t* camera, Entity* entity, std::string text, int
 		{
 			printlog("warning: failed to store text outline surface with imgref %d\n", imgref - 1);
 		}
-		textureId = texid[image->refcount];
+		textureId = texid[(long int)image->userdata];
 	}
 	// setup projection
 	glMatrixMode(GL_PROJECTION);
@@ -864,7 +864,7 @@ void glDrawWorld(view_t* camera, int mode)
 
 		// first (higher) sky layer
 		glColor4f(1.f, 1.f, 1.f, .5);
-		glBindTexture(GL_TEXTURE_2D, texid[tiles[cloudtile]->refcount]); // sky tile
+		glBindTexture(GL_TEXTURE_2D, texid[(long int)tiles[cloudtile]->userdata]); // sky tile
 		glBegin( GL_QUADS );
 		glTexCoord2f((real_t)(ticks % 60) / 60, (real_t)(ticks % 60) / 60);
 		glVertex3f(-CLIPFAR * 16, 64, -CLIPFAR * 16);
@@ -881,7 +881,7 @@ void glDrawWorld(view_t* camera, int mode)
 
 		// second (closer) sky layer
 		glColor4f(1.f, 1.f, 1.f, .5);
-		glBindTexture(GL_TEXTURE_2D, texid[tiles[cloudtile]->refcount]); // sky tile
+		glBindTexture(GL_TEXTURE_2D, texid[(long int)tiles[cloudtile]->userdata]); // sky tile
 		glBegin( GL_QUADS );
 		glTexCoord2f((real_t)(ticks % 240) / 240, (real_t)(ticks % 240) / 240);
 		glVertex3f(-CLIPFAR * 16, 32, -CLIPFAR * 16);
@@ -954,13 +954,13 @@ void glDrawWorld(view_t* camera, int mode)
 						{
 							if ( map.tiles[index] < 0 || map.tiles[index] >= numtiles )
 							{
-								new_tex = texid[sprites[0]->refcount];
-								//glBindTexture(GL_TEXTURE_2D, texid[sprites[0]->refcount]);
+								new_tex = texid[(long int)sprites[0]->userdata];
+								//glBindTexture(GL_TEXTURE_2D, texid[(long int)sprites[0]->userdata]);
 							}
 							else
 							{
-								new_tex = texid[tiles[map.tiles[index]]->refcount];
-								//glBindTexture(GL_TEXTURE_2D, texid[tiles[map.tiles[index]]->refcount]);
+								new_tex = texid[(long int)tiles[map.tiles[index]]->userdata];
+								//glBindTexture(GL_TEXTURE_2D, texid[(long int)tiles[map.tiles[index]]->userdata]);
 							}
 						}
 						else
@@ -1282,8 +1282,8 @@ void glDrawWorld(view_t* camera, int mode)
 						// bind texture
 						if ( mode == REALCOLORS )
 						{
-							new_tex = texid[tiles[mapceilingtile]->refcount];
-							//glBindTexture(GL_TEXTURE_2D, texid[tiles[50]->refcount]); // rock tile
+							new_tex = texid[(long int)tiles[mapceilingtile]->userdata];
+							//glBindTexture(GL_TEXTURE_2D, texid[(long int)tiles[50]->userdata]); // rock tile
 							if (cur_tex!=new_tex)
 							{
 								glEnd();
