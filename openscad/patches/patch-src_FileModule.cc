$NetBSD$

Fix for new boost version.

--- src/FileModule.cc.orig	2024-07-04 04:00:45.934748369 +0000
+++ src/FileModule.cc
@@ -65,7 +65,7 @@ void FileModule::registerUse(const std::
 	auto ext = fs::path(path).extension().generic_string();
 
 	if (boost::iequals(ext, ".otf") || boost::iequals(ext, ".ttf")) {
-		if (fs::is_regular(path)) {
+		if (fs::is_regular_file(path)) {
 			FontCache::instance()->register_font_file(path);
 		} else {
 			LOG(message_group::Error,Location::NONE,"","Can't read font with path '%1$s'",path);
