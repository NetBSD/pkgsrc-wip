$NetBSD$

--- src/net/common/clientstate.cpp.orig	2016-08-07 01:05:43.000000000 +0000
+++ src/net/common/clientstate.cpp
@@ -302,8 +302,8 @@ ClientStateReadingServerList::Enter(boos
 
 		// Unzip the file using zlib.
 		try {
-			ifstream inFile(zippedServerListPath.directory_string().c_str(), ios_base::in | ios_base::binary);
-			ofstream outFile(xmlServerListPath.directory_string().c_str(), ios_base::out | ios_base::trunc);
+			boost::filesystem::ifstream inFile(zippedServerListPath.directory_string().c_str(), ios_base::in | ios_base::binary);
+			boost::filesystem::ofstream outFile(xmlServerListPath.directory_string().c_str(), ios_base::out | ios_base::trunc);
 			boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
 			in.push(boost::iostreams::zlib_decompressor());
 			in.push(inFile);
