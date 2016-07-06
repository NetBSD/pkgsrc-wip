$NetBSD$

--- regress/nightly.sh.orig	2014-06-02 15:46:30.000000000 +0000
+++ regress/nightly.sh
@@ -45,7 +45,7 @@ export LOG_FILE=`pwd`/${MYNAME}_${START_
 #
 # if we are the master host, get things set up
 #
-if [ X$MYNAME == X$MASTERHOST ] ; then
+if [ X$MYNAME = X$MASTERHOST ] ; then
     echo "fetching archive"
 
     # Delete any leftovers
