$NetBSD: patch-Swiften_Compress_ZLibCompressor.cpp,v 1.2 2013/07/07 11:42:58 thomasklausner Exp $

--- Swiften/Compress/ZLibCompressor.cpp.orig	2012-12-22 12:23:59.000000000 +0000
+++ Swiften/Compress/ZLibCompressor.cpp
@@ -11,8 +11,6 @@
 
 #include <Swiften/Compress/ZLibCodecompressor_Private.h>
 
-#pragma GCC diagnostic ignored "-Wold-style-cast"
-
 namespace Swift {
 
 ZLibCompressor::ZLibCompressor() {
