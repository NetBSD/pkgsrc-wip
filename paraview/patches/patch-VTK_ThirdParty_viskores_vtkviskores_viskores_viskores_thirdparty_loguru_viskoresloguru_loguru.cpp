$NetBSD$

NetBSD support

--- VTK/ThirdParty/viskores/vtkviskores/viskores/viskores/thirdparty/loguru/viskoresloguru/loguru.cpp.orig	2025-08-10 04:01:20.217486597 +0000
+++ VTK/ThirdParty/viskores/vtkviskores/viskores/viskores/thirdparty/loguru/viskoresloguru/loguru.cpp
@@ -102,7 +102,7 @@
 		#include <pthread_np.h>
 	#endif
 
-	#ifdef __linux__
+	#if defined(__linux__) || defined(__NetBSD__)
 		/* On Linux, the default thread name is the same as the name of the binary.
 		   Additionally, all new threads inherit the name of the thread it got forked from.
 		   For this reason, Loguru use the pthread Thread Local Storage
@@ -572,6 +572,8 @@ namespace loguru
 					pthread_setname_np("main thread");
 				#elif defined(__FreeBSD__) || defined(__OpenBSD__)
 					pthread_set_name_np(this_thread, "main thread");
+				#elif defined(__NetBSD__)
+					pthread_set_name_np(this_thread, "%s", "main thread");
 				#elif defined(__linux__)
 					pthread_setname_np(this_thread, "main thread");
 				#endif
@@ -960,6 +962,8 @@ namespace loguru
 			#elif defined(__FreeBSD__)
 				long thread_id;
 				(void)thr_self(&thread_id);
+			#elif defined(__NetBSD__)
+				uint64_t thread_id = (uint64_t)pthread_self();
 			#elif defined(__OpenBSD__)
 				unsigned thread_id = -1;
 			#else
@@ -1075,7 +1079,7 @@ namespace loguru
 						 i - skip, int(2 + sizeof(void*) * 2), callstack[i],
 						 status == 0 ? demangled :
 						 info.dli_sname == 0 ? symbols[i] : info.dli_sname,
-						 static_cast<char*>(callstack[i]) - static_cast<char*>(info.dli_saddr));
+						 static_cast<char*>(callstack[i]) - static_cast<const char*>(info.dli_saddr));
 				free(demangled);
 			} else {
 				snprintf(buf, sizeof(buf), "%-3d %*p %s\n",
