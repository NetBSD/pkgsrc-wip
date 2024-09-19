$NetBSD$

--- src/VBox/Main/testcase/tstCollector.cpp.orig	2016-03-04 19:29:42.000000000 +0000
+++ src/VBox/Main/testcase/tstCollector.cpp
@@ -23,6 +23,9 @@
 #ifdef RT_OS_FREEBSD
 # include "../src-server/freebsd/PerformanceFreeBSD.cpp"
 #endif
+#ifdef RT_OS_NETBSD
+# include "../src-server/netbsd/PerformanceNetBSD.cpp"
+#endif
 #ifdef RT_OS_LINUX
 # include "../src-server/linux/PerformanceLinux.cpp"
 #endif
@@ -577,4 +580,3 @@ int main(int argc, char *argv[])
 
     return rc;
 }
-
