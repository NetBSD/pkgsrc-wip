$NetBSD$

--- scripts/bootstrap/buildenv.sh.orig	2023-11-28 16:39:24.563015783 +0000
+++ scripts/bootstrap/buildenv.sh
@@ -93,6 +93,11 @@ freebsd)
   JAVA_HOME="${JAVA_HOME:-/usr/local/openjdk11}"
   ;;
 
+netbsd)
+  # JAVA_HOME must point to a Java installation.
+  JAVA_HOME="${JAVA_HOME:-/usr/pkg/java/openjdk11}"
+  ;;
+
 openbsd)
   # JAVA_HOME must point to a Java installation.
   JAVA_HOME="${JAVA_HOME:-/usr/local/jdk-11}"
