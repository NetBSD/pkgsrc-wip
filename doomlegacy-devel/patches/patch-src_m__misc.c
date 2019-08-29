$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

--- src/m_misc.c.orig	2019-08-21 09:16:46.000000000 +0000
+++ src/m_misc.c
@@ -713,14 +713,14 @@ boolean Write_PCXfile ( const char * fil
     pcx->xmin = 0;
     pcx->ymin = 0;
     // [WDJ] The PCX format must be little-endian, must swap when big-endian
-    pcx->xmax = LE_SWAP16(width-1);
-    pcx->ymax = LE_SWAP16(height-1);
-    pcx->hres = LE_SWAP16(width);
-    pcx->vres = LE_SWAP16(height);
+    pcx->xmax = (uint16_t)( LE_SWAP16(width-1) );
+    pcx->ymax = (uint16_t)( LE_SWAP16(height-1) );
+    pcx->hres = (uint16_t)( LE_SWAP16(width) );
+    pcx->vres = (uint16_t)( LE_SWAP16(height) );
     memset (pcx->palette,0,sizeof(pcx->palette));
     pcx->color_planes = 1;              // chunky image
-    pcx->bytes_per_line = LE_SWAP16(width);
-    pcx->palette_type = LE_SWAP16(1);   // Color (2=grey scale)
+    pcx->bytes_per_line = (uint16_t)( LE_SWAP16(width) );
+    pcx->palette_type = (uint16_t)( LE_SWAP16(1) );   // Color (2=grey scale)
     memset (pcx->filler,0,sizeof(pcx->filler));
 
 
@@ -788,8 +788,8 @@ boolean  Write_TGA( const char * filenam
 
     memset(&tga_hdr, 0, sizeof(tga_hdr));
     // TGA format is little-endian
-    tga_hdr.width = LE_SWAP16(width);
-    tga_hdr.height = LE_SWAP16(height);
+    tga_hdr.width = (uint16_t)( LE_SWAP16(width) );
+    tga_hdr.height = (uint16_t)( LE_SWAP16(height) );
     tga_hdr.image_pix_size = bitpp;  // normal, 24 bits per pixel
     tga_hdr.image_type = 2;  // Uncompressed, RGB
     tga_hdr.image_descriptor = 0x20;  // bit 5, origin in upper left-hand corner
