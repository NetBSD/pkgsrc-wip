$NetBSD: patch-src_egl_main_eglglobals.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

From NetBSD xsrc:
The third argument of mincore(2) is unsigned only on linux.

--- src/egl/main/eglglobals.c.orig	2019-05-03 15:59:12.000000000 +0000
+++ src/egl/main/eglglobals.c
@@ -93,11 +93,22 @@ struct _egl_global _eglGlobal =
    .debugTypesEnabled = _EGL_DEBUG_BIT_CRITICAL | _EGL_DEBUG_BIT_ERROR,
 };
 
+#if defined(HAVE_NOATEXIT)
+static EGLBoolean registered = EGL_FALSE;
 
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 _eglAtExit(void)
 {
    EGLint i;
+
+#if defined(HAVE_NOATEXIT)
+   if (!registered)
+      return;
+#endif
+
    for (i = _eglGlobal.NumAtExitCalls - 1; i >= 0; i--)
       _eglGlobal.AtExitCalls[i]();
 }
@@ -107,14 +118,20 @@ void
 _eglAddAtExitCall(void (*func)(void))
 {
    if (func) {
+#if !defined(HAVE_NOATEXIT)
       static EGLBoolean registered = EGL_FALSE;
+#endif
 
       mtx_lock(_eglGlobal.Mutex);
 
+#if defined(HAVE_NOATEXIT)
+      registered = EGL_TRUE;
+#else
       if (!registered) {
          atexit(_eglAtExit);
          registered = EGL_TRUE;
       }
+#endif
 
       assert(_eglGlobal.NumAtExitCalls < ARRAY_SIZE(_eglGlobal.AtExitCalls));
       _eglGlobal.AtExitCalls[_eglGlobal.NumAtExitCalls++] = func;
@@ -162,7 +179,10 @@ _eglPointerIsDereferencable(void *p)
 {
 #ifdef HAVE_MINCORE
    uintptr_t addr = (uintptr_t) p;
-   unsigned char valid = 0;
+#ifdef __linux__
+   unsigned
+#endif
+   char valid = 0;
    const long page_size = getpagesize();
 
    if (p == NULL)
