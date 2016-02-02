# $NetBSD$
--- ./install.sh.orig	2016-02-01 19:35:39.000000000 -0800
+++ ./install.sh	2016-02-01 19:43:27.000000000 -0800
@@ -39,13 +39,12 @@
       datadir=/usr/local/share/nim/data
       ;;
     *)
-      bindir="$1/nim/bin"
-      configdir="$1/nim/config"
-      libdir="$1/nim/lib"
-      docdir="$1/nim/doc"
-      datadir="$1/nim/data"
+      bindir="$1/bin"
+      configdir="$1/share/nim/config"
+      libdir="$1/lib/nim"
+      docdir="$1/share/doc/nim"
+      datadir="$1/share/nim/data"
       
-      mkdir -p $1/nim
       mkdir -p $bindir
       mkdir -p $configdir
       ;;
