$NetBSD$

pthread_setname_np takes 3 arguments on NetBSD.

--- src/libslic3r/Thread.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/libslic3r/Thread.cpp
@@ -160,7 +160,37 @@ std::optional<std::string> get_current_t
 	return std::nullopt;
 }
 
-#else
+#else // __APPLE__
+
+#ifdef __NetBSD__
+
+// pthread_setname_np takes 3 args on NetBSD.
+
+bool set_thread_name(std::thread &thread, const char *thread_name)
+{
+   	pthread_setname_np(thread.native_handle(), thread_name, nullptr);
+	return true;
+}
+
+bool set_thread_name(boost::thread &thread, const char *thread_name)
+{
+   	pthread_setname_np(thread.native_handle(), thread_name, nullptr);
+	return true;
+}
+
+bool set_current_thread_name(const char *thread_name)
+{
+	pthread_setname_np(pthread_self(), thread_name, nullptr);
+	return true;
+}
+
+std::optional<std::string> get_current_thread_name()
+{
+	char buf[16];
+	return std::string(pthread_getname_np(pthread_self(), buf, 16) == 0 ? buf : "");
+}
+
+#else // __NetBSD__
 
 // posix
 bool set_thread_name(std::thread &thread, const char *thread_name)
@@ -187,7 +217,9 @@ std::optional<std::string> get_current_t
 	return std::string(pthread_getname_np(pthread_self(), buf, 16) == 0 ? buf : "");
 }
 
-#endif
+#endif // __NetBSD__
+
+#endif // __APPLE__
 
 #endif // _WIN32
 
