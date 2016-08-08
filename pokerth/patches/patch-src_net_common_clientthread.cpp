$NetBSD$

--- src/net/common/clientthread.cpp.orig	2016-08-06 11:06:56.000000000 +0000
+++ src/net/common/clientthread.cpp
@@ -1604,7 +1604,7 @@ void
 ClientThread::ReadSessionGuidFromFile()
 {
 	string guidFileName(GetContext().GetCacheDir() + TEMP_GUID_FILENAME);
-	ifstream guidStream(guidFileName.c_str(), ios::in | ios::binary);
+	boost::filesystem::ifstream guidStream(guidFileName.c_str(), ios::in | ios::binary);
 	if (guidStream.good()) {
 		std::vector<char> tmpGuid(CLIENT_GUID_SIZE);
 		guidStream.read(&tmpGuid[0], CLIENT_GUID_SIZE);
@@ -1616,7 +1616,7 @@ void
 ClientThread::WriteSessionGuidToFile() const
 {
 	string guidFileName(GetContext().GetCacheDir() + TEMP_GUID_FILENAME);
-	ofstream guidStream(guidFileName.c_str(), ios::out | ios::trunc | ios::binary);
+	boost::filesystem::ofstream guidStream(guidFileName.c_str(), ios::out | ios::trunc | ios::binary);
 	if (guidStream.good()) {
 		guidStream.write(GetContext().GetSessionGuid().c_str(), GetContext().GetSessionGuid().size());
 	}
