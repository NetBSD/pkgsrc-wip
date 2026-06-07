$NetBSD$

# vfork() is deprecated on macOS

--- Parameters_openReadsFiles.cpp.orig	2026-06-07 00:57:24.777038819 +0000
+++ Parameters_openReadsFiles.cpp
@@ -80,10 +80,10 @@ void Parameters::openReadsFiles()
             readFilesCommandPID[imate]=0;
 
             ostringstream errOut;
-            pid_t PID=vfork();
+            pid_t PID=fork();
             switch (PID) {
                 case -1:
-                    errOut << "EXITING: because of fatal EXECUTION error: Failed vforking readFilesCommand\n";
+                    errOut << "EXITING: because of fatal EXECUTION error: Failed forking readFilesCommand\n";
                     errOut << errno << ": " << strerror(errno) << "\n";
                     exitWithError(errOut.str(), std::cerr, inOut->logMain, EXIT_CODE_PARAMETER, *this);
                     break;
