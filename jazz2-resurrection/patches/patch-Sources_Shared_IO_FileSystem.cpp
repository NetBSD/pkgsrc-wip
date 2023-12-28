$NetBSD$

dirfd is a macro on NetBSD.

--- Sources/Shared/IO/FileSystem.cpp.orig	2023-12-27 16:51:40.578784448 +0000
+++ Sources/Shared/IO/FileSystem.cpp
@@ -351,7 +351,7 @@ namespace Death { namespace IO {
 				return;
 			}
 
-			std::int32_t dfd = ::dirfd(d);
+			std::int32_t dfd = dirfd(d);
 			struct dirent* ent;
 			while ((ent = ::readdir(d)) != nullptr) {
 				if (ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
