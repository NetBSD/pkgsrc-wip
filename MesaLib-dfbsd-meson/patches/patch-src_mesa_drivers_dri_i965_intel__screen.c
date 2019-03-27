$NetBSD: patch-src_mesa_drivers_dri_i965_intel__screen.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Move sys/sysctl.h include because on NetBSD, sysctl.h includes sys/param.h,
and sys/param.h defines a one argument ALIGN.  Allows mesa to redefine
to a two argument ALIGN.

Fix build on older NetBSD w/o _SC_PHYS_PAGES.

From FreeBSD ports graphics/mesa-dri 18.1.4

# Partial revert of the following commit because the feature check fails on 10.x
# which disables HW accel on gen4+ (the new check occurs for gen6+ as well)

From 088449487ebcb72561d73ffb91c96302583445a8 Mon Sep 17 00:00:00 2001
Date: Wed, 22 Mar 2017 15:20:51 -0700
Subject: i965: Require Kernel 3.6 for Gen4-5 platforms.

We've already required Kernel 3.6 on Gen6+ since Mesa 9.2 (May 2013,
commit 92d2f5acfadea672417b6785710c9e8b7f605e41).  It seems reasonable
to require it for Gen4-5 as well, bumping the requirement from 2.6.39.

This is necessary for glClientWaitSync with a timeout to work, which
is a feature we expose on Gen4-5.  Without it, we would fall back to an
infinite wait, which is pretty bad.

See kernel commit 172cf15d18889313bf2c3bfb81fcea08369274ef in 3.6+.

--- src/mesa/drivers/dri/i965/intel_screen.c.orig	2017-11-10 23:18:56.000000000 +0000
+++ src/mesa/drivers/dri/i965/intel_screen.c
@@ -27,6 +27,11 @@
 #include <errno.h>
 #include <time.h>
 #include <unistd.h>
+
+#if defined(HAVE_SYS_SYSCTL_H) && defined(PHYSMEM_NETBSD)
+# include <sys/sysctl.h>
+#endif
+
 #include "main/context.h"
 #include "main/framebuffer.h"
 #include "main/renderbuffer.h"
@@ -1470,6 +1475,13 @@ brw_query_renderer_integer(__DRIscreen *
       const unsigned gpu_mappable_megabytes =
          screen->aperture_threshold / (1024 * 1024);
 
+#if defined(HW_PHYSMEM64) && defined(PHYSMEM_NETBSD)
+      int mib[2] = { CTL_HW, HW_PHYSMEM64 };
+      const uint64_t system_memory_bytes;
+      size_t len = sizeof(system_memory_bytes);
+      if (sysctl(mib, 2, &system_memory_bytes, &len, NULL, 0) != 0)
+         return -1;
+#else
       const long system_memory_pages = sysconf(_SC_PHYS_PAGES);
       const long system_page_size = sysconf(_SC_PAGE_SIZE);
 
@@ -1478,6 +1490,7 @@ brw_query_renderer_integer(__DRIscreen *
 
       const uint64_t system_memory_bytes = (uint64_t) system_memory_pages
          * (uint64_t) system_page_size;
+#endif
 
       const unsigned system_memory_megabytes =
          (unsigned) (system_memory_bytes / (1024 * 1024));
@@ -1840,10 +1853,17 @@ intel_init_bufmgr(struct intel_screen *s
       return false;
    }
 
+#if defined(REQUIRE_36_GEN4)
+   if (!intel_get_boolean(screen, I915_PARAM_HAS_RELAXED_DELTA)) {
+      fprintf(stderr, "[%s: %u] Kernel 2.6.39 required.\n", __func__, __LINE__);
+      return false;
+   }
+#else
    if (!intel_get_boolean(screen, I915_PARAM_HAS_EXEC_NO_RELOC)) {
       fprintf(stderr, "[%s: %u] Kernel 3.9 required.\n", __func__, __LINE__);
       return false;
    }
+#endif
 
    return true;
 }
