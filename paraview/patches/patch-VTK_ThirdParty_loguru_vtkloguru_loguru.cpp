$NetBSD$

NetBSD support

--- VTK/ThirdParty/loguru/vtkloguru/loguru.cpp.orig	2022-11-14 01:46:47.000000000 +0000
+++ VTK/ThirdParty/loguru/vtkloguru/loguru.cpp
@@ -973,10 +973,12 @@ namespace loguru
 			#elif defined(__FreeBSD__)
 				long thread_id;
 				(void)thr_self(&thread_id);
+			#elif defined(__NetBSD__)
+				uint64_t thread_id = (uint64_t)pthread_self();
 			#elif defined(__OpenBSD__)
 				unsigned thread_id = -1;
 			#else
-				uint64_t thread_id = thread;
+				uint64_t thread_id = (void *)thread;
 			#endif
 			if (right_align_hext_id) {
 				snprintf(buffer, length, "%*X", static_cast<int>(length - 1), static_cast<unsigned>(thread_id));
@@ -1088,7 +1090,7 @@ namespace loguru
 						 i - skip, int(2 + sizeof(void*) * 2), callstack[i],
 						 status == 0 ? demangled :
 						 info.dli_sname == 0 ? symbols[i] : info.dli_sname,
-						 static_cast<char*>(callstack[i]) - static_cast<char*>(info.dli_saddr));
+						 static_cast<char*>(callstack[i]) - static_cast<const char*>(info.dli_saddr));
 				free(demangled);
 			} else {
 				snprintf(buf, sizeof(buf), "%-3d %*p %s\n",
