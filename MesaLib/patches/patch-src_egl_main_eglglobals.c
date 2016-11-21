$NetBSD$

atexit() is not a good idea in shared libraries.

--- src/egl/main/eglglobals.c.orig	2016-11-10 22:05:17.000000000 +0000
+++ src/egl/main/eglglobals.c
@@ -72,11 +72,16 @@ struct _egl_global _eglGlobal =
    _EGL_DEBUG_BIT_CRITICAL | _EGL_DEBUG_BIT_ERROR, /* debugTypesEnabled */
 };
 
+static EGLBoolean registered = EGL_FALSE;
 
-static void
+static void __attribute__((__destructor__))
 _eglAtExit(void)
 {
    EGLint i;
+
+   if (!registered)
+     return;
+
    for (i = _eglGlobal.NumAtExitCalls - 1; i >= 0; i--)
       _eglGlobal.AtExitCalls[i]();
 }
@@ -86,14 +91,9 @@ void
 _eglAddAtExitCall(void (*func)(void))
 {
    if (func) {
-      static EGLBoolean registered = EGL_FALSE;
-
       mtx_lock(_eglGlobal.Mutex);
 
-      if (!registered) {
-         atexit(_eglAtExit);
-         registered = EGL_TRUE;
-      }
+      registered = EGL_TRUE;
 
       assert(_eglGlobal.NumAtExitCalls < ARRAY_SIZE(_eglGlobal.AtExitCalls));
       _eglGlobal.AtExitCalls[_eglGlobal.NumAtExitCalls++] = func;
