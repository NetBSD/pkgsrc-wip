$NetBSD$

--- src/VBox/Frontends/VBoxAutostart/VBoxAutostart-posix.cpp.orig	2016-03-04 19:28:58.000000000 +0000
+++ src/VBox/Frontends/VBoxAutostart/VBoxAutostart-posix.cpp
@@ -61,7 +61,7 @@
 
 using namespace com;
 
-#if defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_DARWIN)
+#if defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_DARWIN) || defined(RT_OS_NETBSD)
 # define VBOXAUTOSTART_DAEMONIZE
 #endif
 
@@ -564,4 +564,3 @@ int main(int argc, char *argv[])
     autostartShutdown();
     return rcExit;
 }
-
