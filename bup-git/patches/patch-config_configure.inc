$NetBSD: patch-config_configure.inc,v 1.1 2015/07/05 20:46:45 thomasklausner Exp $

--- config/configure.inc.orig	2015-07-05 20:33:32.000000000 +0000
+++ config/configure.inc
@@ -1287,7 +1287,11 @@ AC_MAK() {
 #
 # AC_DEFINE adds a #define to config.h
 AC_DEFINE() {
-    echo "#define $1 ${2:-1}" >> $__cwd/config.h.tmp
+    local name="$1" value="${2:-1}"
+    if ! printf -v "ac_defined_$name" '%s' "$value"; then
+        AC_FATAL 'AC_DEFINE unable to set "ac_defined_$name" to "$value"'
+    fi
+    echo "#define $name $value" >> $__cwd/config.h.tmp
 }
 
 #
