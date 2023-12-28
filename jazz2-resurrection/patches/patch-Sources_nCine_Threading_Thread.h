$NetBSD$

Adapt threading to NetBSD definitions.

--- Sources/nCine/Threading/Thread.h.orig	2023-12-27 16:57:49.158147558 +0000
+++ Sources/nCine/Threading/Thread.h
@@ -15,6 +15,10 @@
 #	include <mach/mach_init.h>
 #endif
 
+#if defined(__NetBSD__)
+#	include <sched.h>
+#endif
+
 namespace nCine
 {
 #if !defined(DEATH_TARGET_ANDROID) && !defined(DEATH_TARGET_EMSCRIPTEN) && !defined(DEATH_TARGET_SWITCH)
@@ -27,9 +31,19 @@ namespace nCine
 	public:
 		ThreadAffinityMask()
 		{
+#if defined(__NetBSD__)
+			cpuSet_ = cpuset_create();
+#endif
 			Zero();
 		}
 
+#if defined(__NetBSD__)
+		~ThreadAffinityMask()
+		{
+			cpuset_destroy(cpuSet_);
+		}
+#endif
+
 		ThreadAffinityMask(std::int32_t cpuNum)
 		{
 			Zero();
@@ -50,6 +64,8 @@ namespace nCine
 		DWORD_PTR affinityMask_;
 #	elif defined(DEATH_TARGET_APPLE)
 		integer_t affinityTag_;
+#	elif defined(__NetBSD__)
+		cpuset_t *cpuSet_;
 #	else
 		cpu_set_t cpuSet_;
 #	endif
@@ -181,4 +197,4 @@ namespace nCine
 		static void* WrapperFunction(void* arg);
 #endif
 	};
-}
\ No newline at end of file
+}
