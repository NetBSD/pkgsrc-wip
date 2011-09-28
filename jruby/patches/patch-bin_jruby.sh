$NetBSD: patch-bin_jruby.sh,v 1.1.1.1 2011/09/28 12:00:46 ryo-on Exp $

* Improve portability

--- bin/jruby.sh.orig	2011-09-28 11:44:07.000000000 +0000
+++ bin/jruby.sh
@@ -38,13 +38,7 @@ while [ -h "$PRG" ] ; do
   fi
 done
 
-JRUBY_HOME_1=`dirname "$PRG"`           # the ./bin dir
-if [ "$JRUBY_HOME_1" = '.' ] ; then
-  cwd=`pwd`
-  JRUBY_HOME=`dirname $cwd` # JRUBY-2699
-else
-  JRUBY_HOME=`dirname "$JRUBY_HOME_1"`  # the . dir
-fi
+JRUBY_HOME=@JRUBY_HOME@
 
 if [ -z "$JRUBY_OPTS" ] ; then
   JRUBY_OPTS=""
@@ -116,10 +110,10 @@ if [ "$JRUBY_PARENT_CLASSPATH" != "" ]; 
 else
     # add other jars in lib to CP for command-line execution
     for j in "$JRUBY_HOME"/lib/*.jar; do
-        if [ "$j" == "$JRUBY_HOME"/lib/jruby.jar ]; then
+        if [ "$j" = "$JRUBY_HOME"/lib/jruby.jar ]; then
           continue
         fi
-        if [ "$j" == "$JRUBY_HOME"/lib/jruby-complete.jar ]; then
+        if [ "$j" = "$JRUBY_HOME"/lib/jruby-complete.jar ]; then
           continue
         fi
         if [ "$CP" ]; then
