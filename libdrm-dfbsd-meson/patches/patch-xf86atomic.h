$NetBSD$

Option to define atomic types similar to current NetBSD xsrc.

This single patch allows glxgears to run properly on
an Intel integrated graphics IvyBridge machine on DragonFly.
libdrm atomic_add_unless() may reverse return value meaning
https://bugs.freedesktop.org/show_bug.cgi?id=100077

--- xf86atomic.h.orig	2019-03-12 11:55:31.000000000 +0000
+++ xf86atomic.h
@@ -79,12 +79,20 @@ typedef struct {
 #define HAS_ATOMIC_OPS 1
 
 #if defined(__NetBSD__)
+#if defined(STRICT_XSRC_NETBSD)
+#define LIBDRM_ATOMIC_TYPE unsigned int
+#else /* !STRICT_XSRC_NETBSD */
 #define LIBDRM_ATOMIC_TYPE int
+#endif /*STRICT_XSRC_NETBSD */
 #else
 #define LIBDRM_ATOMIC_TYPE uint_t
 #endif
 
+#if defined(STRICT_XSRC_NETBSD)
+typedef struct { volatile LIBDRM_ATOMIC_TYPE atomic; } atomic_t;
+#else /* !STRICT_XSRC_NETBSD */
 typedef struct { LIBDRM_ATOMIC_TYPE atomic; } atomic_t;
+#endif /*STRICT_XSRC_NETBSD */
 
 # define atomic_read(x) (int) ((x)->atomic)
 # define atomic_set(x, val) ((x)->atomic = (LIBDRM_ATOMIC_TYPE)(val))
@@ -107,7 +115,11 @@ static inline int atomic_add_unless(atom
 	c = atomic_read(v);
 	while (c != unless && (old = atomic_cmpxchg(v, c, c + add)) != c)
 		c = old;
+#if defined(INVERT_ATOMIC_ADD_UNLESS)
+	return c != unless;
+#else
 	return c == unless;
+#endif
 }
 
 #endif
