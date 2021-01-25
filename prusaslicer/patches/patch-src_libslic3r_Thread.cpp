$NetBSD$

pthread_setname_np takes 3 arguments.

--- src/libslic3r/Thread.cpp.orig	2021-01-11 13:01:51.000000000 +0000
+++ src/libslic3r/Thread.cpp
@@ -161,19 +161,19 @@ std::optional<std::string> get_current_t
 // posix
 bool set_thread_name(std::thread &thread, const char *thread_name)
 {
-   	pthread_setname_np(thread.native_handle(), thread_name);
+   	pthread_setname_np(thread.native_handle(), thread_name, nullptr);
 	return true;
 }
 
 bool set_thread_name(boost::thread &thread, const char *thread_name)
 {
-   	pthread_setname_np(thread.native_handle(), thread_name);
+   	pthread_setname_np(thread.native_handle(), thread_name, nullptr);
 	return true;
 }
 
 bool set_current_thread_name(const char *thread_name)
 {
-	pthread_setname_np(pthread_self(), thread_name);
+	pthread_setname_np(pthread_self(), thread_name, nullptr);
 	return true;
 }
 
