$NetBSD$

Add NetBSD support.

--- conda-recipes/llvmdev/build.sh.orig	2016-08-24 14:49:54.000000000 +0000
+++ conda-recipes/llvmdev/build.sh
@@ -13,6 +13,8 @@ if [[ "$unamestr" == 'Linux' ]]; then
     platform='linux'
 elif [[ "$unamestr" == 'FreeBSD' ]]; then
     platform='freebsd'
+elif [[ "$unamestr" == 'NetBSD' ]]; then
+    platform='netbsd'
 elif [[ "$unamestr" == 'Darwin' ]]; then
     platform='osx'
 fi
