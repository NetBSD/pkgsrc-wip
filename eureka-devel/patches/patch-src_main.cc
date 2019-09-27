$NetBSD$

Add placeholder for pkgsrc PREFIX to beginning of search list.
Remove date to make builds reproducible (based on Debian patch).

--- src/main.cc.orig	2019-09-27 11:13:24.000000000 +0000
+++ src/main.cc
@@ -301,6 +301,7 @@ static void Determine_InstallPath(const 
 #else
 	static const char *prefixes[] =
 	{
+		"PKGSRC_PREFIX",
 		"/usr/local",
 		"/usr",
 		"/opt",
@@ -947,7 +948,7 @@ static void ShowHelp()
 
 static void ShowVersion()
 {
-	printf("Eureka version " EUREKA_VERSION " (" __DATE__ ")\n");
+	printf("Eureka version " EUREKA_VERSION " (Reproducible build)\n");
 
 	fflush(stdout);
 }
