$NetBSD: patch-hotspot_src_os_cpu_bsd_i486.cpp,v 1.1 2011/07/23 04:37:05 ftigeot Exp $

--- hotspot/src/os_cpu/bsd_i486/vm/os_bsd_i486.cpp.orig	2011-07-22 13:35:38 +0000
+++ hotspot/src/os_cpu/bsd_i486/vm/os_bsd_i486.cpp
@@ -35,7 +35,7 @@
 # include <fpu_control.h>
 #endif
 
-# ifdef __FreeBSD__
+# if defined(__FreeBSD__) || defined (__DragonFly__)
 #  include <pthread_np.h>
 #  define context_eip uc_mcontext.mc_eip
 #  define context_esp uc_mcontext.mc_esp
