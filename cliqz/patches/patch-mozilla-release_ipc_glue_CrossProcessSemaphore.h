$NetBSD$

Original patch from ryoon, imported from www/firefox

--- mozilla-release/ipc/glue/CrossProcessSemaphore.h.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/ipc/glue/CrossProcessSemaphore.h
@@ -93,7 +93,13 @@ private:
   HANDLE mSemaphore;
 #elif !defined(OS_MACOSX)
   RefPtr<mozilla::ipc::SharedMemoryBasic> mSharedBuffer;
+#if defined(__NetBSD__)
+  pthread_mutex_t* mMutex;
+  pthread_cond_t* mNotZero;
+  uint32_t* mValue;
+#else  
   sem_t* mSemaphore;
+#endif  
   mozilla::Atomic<int32_t>* mRefCount;
 #endif
 };
