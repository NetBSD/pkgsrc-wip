$NetBSD$

Support libheif 1.20.
https://invent.kde.org/graphics/krita/-/commit/6ad4fa68a9e1ce06fc884e34f3cedcdd4b9a2076

--- plugins/impex/heif/HeifExport.cpp.orig	2025-07-12 19:30:12.000000000 +0000
+++ plugins/impex/heif/HeifExport.cpp
@@ -137,6 +137,12 @@ KisImportExportErrorCode HeifExport::con
     HeifLock lock;
 #endif
 
+#if LIBHEIF_HAVE_VERSION(1, 20, 0)
+    using HeifStrideType = size_t;
+#else
+    using HeifStrideType = int;
+#endif
+
     KisImageSP image = document->savingImage();
     const KoColorSpace *cs = image->colorSpace();
 
@@ -250,10 +256,10 @@ KisImportExportErrorCode HeifExport::con
                 img.add_plane(heif_channel_G, width,height, 8);
                 img.add_plane(heif_channel_B, width,height, 8);
 
-                int strideR = 0;
-                int strideG = 0;
-                int strideB = 0;
-                int strideA = 0;
+                HeifStrideType strideR = 0;
+                HeifStrideType strideG = 0;
+                HeifStrideType strideB = 0;
+                HeifStrideType strideA = 0;
 
                 uint8_t *ptrR = img.get_plane(heif_channel_R, &strideR);
                 uint8_t *ptrG = img.get_plane(heif_channel_G, &strideG);
@@ -289,7 +295,7 @@ KisImportExportErrorCode HeifExport::con
                 img.create(width, height, heif_colorspace_RGB, chroma);
                 img.add_plane(heif_channel_interleaved, width, height, 12);
 
-                int stride = 0;
+                HeifStrideType stride = 0;
 
                 uint8_t *ptr = img.get_plane(heif_channel_interleaved, &stride);
 
@@ -330,8 +336,8 @@ KisImportExportErrorCode HeifExport::con
 
                 img.add_plane(heif_channel_Y, width, height, 8);
 
-                int strideG = 0;
-                int strideA = 0;
+                HeifStrideType strideG = 0;
+                HeifStrideType strideA = 0;
 
                 uint8_t *ptrG = img.get_plane(heif_channel_Y, &strideG);
                 uint8_t *ptrA = [&]() -> uint8_t * {
@@ -363,8 +369,8 @@ KisImportExportErrorCode HeifExport::con
 
                 img.add_plane(heif_channel_Y, width, height, 12);
 
-                int strideG = 0;
-                int strideA = 0;
+                HeifStrideType strideG = 0;
+                HeifStrideType strideA = 0;
 
                 uint8_t *ptrG = img.get_plane(heif_channel_Y, &strideG);
                 uint8_t *ptrA = [&]() -> uint8_t * {
