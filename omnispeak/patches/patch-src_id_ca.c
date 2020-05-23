$NetBSD$

Search for data files in PREFIX.

--- src/id_ca.c.orig	2020-05-04 04:33:47.000000000 +0000
+++ src/id_ca.c
@@ -31,6 +31,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include "ck_def.h"
 #include "ck_ep.h"
 
+#include <limits.h>
 #include <stdio.h>
 #include <string.h>
 #ifdef WITH_SDL
@@ -85,6 +86,25 @@ bool CAL_AdjustFilenameCase(char *filena
 
 	// We didn't find a matching file.
 	closedir(currentDirPtr);
+
+	currentDirPtr = opendir("@@PKGSRC_DATA_DIR@@");
+
+	// Search the current directory for matching names.
+	for (struct dirent *dirEntry = readdir(currentDirPtr); dirEntry; dirEntry = readdir(currentDirPtr))
+	{
+		if (!CK_Cross_strcasecmp(dirEntry->d_name, filename))
+		{
+			strncpy(filename, "@@PKGSRC_DATA_DIR@@", PATH_MAX);
+			strncat(filename, "/", PATH_MAX);
+			strncat(filename, dirEntry->d_name, PATH_MAX);
+			closedir(currentDirPtr);
+			return true;
+		}
+	}
+
+	// We didn't find a matching file.
+	closedir(currentDirPtr);
+
 	return false;
 }
 #else
@@ -164,7 +184,7 @@ void (*ca_finishCacheBox)(void);
 // Does a file exist (with filename case correction)
 bool CA_IsFilePresent(const char *filename)
 {
-	static char newname[16];
+	static char newname[PATH_MAX];
 	strcpy(newname, filename);
 	if (!CAL_AdjustFilenameCase(newname))
 	{
@@ -178,7 +198,7 @@ bool CA_IsFilePresent(const char *filena
 // valid until the NEXT invocation of this function.
 char *CAL_AdjustExtension(const char *filename)
 {
-	static char newname[16];
+	static char newname[PATH_MAX];
 	strcpy(newname, filename);
 	size_t fnamelen = strlen(filename);
 	newname[fnamelen - 3] = ck_currentEpisode->ext[0];
