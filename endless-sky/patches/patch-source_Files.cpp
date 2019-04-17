$NetBSD$

Also test for NetBSD.
Search for data in installation path.

--- source/Files.cpp.orig	2015-12-14 04:39:54.000000000 +0000
+++ source/Files.cpp
@@ -105,12 +105,12 @@ void Files::Init(const char * const *arg
 #endif
 	if(resources.back() != '/')
 		resources += '/';
-#if defined __linux__ || defined __FreeBSD__ || defined __DragonFly__
+#if defined __linux__ || defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__
 	// Special case, for Linux: the resource files are not in the same place as
 	// the executable, but are under the same prefix (/usr or /usr/local).
 	static const string LOCAL_PATH = "/usr/local/";
-	static const string STANDARD_PATH = "/usr/";
-	static const string RESOURCE_PATH = "share/games/endless-sky/";
+	static const string STANDARD_PATH = "@PREFIX@/";
+	static const string RESOURCE_PATH = "share/endless-sky/";
 	if(!resources.compare(0, LOCAL_PATH.length(), LOCAL_PATH))
 		resources = LOCAL_PATH + RESOURCE_PATH;
 	else if(!resources.compare(0, STANDARD_PATH.length(), STANDARD_PATH))
