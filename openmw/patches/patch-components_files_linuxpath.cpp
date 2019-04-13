$NetBSD$

Support NetBSD.

--- components/files/linuxpath.cpp.orig	2019-03-10 10:50:29.000000000 +0000
+++ components/files/linuxpath.cpp
@@ -1,6 +1,6 @@
 #include "linuxpath.hpp"
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <pwd.h>
 #include <unistd.h>
@@ -157,4 +157,4 @@ boost::filesystem::path LinuxPath::getIn
 
 } /* namespace Files */
 
-#endif /* defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) */
+#endif /* defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) */ 
