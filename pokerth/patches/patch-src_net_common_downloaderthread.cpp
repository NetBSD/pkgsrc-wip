$NetBSD$

--- src/net/common/downloaderthread.cpp.orig	2016-08-06 11:09:13.000000000 +0000
+++ src/net/common/downloaderthread.cpp
@@ -96,7 +96,7 @@ DownloaderThread::Main()
 				// Previous download was finished.
 				if (m_curDownloadData) {
 					path filepath(m_curDownloadData->filename);
-					ifstream instream(filepath.file_string().c_str(), ios_base::in | ios_base::binary);
+					boost::filesystem::ifstream instream(filepath.file_string().c_str(), ios_base::in | ios_base::binary);
 					// Find out file size.
 					// Not fully portable, but works on win/linux/mac.
 					instream.seekg(0, ios_base::beg);
