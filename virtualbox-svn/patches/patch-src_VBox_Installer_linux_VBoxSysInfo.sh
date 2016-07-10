$NetBSD$

--- src/VBox/Installer/linux/VBoxSysInfo.sh.orig	2016-03-04 19:29:33.000000000 +0000
+++ src/VBox/Installer/linux/VBoxSysInfo.sh
@@ -109,6 +109,12 @@ get_freebsd_info () {
     echo "Kernel: $kernel"
 }
 
+# Print information about a NetBSD system.  FIXME.
+get_netbsd_info () {
+    kernel=`uname -v`
+    echo "Kernel: $kernel"
+}
+
 system=`uname -s`
 case "$system" in
 Linux|linux)
@@ -123,6 +129,9 @@ Darwin)
 FreeBSD)
     get_freebsd_info
     ;;
+NetBSD)
+    get_netbsd_info
+    ;;
 *)
     echo "System unknown"
     exit 1
