$NetBSD: patch-src_backends_graphics.h,v 1.1 2014/02/22 12:17:46 thomasklausner Exp $

C++ does not allow > > except as operator.

--- src/backends/graphics.h.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/backends/graphics.h
@@ -289,12 +289,12 @@ public:
 	/*
 	 * Converts data (which is in RGB format) to the format internally used by cairo.
 	 */
-	static void convertBitmapToCairo(std::vector<uint8_t, reporter_allocator<uint8_t>>& data, uint8_t* inData, uint32_t width,
+	static void convertBitmapToCairo(std::vector<uint8_t, reporter_allocator<uint8_t> >& data, uint8_t* inData, uint32_t width,
 					 uint32_t height, size_t* dataSize, size_t* stride, bool rgb15);
 	/*
 	 * Converts data (which is in ARGB format) to the format internally used by cairo.
 	 */
-	static void convertBitmapWithAlphaToCairo(std::vector<uint8_t, reporter_allocator<uint8_t>>& data, uint8_t* inData, uint32_t width,
+	static void convertBitmapWithAlphaToCairo(std::vector<uint8_t, reporter_allocator<uint8_t> >& data, uint8_t* inData, uint32_t width,
 			uint32_t height, size_t* dataSize, size_t* stride);
 };
 
@@ -398,7 +398,7 @@ public:
 class SoftwareInvalidateQueue: public InvalidateQueue
 {
 public:
-	std::list<_R<DisplayObject>> queue;
+	std::list<_R<DisplayObject> > queue;
 	void addToInvalidateQueue(_R<DisplayObject> d);
 };
 
