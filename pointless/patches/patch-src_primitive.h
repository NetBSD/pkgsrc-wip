$NetBSD: patch-src_primitive.h,v 1.1 2012/03/06 23:37:42 minskim Exp $

--- src/primitive.h.orig	2003-05-20 21:04:02.000000000 +0000
+++ src/primitive.h
@@ -106,7 +106,7 @@ friend class TiledTexture;
 public:
 	typedef Ref<Tile> handle;
 	~Tile();
-	TiledTexture* get_texture() const { // Making this const is a HACK
+	class TiledTexture* get_texture() const { // Making this const is a HACK
 		return _texture; } 
 	void copy_from_subimage(Image *img, uint xoffset, uint yoffset);
 private:
