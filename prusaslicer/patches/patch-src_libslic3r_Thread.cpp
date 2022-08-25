$NetBSD$

pthread_setname_np takes 3 arguments on NetBSD.

--- src/libslic3r/Thread.cpp.orig	2022-08-19 14:41:23.000000000 +0000
+++ src/libslic3r/Thread.cpp
@@ -157,6 +157,36 @@ std::optional<std::string> get_current_t
 	return std::nullopt;
 }
 
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
 #else
 
 // posix
@@ -184,7 +214,9 @@ std::optional<std::string> get_current_t
 	return std::string(pthread_getname_np(pthread_self(), buf, 16) == 0 ? buf : "");
 }
 
-#endif
+#endif // __NetBSD__
+
+#endif // __APPLE__
 
 #endif // _WIN32
 
