$NetBSD$

Adapt to pthread_setname_np signature on NetBSD.

Not yet sent upstream.

--- cpp/src/platform/unix/ThreadImpl.cpp.orig	2019-05-03 14:49:45.000000000 +0000
+++ cpp/src/platform/unix/ThreadImpl.cpp
@@ -90,8 +90,13 @@ bool ThreadImpl::Start
 	string threadname("OZW-");
 	threadname.append(m_name);
 #if !defined(__APPLE_CC__) && !defined(__FreeBSD__)
+#if defined(__NetBSD__)
+	/* signature differs */
+	pthread_setname_np( m_hThread, "%s", (void  *) threadname.c_str() );
+#else
 	pthread_setname_np( m_hThread, threadname.c_str() );
 #endif
+#endif
 	//fprintf(stderr, "thread %s starting %08x\n", m_name.c_str(), m_hThread);
 	//fflush(stderr);
 
