$NetBSD$

* Import patch from chromium

--- src/Vulkan/VkSemaphoreExternalLinux.hpp.orig	2025-11-19 17:28:04.673283748 +0000
+++ src/Vulkan/VkSemaphoreExternalLinux.hpp
@@ -50,13 +50,17 @@ public:
 	{
 		pthread_mutexattr_t mattr;
 		pthread_mutexattr_init(&mattr);
+#if 0
 		pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
+#endif
 		pthread_mutex_init(&mutex, &mattr);
 		pthread_mutexattr_destroy(&mattr);
 
 		pthread_condattr_t cattr;
 		pthread_condattr_init(&cattr);
+#if 0
 		pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED);
+#endif
 		pthread_cond_init(&cond, &cattr);
 		pthread_condattr_destroy(&cattr);
 	}
