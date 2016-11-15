$NetBSD$

--- src/Path.cpp.orig	2016-03-23 11:25:18.000000000 +0000
+++ src/Path.cpp
@@ -237,7 +237,7 @@ Path fetchDataPath()
 	}
 	else
 	{
-		pathStream << ":/usr/local/share:/usr/share";
+		pathStream << ":/usr/pkg/share:/usr/local/share:/usr/share";
 	}
 	
 	std::string strPath;
