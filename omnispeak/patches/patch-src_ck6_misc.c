$NetBSD$

Part of a patch set to search for data files in PREFIX.

--- src/ck6_misc.c.orig	2017-07-15 21:27:56.000000000 +0000
+++ src/ck6_misc.c
@@ -27,6 +27,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include "ck_def.h"
 #include "ck_act.h"
 #include "ck6_ep.h"
+#include <limits.h>
 #include <stdio.h>
 
 CK_EpisodeDef *ck6_episode;
@@ -106,7 +107,7 @@ bool CK6_IsPresent()
 	if (!CA_IsFilePresent("AUDIO.CK6"))
 		return false;
 	
-	char egaGraphName[] = "EGAGRAPH.CK6";
+	char egaGraphName[PATH_MAX] = "EGAGRAPH.CK6";
 	CAL_AdjustFilenameCase(egaGraphName);
 	size_t egaGraphSize = CA_GetFileSize(egaGraphName);
 	if (egaGraphSize == 464662)
