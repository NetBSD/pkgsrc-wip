$NetBSD: patch-src_egl_main_eglglobals.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/egl/main/eglglobals.c.orig	2019-03-15 01:02:19.000000000 +0000
+++ src/egl/main/eglglobals.c
@@ -93,11 +93,23 @@ struct _egl_global _eglGlobal =
    .debugTypesEnabled = _EGL_DEBUG_BIT_CRITICAL | _EGL_DEBUG_BIT_ERROR,
 };
 
+#if defined(HAVE_NOATEXIT)
+/* static EGLBoolean registered = EGL_FALSE; */
+static int add_atexit_called = 0;
 
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 _eglAtExit(void)
 {
    EGLint i;
+
+#if defined(HAVE_NOATEXIT)
+   if (!add_atexit_called)
+      return;
+#endif
+
    for (i = _eglGlobal.NumAtExitCalls - 1; i >= 0; i--)
       _eglGlobal.AtExitCalls[i]();
 }
@@ -106,15 +118,26 @@ _eglAtExit(void)
 void
 _eglAddAtExitCall(void (*func)(void))
 {
+#if 0
+   static EGLBoolean registered = EGL_FALSE;
+#endif
+
    if (func) {
+#if 1
       static EGLBoolean registered = EGL_FALSE;
+#endif
 
       mtx_lock(_eglGlobal.Mutex);
 
+#if defined(HAVE_NOATEXIT)
+      add_atexit_called = 1;
+      registered = EGL_TRUE;
+#else
       if (!registered) {
          atexit(_eglAtExit);
          registered = EGL_TRUE;
       }
+#endif
 
       assert(_eglGlobal.NumAtExitCalls < ARRAY_SIZE(_eglGlobal.AtExitCalls));
       _eglGlobal.AtExitCalls[_eglGlobal.NumAtExitCalls++] = func;
