$NetBSD: patch-src_network_kernel_qhostinfo__unix.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

--- src/network/kernel/qhostinfo_unix.cpp.orig	2016-05-20 00:28:33.000000000 +0000
+++ src/network/kernel/qhostinfo_unix.cpp
@@ -117,6 +117,8 @@ static bool resolveLibraryInternal()
         if (!local_res_nclose)
             local_res_ninit = 0;
     }
+    if (local_res_ninit)
+        local_res_ninit = 0;
 #endif
 
     return true;
