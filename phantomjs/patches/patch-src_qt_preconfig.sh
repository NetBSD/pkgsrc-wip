$NetBSD: patch-src_qt_preconfig.sh,v 1.2 2015/01/09 14:03:41 fhajny Exp $

Add support for SunOS. Only configure here, delegate build to pkgsrc.
--- src/qt/preconfig.sh.orig	2014-10-23 04:27:58.000000000 +0000
+++ src/qt/preconfig.sh
@@ -1,6 +1,6 @@
 #!/usr/bin/env bash
 
-COMPILE_JOBS=4
+set -e
 
 QT_CFG=''
 QT_CFG+=' -opensource'          # Use the open-source license
@@ -18,6 +18,14 @@ else
     QT_CFG+=' -qpa'             # X11-less with QPA (aka Lighthouse)
 fi
 
+if [[ $OSTYPE = solaris* ]]; then
+    if [[ $MACHINE_ARCH = x86_64 ]]; then
+        QT_CFG+=' -platform solaris-g++-64'
+    else
+        QT_CFG+=' -platform solaris-g++'
+    fi
+fi
+
 QT_CFG+=' -release'             # Build only for release (no debugging support)
 QT_CFG+=' -fast'                # Accelerate Makefiles generation
 QT_CFG+=' -nomake demos'        # Don't build with the demos
