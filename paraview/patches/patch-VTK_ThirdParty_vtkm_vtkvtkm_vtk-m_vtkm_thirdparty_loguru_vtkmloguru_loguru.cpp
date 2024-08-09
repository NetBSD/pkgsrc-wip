$NetBSD$

NetBSD support

--- VTK/ThirdParty/vtkm/vtkvtkm/vtk-m/vtkm/thirdparty/loguru/vtkmloguru/loguru.cpp.orig	2024-05-17 19:18:15.000000000 +0000
+++ VTK/ThirdParty/vtkm/vtkvtkm/vtk-m/vtkm/thirdparty/loguru/vtkmloguru/loguru.cpp
@@ -102,7 +102,7 @@
 		#include <pthread_np.h>
 	#endif
 
-	#ifdef __linux__
+	#if defined(__linux__) || defined(__NetBSD__)
 		/* On Linux, the default thread name is the same as the name of the binary.
 		   Additionally, all new threads inherit the name of the thread it got forked from.
 		   For this reason, Loguru use the pthread Thread Local Storage
@@ -960,6 +960,8 @@ namespace loguru
 			#elif defined(__FreeBSD__)
 				long thread_id;
 				(void)thr_self(&thread_id);
+			#elif defined(__NetBSD__)
+				uint64_t thread_id = (uint64_t)pthread_self();
 			#elif defined(__OpenBSD__)
 				unsigned thread_id = -1;
 			#else
@@ -1075,7 +1077,7 @@ namespace loguru
 						 i - skip, int(2 + sizeof(void*) * 2), callstack[i],
 						 status == 0 ? demangled :
 						 info.dli_sname == 0 ? symbols[i] : info.dli_sname,
-						 static_cast<char*>(callstack[i]) - static_cast<char*>(info.dli_saddr));
+						 static_cast<char*>(callstack[i]) - static_cast<const char*>(info.dli_saddr));
 				free(demangled);
 			} else {
 				snprintf(buf, sizeof(buf), "%-3d %*p %s\n",
