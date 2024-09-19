$NetBSD$


--- src/XHTMLR.cpp.orig	2012-06-26 10:46:34.000000000 -0500
+++ src/XHTMLR.cpp	2014-02-05 20:50:06.000000000 -0600
@@ -64,7 +64,7 @@
 	std::string humanReadableKey = key;
 	BasicLatin::segmentize(humanReadableKey);
 	
-	_ss << "<" << _keyValuePairTag << " class=\"" << key << "\">" << humanReadableKey << ": " << value << "</" << _keyValuePairTag << ">" << std::endl;
+	_ss << "<" << _keyValuePairTag << " class=\"" << key << "\">" << "<span class=\"key\">" << humanReadableKey << "</span>: <span class=\"val\">" << value << "</span></" << _keyValuePairTag << ">" << std::endl;
 	
 }
 
