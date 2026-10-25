$NetBSD$

* Add support to NetBSD and FreeBSD

--- resources/server/bin/helpers/check-requirements-linux.sh.orig	2026-10-14 09:52:01.000000000 +0000
+++ resources/server/bin/helpers/check-requirements-linux.sh
@@ -24,6 +24,7 @@ if [ -f "/tmp/vscode-skip-server-require
 fi
 
 ARCH=$(uname -m)
+UNAME=$(uname)
 found_required_glibc=0
 found_required_glibcxx=0
 MIN_GLIBCXX_VERSION="3.4.25"
@@ -34,8 +35,15 @@ if [ -f /etc/os-release ]; then
     if [ "$OS_ID" = "nixos" ]; then
         echo "Warning: NixOS detected, skipping GLIBC check"
         exit 0
+    elif [ "$OS_ID" = "freebsd" ]; then
+        echo "Warning: FreeBSD detected, skipping GLIBC check"
+        exit 0
     fi
 fi
+if [ "$UNAME" = "NetBSD" ]; then
+    echo "Warning:NetBSD detected, skipping GLIBC check"
+    exit 0
+fi
 
 # Based on https://github.com/bminor/glibc/blob/520b1df08de68a3de328b65a25b86300a7ddf512/elf/cache.c#L162-L245
 case $ARCH in
