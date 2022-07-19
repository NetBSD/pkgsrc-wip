$NetBSD$

Add NetBSD support.

--- src/unix/dialup.cpp.orig	2022-07-06 14:19:50.000000000 +0000
+++ src/unix/dialup.cpp
@@ -795,6 +795,7 @@ wxDialUpManagerImpl::NetConnection wxDia
     // nothing to add to ping command
 #elif defined(__AIX__) || \
       defined (__BSD__) || \
+      defined (__NetBSD__) || \
       defined(__LINUX__) || \
       defined(__OSF__) || \
       defined(__SGI__) || \
