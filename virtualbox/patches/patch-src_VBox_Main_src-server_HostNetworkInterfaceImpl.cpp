$NetBSD$

--- src/VBox/Main/src-server/HostNetworkInterfaceImpl.cpp.orig	2016-03-04 19:29:40.000000000 +0000
+++ src/VBox/Main/src-server/HostNetworkInterfaceImpl.cpp
@@ -27,9 +27,9 @@
 
 #include <iprt/cpp/utils.h>
 
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <netinet/in.h> /* INADDR_NONE */
-#endif /* RT_OS_FREEBSD */
+#endif /* RT_OS_FREEBSD || RT_OS_NETBSD */
 
 #include "VirtualBoxImpl.h"
 
