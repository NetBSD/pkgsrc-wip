$NetBSD$

Fix pthread_setname_np on NetBSD

--- src/platform/Thread.cpp.orig	2020-12-30 05:41:19.000000000 +0000
+++ src/platform/Thread.cpp
@@ -134,7 +134,11 @@ void * Thread::entryPoint(void * param) 
 	// Set the thread name.
 	#if ARX_HAVE_PTHREAD_SETNAME_NP && ARX_PLATFORM != ARX_PLATFORM_MACOS
 	// Linux
+# ifdef __NetBSD__
+	pthread_setname_np(thread.m_thread, "%s", (void*)thread.m_threadName.c_str());
+# else
 	pthread_setname_np(thread.m_thread, thread.m_threadName.c_str());
+# endif
 	#elif ARX_HAVE_PTHREAD_SETNAME_NP && ARX_PLATFORM == ARX_PLATFORM_MACOS
 	// macOS
 	pthread_setname_np(thread.m_threadName.c_str());
