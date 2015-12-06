$NetBSD$

--- 3rdparty/google-breakpad/src/third_party/protobuf/protobuf/post_process_dist.sh.orig	2015-11-02 13:52:00.000000000 +0000
+++ 3rdparty/google-breakpad/src/third_party/protobuf/protobuf/post_process_dist.sh
@@ -15,7 +15,7 @@
 #    non-testdata .txt files are converted to Windows-style line endings.
 # 5) Cleans up after itself.
 
-if [ "$1" == "" ]; then
+if [ "$1" = "" ]; then
   echo "USAGE:  $1 DISTFILE" >&2
   exit 1
 fi
