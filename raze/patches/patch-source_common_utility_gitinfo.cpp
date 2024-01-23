$NetBSD$

Don't return the git version (this is not a git checkout), use the 
VERSIONSTR instead.

--- source/common/utility/gitinfo.cpp.orig	2024-01-17 17:21:01.292994816 +0000
+++ source/common/utility/gitinfo.cpp
@@ -39,7 +39,7 @@
 
 const char *GetGitDescription()
 {
-	return GIT_DESCRIPTION;
+	return "\0";
 }
 
 const char *GetGitHash()
