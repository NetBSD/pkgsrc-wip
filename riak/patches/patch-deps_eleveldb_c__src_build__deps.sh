$NetBSD: patch-deps_eleveldb_c__src_build__deps.sh,v 1.1 2014/11/28 20:38:31 fhajny Exp $

Do not detect lzf includes, breaks on NetBSD.
--- deps/eleveldb/c_src/build_deps.sh.orig	2016-04-12 14:46:02.000000000 +0000
+++ deps/eleveldb/c_src/build_deps.sh
@@ -67,7 +67,7 @@ case "$1" in
     *)
         if [ ! -d snappy-$SNAPPY_VSN ]; then
             tar -xzf snappy-$SNAPPY_VSN.tar.gz
-            (cd snappy-$SNAPPY_VSN && ./configure --prefix=$BASEDIR/system --libdir=$BASEDIR/system/lib --with-pic)
+            (cd snappy-$SNAPPY_VSN && ./configure --prefix=$BASEDIR/system --libdir=$BASEDIR/system/lib --with-pic ac_cv_lib_lzf_lzf_compress=no)
         fi
 
         if [ ! -f system/lib/libsnappy.a ]; then
