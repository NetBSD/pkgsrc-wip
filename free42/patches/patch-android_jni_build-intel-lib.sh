$NetBSD$

Remediate bashism.

--- android/jni/build-intel-lib.sh.orig	2018-06-24 18:40:42.000000000 +0000
+++ android/jni/build-intel-lib.sh
@@ -4,7 +4,7 @@ if [ -f libgcc111libbid.a ]; then exit 0
 
 mkdir bin
 export PATH="`/bin/pwd`/bin:$PATH"
-if [ `hostname` == "air" ]
+if [ `hostname` = "air" ]
 then
     TOOLCHAIN=arm-linux-androideabi-4.8
 else
