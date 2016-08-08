$NetBSD$

--- src/core/common/loghelper_server.cpp.orig	2016-08-07 01:11:48.000000000 +0000
+++ src/core/common/loghelper_server.cpp
@@ -67,7 +67,7 @@ void
 internal_log_err(const string &msg)
 {
 	if (!g_logFile.empty()) {
-		ofstream o(g_logFile.c_str(), ios_base::out | ios_base::app);
+		boost::filesystem::ofstream o(g_logFile.c_str(), ios_base::out | ios_base::app);
 		if (!o.fail()) {
 			o << second_clock::local_time() << " ERR: " << msg;
 			o.flush();
@@ -80,7 +80,7 @@ internal_log_msg(const std::string &msg)
 {
 	if (g_logLevel) {
 		if (!g_logFile.empty()) {
-			ofstream o(g_logFile.c_str(), ios_base::out | ios_base::app);
+			boost::filesystem::ofstream o(g_logFile.c_str(), ios_base::out | ios_base::app);
 			if (!o.fail())
 				o << second_clock::local_time() << " MSG: " << msg;
 		}
@@ -92,7 +92,7 @@ internal_log_level(const std::string &ms
 {
 	if (g_logLevel >= logLevel) {
 		if (!g_logFile.empty()) {
-			ofstream o(g_logFile.c_str(), ios_base::out | ios_base::app);
+			boost::filesystem::ofstream o(g_logFile.c_str(), ios_base::out | ios_base::app);
 			if (!o.fail())
 				o << second_clock::local_time() << " OUT: " << msg;
 		}
