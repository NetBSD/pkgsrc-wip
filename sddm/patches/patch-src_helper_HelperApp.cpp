$NetBSD$

NetBSD support

--- src/helper/HelperApp.cpp.orig	2020-11-03 09:47:51.000000000 +0000
+++ src/helper/HelperApp.cpp
@@ -308,7 +308,7 @@ namespace SDDM {
             qWarning() << "Failed to write utmpx: " << strerror(errno);
         endutxent();
 
-#if !defined(Q_OS_FREEBSD)
+#if !defined(Q_OS_FREEBSD) && !defined(Q_OS_NETBSD)
         // append to failed login database btmp
         if (!authSuccessful) {
 #if defined(Q_OS_LINUX)
@@ -360,7 +360,7 @@ namespace SDDM {
 #if defined(Q_OS_LINUX)
         // append to wtmp
         updwtmpx("/var/log/wtmp", &entry);
-#elif defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
         pututxline(&entry);
 #endif
     }
