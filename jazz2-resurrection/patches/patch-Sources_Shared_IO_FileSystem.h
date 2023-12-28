$NetBSD$

Use the same filesystem implementation as FreeBSD for *BSD.

--- Sources/Shared/IO/FileSystem.h.orig	2023-12-27 16:49:46.047651610 +0000
+++ Sources/Shared/IO/FileSystem.h
@@ -16,7 +16,7 @@
 #	elif defined(DEATH_TARGET_ANDROID)
 using DIR = struct DIR;
 using AAssetDir = struct AAssetDir;
-#	elif defined(__FreeBSD__)
+#	elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 struct _dirdesc;
 using DIR = struct _dirdesc;
 #	else
@@ -273,4 +273,4 @@ namespace Death { namespace IO {
 	};
 
 	using fs = FileSystem;
-}}
\ No newline at end of file
+}}
