$NetBSD$

This single patch allows glxgears to run properly on
an Intel integrated graphics IvyBridge machine on DragonFly.
libdrm atomic_add_unless() may reverse return value meaning
https://bugs.freedesktop.org/show_bug.cgi?id=100077

From Ravenports

graphics/mesa-dri: Disable soft-spinning of all buffers (#169)

* It is broken with current DragonFly 5.4 and 5.5 kernels

* This patch is a revert of Mesa's
commit: a363bb2cd0e2a141f2c60be005009703bffcbe4e
"i965: Allocate VMA in userspace for full-PPGTT systems."
Date: Tue Apr 10 01:18:25 2018 -0700

Discussion in

https://bugs.dragonflybsd.org/issues/3171

--- src/mesa/drivers/dri/i965/brw_bufmgr.c.orig	2019-03-05 16:06:50.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_bufmgr.c
@@ -98,7 +98,11 @@ atomic_add_unless(int *v, int add, int u
    c = p_atomic_read(v);
    while (c != unless && (old = p_atomic_cmpxchg(v, c, c + add)) != c)
       c = old;
+#if defined(INVERT_ATOMIC_ADD_UNLESS)
+   return c != unless;
+#else
    return c == unless;
+#endif
 }
 
 /**
@@ -1721,7 +1725,11 @@ brw_bufmgr_init(struct gen_device_info *
       bufmgr->initial_kflags |= EXEC_OBJECT_SUPPORTS_48B_ADDRESS;
 
       /* Allocate VMA in userspace if we have softpin and full PPGTT. */
+#if defined(REVERT_I965_SOFTPIN)
+      if (false && gem_param(fd, I915_PARAM_HAS_EXEC_SOFTPIN) > 0 &&
+#else
       if (gem_param(fd, I915_PARAM_HAS_EXEC_SOFTPIN) > 0 &&
+#endif
           gem_param(fd, I915_PARAM_HAS_ALIASING_PPGTT) > 1) {
          bufmgr->initial_kflags |= EXEC_OBJECT_PINNED;
 
