$NetBSD$

--- src/VBox/Main/src-server/HostDnsService.cpp.orig	2016-03-04 19:29:40.000000000 +0000
+++ src/VBox/Main/src-server/HostDnsService.cpp
@@ -152,6 +152,8 @@ const HostDnsMonitor *HostDnsMonitor::ge
         g_monitor =  new HostDnsServiceSolaris();
 # elif defined(RT_OS_FREEBSD)
         g_monitor = new HostDnsServiceFreebsd();
+# elif defined(RT_OS_NETBSD)
+        g_monitor = new HostDnsServiceNetbsd();
 # elif defined(RT_OS_OS2)
         g_monitor = new HostDnsServiceOs2();
 # else
