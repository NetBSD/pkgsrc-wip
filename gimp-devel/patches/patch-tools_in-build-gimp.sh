$NetBSD$

--- tools/in-build-gimp.sh.orig	2025-02-11 10:03:42.336326539 +0000
+++ tools/in-build-gimp.sh
@@ -26,10 +26,10 @@ fi
 
 if command -v gdb; then
   echo RUNNING: cat /dev/stdin "|" gdb --batch -x "$GIMP_GLOBAL_SOURCE_ROOT/tools/debug-in-build-gimp.py" --args $GIMP_SELF_IN_BUILD "$@"
-  cat /dev/stdin | gdb --return-child-result --batch -x "$GIMP_GLOBAL_SOURCE_ROOT/tools/debug-in-build-gimp.py" --args $GIMP_SELF_IN_BUILD "$@"
+  cat /dev/stdin | LD_LIBRARY_PATH=${GIMP_GLOBAL_BUILD_ROOT}/libgimp:${GIMP_GLOBAL_BUILD_ROOT}/libgimpbase:${GIMP_GLOBAL_BUILD_ROOT}/libgimpcolor:${GIMP_GLOBAL_BUILD_ROOT}/libgimpconfig:${GIMP_GLOBAL_BUILD_ROOT}/libgimpmath:${GIMP_GLOBAL_BUILD_ROOT}/libgimpmodule:${GIMP_GLOBAL_BUILD_ROOT}/libgimpthumb:${GIMP_GLOBAL_BUILD_ROOT}/libgimpwidgets gdb --return-child-result --batch -x "$GIMP_GLOBAL_SOURCE_ROOT/tools/debug-in-build-gimp.py" --args $GIMP_SELF_IN_BUILD "$@"
 else
   echo RUNNING: cat /dev/stdin "|" $GIMP_SELF_IN_BUILD "$@"
-  cat /dev/stdin | $GIMP_SELF_IN_BUILD "$@"
+  cat /dev/stdin | LD_LIBRARY_PATH=${GIMP_GLOBAL_BUILD_ROOT}/libgimp:${GIMP_GLOBAL_BUILD_ROOT}/libgimpbase:${GIMP_GLOBAL_BUILD_ROOT}/libgimpcolor:${GIMP_GLOBAL_BUILD_ROOT}/libgimpconfig:${GIMP_GLOBAL_BUILD_ROOT}/libgimpmath:${GIMP_GLOBAL_BUILD_ROOT}/libgimpmodule:${GIMP_GLOBAL_BUILD_ROOT}/libgimpthumb:${GIMP_GLOBAL_BUILD_ROOT}/libgimpwidgets $GIMP_SELF_IN_BUILD "$@"
 fi
 
 if [ -n "$GIMP_TEMP_UPDATE_RPATH" ]; then
