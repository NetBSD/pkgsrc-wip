$NetBSD$

Use ASCII path names.

--- Sources/Jazz2/PreferencesCache.cpp.orig	2023-12-28 09:40:01.466044378 +0000
+++ Sources/Jazz2/PreferencesCache.cpp
@@ -103,7 +103,7 @@ namespace Jazz2
 #	elif defined(DEATH_TARGET_UNIX) && defined(NCINE_PACKAGED_CONTENT_PATH)
 			_configPath = fs::CombinePath(fs::GetSavePath(NCINE_LINUX_PACKAGE), "Jazz2.config"_s);
 #	else
-			_configPath = fs::CombinePath(fs::GetSavePath("Jazz² Resurrection"_s), "Jazz2.config"_s);
+			_configPath = fs::CombinePath(fs::GetSavePath("Jazz2-Resurrection"_s), "Jazz2.config"_s);
 #	endif
 
 #	if defined(DEATH_TARGET_ANDROID)
@@ -487,4 +487,4 @@ namespace Jazz2
 			}
 		}
 	}
-}
\ No newline at end of file
+}
