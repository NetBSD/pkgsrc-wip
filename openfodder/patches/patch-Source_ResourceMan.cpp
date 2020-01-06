$NetBSD$

Use PREFIX when searching for data.

--- Source/ResourceMan.cpp.orig	2019-12-31 20:48:13.000000000 +0000
+++ Source/ResourceMan.cpp
@@ -82,6 +82,7 @@ void cResourceMan::addDefaultDirs() {
 		addBaseDir(path + "/.local/share/");
 	}
 	addBaseDir("/usr/local/share/");
+	addBaseDir(OPENFODDER_DATADIR);
 #endif
 }
 
@@ -624,4 +625,4 @@ std::vector<std::string> cResourceMan::D
 	return results;
 }
 
-#endif
\ No newline at end of file
+#endif
