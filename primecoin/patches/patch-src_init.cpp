$NetBSD$

--- src/init.cpp.orig	2013-08-05 12:37:20.000000000 +0000
+++ src/init.cpp
@@ -537,7 +537,7 @@ bool AppInit2(boost::thread_group& threa
     // Make sure enough file descriptors are available
     int nBind = std::max((int)mapArgs.count("-bind"), 1);
     nMaxConnections = GetArg("-maxconnections", 125);
-    nMaxConnections = std::max(std::min(nMaxConnections, FD_SETSIZE - nBind - MIN_CORE_FILEDESCRIPTORS), 0);
+    nMaxConnections = std::max(std::min(nMaxConnections, (int)(FD_SETSIZE - nBind - MIN_CORE_FILEDESCRIPTORS)), 0);
     int nFD = RaiseFileDescriptorLimit(nMaxConnections + MIN_CORE_FILEDESCRIPTORS);
     if (nFD < MIN_CORE_FILEDESCRIPTORS)
         return InitError(_("Not enough file descriptors available."));
