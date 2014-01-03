$NetBSD: patch-deps_eleveldb__c_src__build_deps.sh,v 1.2 2014/01/03 16:43:47 fhajny Exp $

Let pkgsrc pass in its own libtool.

--- deps/eleveldb/c_src/build_deps.sh.orig	2013-12-20 17:45:04.000000000 +0000
+++ deps/eleveldb/c_src/build_deps.sh
@@ -62,6 +62,7 @@ case "$1" in
     *)
         if [ ! -d snappy-$SNAPPY_VSN ]; then
             tar -xzf snappy-$SNAPPY_VSN.tar.gz
+            (cd snappy-$SNAPPY_VSN && patch -p0 < ../snappy-libtool.patch)
             (cd snappy-$SNAPPY_VSN && ./configure --prefix=$BASEDIR/system --libdir=$BASEDIR/system/lib --with-pic)
         fi
 
