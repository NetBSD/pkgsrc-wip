$NetBSD$

--- src/libs/loguru/loguru.cpp.orig	2023-01-07 07:06:28.000000000 +0000
+++ src/libs/loguru/loguru.cpp
@@ -1145,6 +1145,9 @@ namespace loguru
 			#elif defined(__FreeBSD__)
 				long thread_id;
 				(void)thr_self(&thread_id);
+			#elif defined(__NetBSD__)
+				const auto native_id = pthread_self();
+				const auto thread_id = reinterpret_cast<uintptr_t>((void*)native_id);
 			#elif LOGURU_PTHREADS
 				const auto native_id = pthread_self();
 				// Warning, even within POSIX, return types and sizes vary:
