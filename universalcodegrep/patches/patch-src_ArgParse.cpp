$NetBSD$

https://github.com/gvansickle/ucg/issues/96

--- src/ArgParse.cpp.orig	2016-04-11 00:11:55.000000000 +0000
+++ src/ArgParse.cpp
@@ -663,6 +663,7 @@ std::string ArgParse::GetProjectRCFilena
 	char *current_cwd = original_cwd;
 	while((current_cwd != nullptr) && (current_cwd[0] != '.'))
 	{
+		char *prev_cwd;
 		// If we were able to get a file descriptor to $HOME above...
 		if(home_fd != -1)
 		{
@@ -710,7 +711,9 @@ std::string ArgParse::GetProjectRCFilena
 		}
 
 		// Go up one directory.
-		current_cwd = dirname(current_cwd);
+		prev_cwd = strdup(current_cwd);
+		current_cwd = dirname(prev_cwd);
+		free(prev_cwd);
 	}
 
 	// Free the cwd string.
