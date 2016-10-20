$NetBSD$

--- src/init.cpp.orig	2015-09-28 15:49:30.000000000 +0000
+++ src/init.cpp
@@ -914,11 +914,13 @@ bool AppInit2(boost::thread_group& threa
                 boost::filesystem::path backupFile = backupPathStr + dateTimeStr;
                 sourceFile.make_preferred();
                 backupFile.make_preferred();
-                try {
-                    boost::filesystem::copy_file(sourceFile, backupFile);
-                    LogPrintf("Creating backup of %s -> %s\n", sourceFile, backupFile);
-                } catch(boost::filesystem::filesystem_error &error) {
-                    LogPrintf("Failed to create backup %s\n", error.what());
+		if(boost::filesystem::exists(sourceFile)) {
+                    try {
+                        boost::filesystem::copy_file(sourceFile, backupFile);
+                        LogPrintf("Creating backup of %s -> %s\n", sourceFile, backupFile);
+                    } catch(boost::filesystem::filesystem_error &error) {
+                        LogPrintf("Failed to create backup %s\n", error.what());
+                    }
                 }
                 // Keep only the last 10 backups, including the new one of course
                 typedef std::multimap<std::time_t, boost::filesystem::path> folder_set_t;
