$NetBSD$

This single patch allows glxgears to run properly on
an Intel integrated graphics IvyBridge machine on DragonFly.
libdrm atomic_add_unless() may reverse return value meaning
https://bugs.freedesktop.org/show_bug.cgi?id=100077

This does not seem the correct choice in mesa3d.

--- src/gallium/drivers/iris/iris_bufmgr.c.orig	2019-03-30 17:05:31.000000000 +0000
+++ src/gallium/drivers/iris/iris_bufmgr.c
@@ -114,7 +114,11 @@ atomic_add_unless(int *v, int add, int u
    c = p_atomic_read(v);
    while (c != unless && (old = p_atomic_cmpxchg(v, c, c + add)) != c)
       c = old;
+#if defined(INVERT_ATOMIC_ADD_UNLESS)
+   return c != unless;
+#else
    return c == unless;
+#endif
 }
 
 static const char *
