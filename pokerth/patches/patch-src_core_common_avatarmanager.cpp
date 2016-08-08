$NetBSD$

--- src/core/common/avatarmanager.cpp.orig	2016-08-06 11:04:30.000000000 +0000
+++ src/core/common/avatarmanager.cpp
@@ -61,7 +61,7 @@ using namespace std;
 using namespace boost::filesystem;
 
 struct AvatarFileState {
-	ifstream		inputStream;
+	boost::filesystem::ifstream		inputStream;
 };
 
 AvatarManager::AvatarManager(bool useExternalServer, const std::string &externalServerAddress,
@@ -363,7 +363,7 @@ AvatarManager::StoreAvatarInCache(const 
 				path tmpPath(cacheDir);
 				tmpPath /= (md5buf.ToString() + ext);
 				string fileName(tmpPath.file_string());
-				ofstream o(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
+				boost::filesystem::ofstream o(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
 				if (!o.fail()) {
 					o.write((const char *)data, size);
 					o.close();
