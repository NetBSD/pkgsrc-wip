$NetBSD$

--- src/pokerth_server.cpp.orig	2016-08-07 01:13:51.000000000 +0000
+++ src/pokerth_server.cpp
@@ -161,7 +161,7 @@ main(int argc, char *argv[])
 		pidFile = tmpPidPath.directory_string();
 	}
 	{
-		ofstream pidStream(pidFile.c_str(), ios_base::out | ios_base::trunc);
+		boost::filesystem::ofstream pidStream(pidFile.c_str(), ios_base::out | ios_base::trunc);
 		if (!pidStream.fail())
 			pidStream << getpid();
 		else
