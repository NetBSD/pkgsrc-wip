$NetBSD$

--- source/graphics/TextureConverter.cpp.orig	2015-06-07 21:56:52.000000000 +0000
+++ source/graphics/TextureConverter.cpp
@@ -45,6 +45,10 @@ struct BufferOutputHandler : public nvtt
 	{
 	}
 
+	virtual void endImage()
+	{
+	}
+
 	virtual bool writeData(const void* data, int size)
 	{
 		size_t off = buffer.size();
