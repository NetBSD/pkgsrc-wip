$NetBSD$

Support libheif 1.20.
https://invent.kde.org/graphics/krita/-/commit/6ad4fa68a9e1ce06fc884e34f3cedcdd4b9a2076

--- plugins/impex/heif/HeifImport.cpp.orig	2025-07-12 19:30:12.000000000 +0000
+++ plugins/impex/heif/HeifImport.cpp
@@ -214,6 +214,12 @@ KisImportExportErrorCode HeifImport::con
     HeifLock lock;
 #endif
 
+#if LIBHEIF_HAVE_VERSION(1, 20, 0)
+    using HeifStrideType = size_t;
+#else
+    using HeifStrideType = int;
+#endif
+
     // Wrap input stream into heif Reader object
     Reader_QIODevice reader(io);
 
@@ -387,8 +393,8 @@ KisImportExportErrorCode HeifImport::con
 
         if (heifChroma == heif_chroma_monochrome) {
             dbgFile << "monochrome heif file, bits:" << luma;
-            int strideG = 0;
-            int strideA = 0;
+            HeifStrideType strideG = 0;
+            HeifStrideType strideA = 0;
             const uint8_t *imgG = heifimage.get_plane(heif_channel_Y, &strideG);
             const uint8_t *imgA =
                 heifimage.get_plane(heif_channel_Alpha, &strideA);
@@ -409,10 +415,10 @@ KisImportExportErrorCode HeifImport::con
         } else if (heifChroma == heif_chroma_444) {
             dbgFile << "planar heif file, bits:" << luma;
 
-            int strideR = 0;
-            int strideG = 0;
-            int strideB = 0;
-            int strideA = 0;
+            HeifStrideType strideR = 0;
+            HeifStrideType strideG = 0;
+            HeifStrideType strideB = 0;
+            HeifStrideType strideA = 0;
             const uint8_t* imgR = heifimage.get_plane(heif_channel_R, &strideR);
             const uint8_t* imgG = heifimage.get_plane(heif_channel_G, &strideG);
             const uint8_t* imgB = heifimage.get_plane(heif_channel_B, &strideB);
@@ -439,7 +445,7 @@ KisImportExportErrorCode HeifImport::con
                                     displayNits,
                                     colorSpace);
         } else if (heifChroma == heif_chroma_interleaved_RGB || heifChroma == heif_chroma_interleaved_RGBA) {
-            int stride = 0;
+            HeifStrideType stride = 0;
             dbgFile << "interleaved SDR heif file, bits:" << luma;
 
             const uint8_t *img = heifimage.get_plane(heif_channel_interleaved, &stride);
@@ -461,7 +467,7 @@ KisImportExportErrorCode HeifImport::con
                                       colorSpace);
 
         } else if (heifChroma == heif_chroma_interleaved_RRGGBB_LE || heifChroma == heif_chroma_interleaved_RRGGBBAA_LE || heifChroma == heif_chroma_interleaved_RRGGBB_BE || heifChroma == heif_chroma_interleaved_RRGGBB_BE) {
-            int stride = 0;
+            HeifStrideType stride = 0;
             dbgFile << "interleaved HDR heif file, bits:" << luma;
 
             const uint8_t *img =
