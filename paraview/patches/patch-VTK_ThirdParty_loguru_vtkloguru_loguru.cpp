$NetBSD$

NetBSD support

--- VTK/ThirdParty/loguru/vtkloguru/loguru.cpp.orig	2024-05-17 19:18:15.000000000 +0000
+++ VTK/ThirdParty/loguru/vtkloguru/loguru.cpp
@@ -109,7 +109,7 @@
 		#include <pthread_np.h>
 	#endif
 
-	#ifdef __linux__
+	#if defined(__linux__) || defined(__NetBSD__)
 		/* On Linux, the default thread name is the same as the name of the binary.
 		   Additionally, all new threads inherit the name of the thread it got forked from.
 		   For this reason, Loguru use the pthread Thread Local Storage
@@ -993,7 +993,7 @@ namespace loguru
 				pid_t thread_id = getthrid();
 			#elif LOGURU_PTHREADS
 				// Here we rely on the opaque pthread_t being of integer type, which is the case on linux, but not other platforms.
-				uint64_t thread_id = static_cast<uint64_t>(pthread_self());
+				uint64_t thread_id = (uint64_t)pthread_self();
 			#else
 				// This ID does not correllate to anything we can get from the OS,
 				// so this is the worst way to get the ID.
@@ -1100,7 +1100,7 @@ namespace loguru
 						 i - skip, int(2 + sizeof(void*) * 2), callstack[i],
 						 status == 0 ? demangled :
 						 info.dli_sname == 0 ? symbols[i] : info.dli_sname,
-						 static_cast<char*>(callstack[i]) - static_cast<char*>(info.dli_saddr));
+						 static_cast<char*>(callstack[i]) - static_cast<const char*>(info.dli_saddr));
 				free(demangled);
 			} else {
 				snprintf(buf, sizeof(buf), "%-3d %*p %s\n",
