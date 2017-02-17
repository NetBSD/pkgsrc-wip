$NetBSD$

--- content/browser/memory/memory_coordinator_impl.cc.orig	2017-02-02 02:02:53.000000000 +0000
+++ content/browser/memory/memory_coordinator_impl.cc
@@ -116,8 +116,12 @@ void RecordMetricsOnStateChange(base::Me
 struct MemoryCoordinatorSingletonTraits
     : public base::LeakySingletonTraits<MemoryCoordinator> {
   static MemoryCoordinator* New() {
+#if defined(OS_BSD)
+    return nullptr;
+#else
     return new MemoryCoordinatorImpl(base::ThreadTaskRunnerHandle::Get(),
                                      CreateMemoryMonitor());
+#endif
   }
 };
 
