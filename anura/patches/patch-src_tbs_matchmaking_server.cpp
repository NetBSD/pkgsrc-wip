$NetBSD$
--- ./src/tbs_matchmaking_server.cpp.orig	2016-01-26 00:52:11.000000000 -0800
+++ ./src/tbs_matchmaking_server.cpp	2016-01-26 00:52:47.000000000 -0800
@@ -31,7 +31,7 @@
 #include <iostream>
 
 #include <sys/types.h>
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <sys/wait.h>
 #include <unistd.h>
 #endif
@@ -85,7 +85,7 @@
 
 void sendEmail(std::string email_addr, std::string subject, std::string message)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 
 	std::ostringstream s;
 	s << "/usr/sbin/sendmail " << email_addr;
