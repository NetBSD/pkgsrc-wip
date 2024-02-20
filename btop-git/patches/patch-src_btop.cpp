$NetBSD$

Add support for NetBSD.

--- src/btop.cpp.orig	2024-01-02 15:54:52.000000000 +0000
+++ src/btop.cpp
@@ -255,7 +255,7 @@ void clean_quit(int sig) {
 	Global::quitting = true;
 	Runner::stop();
 	if (Global::_runner_started) {
-	#if defined __APPLE__ || defined __OpenBSD__
+	#if defined __APPLE__ || defined __OpenBSD__ || defined __NetBSD__
 		if (pthread_join(Runner::runner_id, nullptr) != 0) {
 			Logger::warning("Failed to join _runner thread on exit!");
 			pthread_cancel(Runner::runner_id);
@@ -291,7 +291,7 @@ void clean_quit(int sig) {
 
 	const auto excode = (sig != -1 ? sig : 0);
 
-#if defined __APPLE__ || defined __OpenBSD__
+#if defined __APPLE__ || defined __OpenBSD__ || defined __NetBSD__
 	_Exit(excode);
 #else
 	quick_exit(excode);
@@ -975,7 +975,7 @@ int main(int argc, char **argv) {
 		Config::set("tty_mode", true);
 		Logger::info("Forcing tty mode: setting 16 color mode and using tty friendly graph symbols");
 	}
-#if not defined __APPLE__ && not defined __OpenBSD__
+#if not defined __APPLE__ && not defined __OpenBSD__ && not defined __NetBSD__
 	else if (not Global::arg_tty and Term::current_tty.starts_with("/dev/tty")) {
 		Config::set("tty_mode", true);
 		Logger::info("Real tty detected: setting 16 color mode and using tty friendly graph symbols");
