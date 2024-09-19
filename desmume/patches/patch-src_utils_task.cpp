$NetBSD: patch-src_utils_task.cpp,v 1.1 2013/12/19 03:25:57 othyro Exp $

Pass correct type.

--- src/utils/task.cpp.orig	2013-11-28 00:37:27.000000000 +0000
+++ src/utils/task.cpp
@@ -42,7 +42,7 @@ int getOnlineCores (void)
 #elif defined HOST_BSD
 	int cores;
 	const int mib[4] = { CTL_HW, HW_NCPU, 0, 0 };
-	const size_t len = sizeof(cores);
+	size_t len = sizeof(cores);
 	sysctl(mib, 2, &cores, &len, NULL, 0);
 	return (cores < 1) ? 1 : cores;
 #else
