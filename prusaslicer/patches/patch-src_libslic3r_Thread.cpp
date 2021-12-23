$NetBSD$

pthread_setname_np takes 3 arguments on NetBSD.

--- src/libslic3r/Thread.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/libslic3r/Thread.cpp
@@ -156,6 +156,36 @@ std::optional<std::string> get_current_t
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
@@ -183,7 +213,9 @@ std::optional<std::string> get_current_t
 	return std::string(pthread_getname_np(pthread_self(), buf, 16) == 0 ? buf : "");
 }
 
-#endif
+#endif // __NetBSD__
+
+#endif // __APPLE__
 
 #endif // _WIN32
 
@@ -241,6 +273,9 @@ void name_tbb_thread_pool_threads_set_lo
 #else
 				// We are leaking some memory here, because the newlocale() produced memory will never be released.
 				// This is not a problem though, as there will be a maximum one worker thread created per physical thread.
+#ifdef __NetBSD__
+                                setlocale(LC_ALL, "C");
+#else
 				uselocale(newlocale(
 #ifdef __APPLE__
 					LC_ALL_MASK
@@ -249,6 +284,7 @@ void name_tbb_thread_pool_threads_set_lo
 #endif
 					, "C", nullptr));
 #endif
+#endif
     		}
         });
 }
