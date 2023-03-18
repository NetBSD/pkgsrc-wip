$NetBSD$

NetBSD support

--- VTK/ThirdParty/vtkm/vtkvtkm/vtk-m/vtkm/thirdparty/loguru/vtkmloguru/loguru.cpp.orig	2022-11-14 01:46:47.000000000 +0000
+++ VTK/ThirdParty/vtkm/vtkvtkm/vtk-m/vtkm/thirdparty/loguru/vtkmloguru/loguru.cpp
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
