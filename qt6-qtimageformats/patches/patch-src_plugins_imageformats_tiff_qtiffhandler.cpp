$NetBSD$

Don't use deprecated APIs, from upstream
https://code.qt.io/cgit/qt/qtimageformats.git/commit/?id=183e8d70a7a12f99c5a0853d7dae0026e74a91b1

--- src/plugins/imageformats/tiff/qtiffhandler.cpp.orig	2021-02-07 12:11:27.458967159 +0000
+++ src/plugins/imageformats/tiff/qtiffhandler.cpp
@@ -835,7 +835,7 @@ QVariant QTiffHandler::option(ImageOptio
 
 void QTiffHandler::setOption(ImageOption option, const QVariant &value)
 {
-    if (option == CompressionRatio && value.type() == QVariant::Int)
+    if (option == CompressionRatio && value.metaType().id() == QMetaType::Int)
         d->compression = qBound(0, value.toInt(), 1);
     if (option == ImageTransformation) {
         int transformation = value.toInt();
