$NetBSD: patch-build_linux_python__arch.sh,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- build/linux/python_arch.sh.orig	2011-05-24 08:01:31.000000000 +0000
+++ build/linux/python_arch.sh
@@ -10,7 +10,7 @@
 #  python_arch.sh /path/to/sysroot/usr/lib/libpython2.4.so.1.0
 #
 
-python=$(readlink -f "$1")
+python=$(readlink "$1")
 if [ ! -r "$python" ]; then
   echo unknown
   exit 0;
