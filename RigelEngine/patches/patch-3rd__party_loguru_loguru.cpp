$NetBSD$

* Copy the OpenBSD code: NetBSD does not provide an integer thread ID.
* fix compile error for static_cast<> discarding const qualifiers.

--- 3rd_party/loguru/loguru.cpp.orig	2022-05-29 11:42:06.000000000 +0000
+++ 3rd_party/loguru/loguru.cpp
@@ -973,6 +973,8 @@ namespace loguru
 			#elif defined(__FreeBSD__)
 				long thread_id;
 				(void)thr_self(&thread_id);
+			#elif defined(__NetBSD__)
+				unsigned thread_id = -1;
 			#elif defined(__OpenBSD__)
 				unsigned thread_id = -1;
 			#else
@@ -1088,7 +1090,7 @@ namespace loguru
 						 i - skip, int(2 + sizeof(void*) * 2), callstack[i],
 						 status == 0 ? demangled :
 						 info.dli_sname == 0 ? symbols[i] : info.dli_sname,
-						 static_cast<char*>(callstack[i]) - static_cast<char*>(info.dli_saddr));
+						 static_cast<const char*>(callstack[i]) - static_cast<const char*>(info.dli_saddr));
 				free(demangled);
 			} else {
 				snprintf(buf, sizeof(buf), "%-3d %*p %s\n",
