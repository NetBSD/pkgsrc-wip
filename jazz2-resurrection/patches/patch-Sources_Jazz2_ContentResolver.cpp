$NetBSD$

Use ASCII path names.

--- Sources/Jazz2/ContentResolver.cpp.orig	2023-12-28 07:23:40.687240109 +0000
+++ Sources/Jazz2/ContentResolver.cpp
@@ -218,10 +218,10 @@ namespace Jazz2
 			// Shared Content exists, try to use standard XDG paths
 			auto localStorage = fs::GetLocalStorage();
 			if (!localStorage.empty()) {
-				// Use "$XDG_DATA_HOME/Jazz² Resurrection/" if exists (for backward compatibility), otherwise "$XDG_DATA_HOME/{NCINE_LINUX_PACKAGE}/"
-				_sourcePath = fs::CombinePath(localStorage, "Jazz² Resurrection/Source/"_s);
+				// Use "$XDG_DATA_HOME/Jazz2-Resurrection/" if exists (for backward compatibility), otherwise "$XDG_DATA_HOME/{NCINE_LINUX_PACKAGE}/"
+				_sourcePath = fs::CombinePath(localStorage, "Jazz2-Resurrection/Source/"_s);
 				if (fs::DirectoryExists(_sourcePath)) {
-					_cachePath = fs::CombinePath(localStorage, "Jazz² Resurrection/Cache/"_s);
+					_cachePath = fs::CombinePath(localStorage, "Jazz2-Resurrection/Cache/"_s);
 				} else {
 					auto appData = fs::CombinePath(localStorage, NCINE_LINUX_PACKAGE);
 					_sourcePath = fs::CombinePath(appData, "Source/"_s);
@@ -1705,4 +1705,4 @@ namespace Jazz2
 		}
 	}
 #endif
-}
\ No newline at end of file
+}
