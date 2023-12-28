$NetBSD$

Adapt threading to NetBSD definitions.

--- Sources/nCine/Threading/PosixThread.cpp.orig	2023-12-27 17:00:23.489746239 +0000
+++ Sources/nCine/Threading/PosixThread.cpp
@@ -28,6 +28,31 @@
 #	include "common/TracySystem.hpp"
 #endif
 
+#define PTHREAD_SETNAME_NP(h, n) pthread_setname_np(h, n)
+
+#if defined(__NetBSD__)
+#	define PTHREAD_SETNAME_NP(h, n) pthread_setname_np(h, "%s", (void*)n)
+/* requires super-user priveleges, so disable for now */
+#	define pthread_getaffinity_np(t, s, c) while(0) {}
+#	define pthread_setaffinity_np(t, s, c) while(0) {}
+
+void CPU_CLR(int id, cpuset_t **cs) {
+ cpuset_clr(id, *cs);
+}
+
+int CPU_ISSET(int id, cpuset_t **cs) {
+ return cpuset_isset(id, *cs);
+}
+
+void CPU_SET(int id, cpuset_t **cs) {
+ cpuset_set(id, *cs);
+}
+
+void CPU_ZERO(cpuset_t **cs) {
+ cpuset_zero(*cs);
+}
+#endif
+
 namespace nCine
 {
 	namespace
@@ -168,12 +193,12 @@ namespace nCine
 
 		const auto nameLength = strnlen(name, MaxThreadNameLength);
 		if (nameLength <= MaxThreadNameLength - 1) {
-			pthread_setname_np(_sharedBlock->_handle, name);
+			PTHREAD_SETNAME_NP(_sharedBlock->_handle, name);
 		} else {
 			char buffer[MaxThreadNameLength];
 			memcpy(buffer, name, MaxThreadNameLength - 1);
 			buffer[MaxThreadNameLength - 1] = '\0';
-			pthread_setname_np(_sharedBlock->_handle, name);
+			PTHREAD_SETNAME_NP(_sharedBlock->_handle, name);
 		}
 #endif
 	}
@@ -186,7 +211,7 @@ namespace nCine
 		const auto nameLength = strnlen(name, MaxThreadNameLength);
 		if (nameLength <= MaxThreadNameLength - 1) {
 #	if !defined(DEATH_TARGET_APPLE)
-			pthread_setname_np(pthread_self(), name);
+			PTHREAD_SETNAME_NP(pthread_self(), name);
 #	else
 			pthread_setname_np(name);
 #	endif
@@ -195,7 +220,7 @@ namespace nCine
 			memcpy(buffer, name, MaxThreadNameLength - 1);
 			buffer[MaxThreadNameLength - 1] = '\0';
 #	if !defined(DEATH_TARGET_APPLE)
-			pthread_setname_np(pthread_self(), name);
+			PTHREAD_SETNAME_NP(pthread_self(), name);
 #	else
 			pthread_setname_np(name);
 #	endif
@@ -233,7 +258,7 @@ namespace nCine
 
 	std::uintptr_t Thread::GetCurrentId()
 	{
-#if defined(DEATH_TARGET_APPLE) || defined(DEATH_TARGET_SWITCH) || defined(__FreeBSD__)
+#if defined(DEATH_TARGET_APPLE) || defined(DEATH_TARGET_SWITCH) || defined(__FreeBSD__) || defined(__NetBSD__)
 		return reinterpret_cast<std::uintptr_t>(pthread_self());
 #else
 		return static_cast<std::uintptr_t>(pthread_self());
@@ -316,4 +341,4 @@ namespace nCine
 
 #endif
 
-#endif
\ No newline at end of file
+#endif
