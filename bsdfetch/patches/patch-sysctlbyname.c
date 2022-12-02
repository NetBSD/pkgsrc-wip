$NetBSD$

Simplify checking for sizeof sysctl names. 

--- sysctlbyname.c.orig	2022-11-30 09:00:21.000000000 +0000
+++ sysctlbyname.c
@@ -28,7 +28,7 @@ sysctlbyname(const char *name, void *old
 {
 	int i, mib[2];
 
-	for (i = 0; i < (int) (sizeof(sysctlnames) / sizeof(sysctlnames[0])); i++) {
+	for (i = 0; sysctlnames[i].name != NULL; i++) {
 		if (!strcmp(name, sysctlnames[i].name)) {
 			mib[0] = sysctlnames[i].mib0;
 			mib[1] = sysctlnames[i].mib1;
