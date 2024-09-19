$NetBSD: patch-src_irrXML.cpp,v 1.1 2012/11/02 23:51:45 othyro Exp $

Fixes bug if filesize is 0.

--- src/irrXML.cpp.orig	2005-08-20 21:17:54.000000000 +0000
+++ src/irrXML.cpp
@@ -83,7 +83,9 @@ private:
 //! Creates an instance of an UFT-8 or ASCII character xml parser. 
 IrrXMLReader* createIrrXMLReader(const char* filename)
 {
-	return new CXMLReaderImpl<char, IXMLBase>(new CFileReadCallBack(filename)); 
+	CFileReadCallBack* file = new CFileReadCallBack(filename);
+	if (file->getSize() == 0) return NULL;
+	return new CXMLReaderImpl<char, IXMLBase>(file);
 }
 
 
