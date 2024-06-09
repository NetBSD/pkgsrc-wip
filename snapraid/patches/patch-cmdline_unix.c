$NetBSD$

statfs() functions are deprecated since NetBSD 3.0. This patch
replaces them with statvfs().

--- cmdline/unix.c.orig	2024-06-09 07:14:40.831310334 +0000
+++ cmdline/unix.c
@@ -650,9 +650,9 @@ int fsinfo(const char* path, int* has_pe
 	const char* ptype;
 
 #if HAVE_STATFS
-	struct statfs st;
+	struct statvfs st;
 
-	if (statfs(path, &st) != 0) {
+	if (statvfs(path, &st) != 0) {
 		char dir[PATH_MAX];
 		char* slash;
 
@@ -674,7 +674,7 @@ int fsinfo(const char* path, int* has_pe
 			return -1;
 
 		*slash = 0;
-		if (statfs(dir, &st) != 0)
+		if (statvfs(dir, &st) != 0)
 			return -1;
 	}
 #endif
@@ -761,7 +761,7 @@ int fsinfo(const char* path, int* has_pe
 	ptype = "unknown";
 #endif
 
-	log_tag("statfs:%s: %s \n", ptype, path);
+	log_tag("statvfs:%s: %s \n", ptype, path);
 
 	return 0;
 }
