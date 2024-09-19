$NetBSD: patch-xbmc_windowing_WindowingFactory.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

Add NetBSD & FreeBSD sanely

--- xbmc/windowing/WindowingFactory.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/windowing/WindowingFactory.h
@@ -23,32 +23,27 @@
 
 #include "system.h"
 
-#if   defined(TARGET_WINDOWS) && defined(HAS_GL)
-#include "windows/WinSystemWin32GL.h"
-
-#elif defined(TARGET_WINDOWS) && defined(HAS_DX)
-#include "windows/WinSystemWin32DX.h"
-
-#elif defined(TARGET_LINUX)   && defined(HAVE_X11)   && defined(HAS_GLES)
-#include "X11/WinSystemX11GLESContext.h"
-
-#elif defined(TARGET_LINUX)   && defined(HAVE_X11)   && defined(HAS_GL)
-#include "X11/WinSystemX11GLContext.h"
-
-#elif defined(TARGET_LINUX)   && defined(HAS_GLES) && defined(HAS_EGL) && !defined(HAVE_X11)
-#include "egl/WinSystemEGL.h"
-
-#elif defined(TARGET_FREEBSD)   && defined(HAS_GL)   && defined(HAVE_X11)
-#include "X11/WinSystemX11GL.h"
-
-#elif defined(TARGET_FREEBSD) && defined(HAS_GLES) && defined(HAS_EGL)
-#include "egl/WinSystemGLES.h"
+#if defined(TARGET_WINDOWS)
+#  if defined(HAS_GL)
+#    include "windows/WinSystemWin32GL.h"
+#  elif defined(HAS_DX)
+#    include "windows/WinSystemWin32DX.h"
+#  endif
+
+#elif defined(TARGET_LINUX) || defined(TARGET_NETBSD) || defined(TARGET_FREEBSD)
+#  if defined(HAVE_X11)   && defined(HAS_GLES)
+#    include "X11/WinSystemX11GLESContext.h"
+#  elif defined(HAVE_X11) && defined(HAS_GL)
+#    include "X11/WinSystemX11GLContext.h"
+#  elif !defined(HAVE_X11) && defined(HAS_GLES) && defined(HAS_EGL)
+#    include "egl/WinSystemEGL.h"
+#  endif
 
 #elif defined(TARGET_DARWIN_OSX)
-#include "osx/WinSystemOSXGL.h"
+#  include "osx/WinSystemOSXGL.h"
 
 #elif defined(TARGET_DARWIN_IOS)
-#include "osx/WinSystemIOS.h"
+#  include "osx/WinSystemIOS.h"
 
 #endif
 
