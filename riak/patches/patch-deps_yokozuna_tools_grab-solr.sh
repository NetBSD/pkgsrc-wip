$NetBSD$

Don't download, distfile already there.

--- deps/yokozuna/tools/grab-solr.sh.orig	2015-11-17 15:14:49.000000000 +0000
+++ deps/yokozuna/tools/grab-solr.sh
@@ -72,18 +72,6 @@ get_solr()
 if ! check_for_solr
 then
 
-    echo "Create dir $BUILD_DIR"
-    if [ ! -e $BUILD_DIR ]; then
-        mkdir $BUILD_DIR
-    fi
-
-    cd $BUILD_DIR
-
-    if [ ! -e $SRC_DIR ]
-    then
-        get_solr
-    fi
-
     echo "Creating Solr dir $SOLR_DIR"
 
     # Explicitly copy files needed rather than copying everything and
