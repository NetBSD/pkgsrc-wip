$NetBSD$

* Add NetBSD support

--- src/services/pam/subprocess.cpp.orig	2026-09-19 13:09:00.734135837 +0000
+++ src/services/pam/subprocess.cpp
@@ -7,7 +7,7 @@
 #include <qloggingcategory.h>
 #include <qstring.h>
 #include <sched.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <security/pam_types.h>
 #else
 #include <security/_pam_types.h>
@@ -87,7 +87,7 @@ PamIpcExitCode PamSubprocess::exec(const
 	logIf(this->log) << "Starting pam session for user \"" << user << "\" with config \"" << config
 	                 << "\" in dir \"" << configDir << "\"" << std::endl;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 	auto result = pam_start(config, user, &conv, &handle);
 #else
 	auto result = pam_start_confdir(config, user, &conv, configDir, &handle);
