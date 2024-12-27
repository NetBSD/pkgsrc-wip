$NetBSD$

Sys_ListFilteredFiles is called with a "const char *" argument for
the filter argument which results in a compile time error. The filter
is not modified in the function, so give it a const type as well.

--- code/sys/sys_unix.c.orig	2024-12-27 08:53:06.275829131 +0000
+++ code/sys/sys_unix.c
@@ -370,7 +370,7 @@ Sys_ListFilteredFiles
 ==================
 */
 void Sys_ListFilteredFiles(
-    const char *basedir, char *subdirs, char *filter, qboolean wantsubs, char **list, int *numfiles
+    const char *basedir, char *subdirs, const char *filter, qboolean wantsubs, char **list, int *numfiles
 )
 {
     char           search[MAX_OSPATH], newsubdirs[MAX_OSPATH];
