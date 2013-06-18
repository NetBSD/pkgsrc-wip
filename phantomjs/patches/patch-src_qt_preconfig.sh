$NetBSD: patch-src_qt_preconfig.sh,v 1.1 2013/06/18 11:02:23 fhajny Exp $

Add support for SunOS. Only configure here, delegate build to pkgsrc.
--- src/qt/preconfig.sh.orig	2013-06-03 23:11:50.000000000 +0000
+++ src/qt/preconfig.sh
@@ -1,5 +1,7 @@
 #!/usr/bin/env bash
 
+set -e
+
 COMPILE_JOBS=4
 
 QT_CFG=''
@@ -18,6 +20,14 @@ else
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
@@ -107,9 +117,3 @@ done
 export MAKEFLAGS=-j$COMPILE_JOBS
 
 ./configure -prefix $PWD $QT_CFG
-make -j$COMPILE_JOBS
-
-# Build text codecs
-pushd src/plugins/codecs/
-make -j$COMPILE_JOBS
-popd
