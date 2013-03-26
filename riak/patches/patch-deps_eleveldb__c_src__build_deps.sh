$NetBSD: patch-deps_eleveldb__c_src__build_deps.sh,v 1.1 2013/03/26 20:46:28 fhajny Exp $

Let pkgsrc pass in its own libtool.

--- deps/eleveldb/c_src/build_deps.sh.orig	2012-09-07 20:17:01.000000000 +0000
+++ deps/eleveldb/c_src/build_deps.sh
@@ -68,6 +68,7 @@ case "$1" in
     *)
         if [ ! -d snappy-$SNAPPY_VSN ]; then
             tar -xzf snappy-$SNAPPY_VSN.tar.gz
+            (cd snappy-$SNAPPY_VSN && patch -p0 < ../snappy-libtool.patch)
             (cd snappy-$SNAPPY_VSN && ./configure --prefix=$BASEDIR/system --with-pic)
         fi
 
