$NetBSD$

--- gpu/gpu_ipc_service.gypi.orig	2016-06-24 01:02:23.000000000 +0000
+++ gpu/gpu_ipc_service.gypi
@@ -82,7 +82,7 @@
         ],
       },
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or os_bsd==1', {
       'sources': [ 'ipc/service/image_transport_surface_linux.cc' ],
     }],
     ['use_x11 == 1 and (target_arch != "arm" or chromeos == 0)', {
