$NetBSD$

--- scripts/qemu-binfmt-conf.sh.orig	2017-03-31 14:07:03.000000000 +0000
+++ scripts/qemu-binfmt-conf.sh
@@ -279,12 +279,12 @@ while true ; do
         shift
         # check given cpu is in the supported CPU list
         for cpu in ${qemu_target_list} ; do
-            if [ "$cpu" == "$1" ] ; then
+            if [ "$cpu" = "$1" ] ; then
                 break
             fi
         done
 
-        if [ "$cpu" == "$1" ] ; then
+        if [ "$cpu" = "$1" ] ; then
             qemu_target_list="$1"
         else
             echo "ERROR: unknown CPU \"$1\"" 1>&2
