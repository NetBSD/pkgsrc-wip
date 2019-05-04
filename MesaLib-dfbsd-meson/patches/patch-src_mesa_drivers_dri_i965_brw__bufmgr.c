$NetBSD$

From Ravenports

graphics/mesa-dri: Disable soft-spinning of all buffers (#169)

* It is broken with current DragonFly 5.4 and 5.5 kernels

* This patch is a revert of Mesa's
commit: a363bb2cd0e2a141f2c60be005009703bffcbe4e
"i965: Allocate VMA in userspace for full-PPGTT systems."
Date: Tue Apr 10 01:18:25 2018 -0700

Discussion in

https://bugs.dragonflybsd.org/issues/3171

--- src/mesa/drivers/dri/i965/brw_bufmgr.c.orig	2019-05-03 15:59:12.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_bufmgr.c
@@ -1721,7 +1721,11 @@ brw_bufmgr_init(struct gen_device_info *
       bufmgr->initial_kflags |= EXEC_OBJECT_SUPPORTS_48B_ADDRESS;
 
       /* Allocate VMA in userspace if we have softpin and full PPGTT. */
+#if defined(REVERT_I965_SOFTPIN)
+      if (false && gem_param(fd, I915_PARAM_HAS_EXEC_SOFTPIN) > 0 &&
+#else
       if (gem_param(fd, I915_PARAM_HAS_EXEC_SOFTPIN) > 0 &&
+#endif
           gem_param(fd, I915_PARAM_HAS_ALIASING_PPGTT) > 1) {
          bufmgr->initial_kflags |= EXEC_OBJECT_PINNED;
 
