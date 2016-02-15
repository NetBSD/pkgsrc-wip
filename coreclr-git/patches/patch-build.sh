$NetBSD$

--- build.sh.orig	2016-02-12 01:41:34.000000000 +0000
+++ build.sh
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/usr/pkg/bin/bash
 
 PYTHON=${PYTHON:-python}
 
@@ -204,7 +204,7 @@ isMSBuildOnNETCoreSupported()
                     __isMSBuildOnNETCoreSupported=1
                 fi 
             fi
-        elif [ "$__BuildOS" == "OSX" ]; then
+        elif [ "$__BuildOS" == "NetBSD" -o "$__BuildOS" == "OSX" ]; then
             __isMSBuildOnNETCoreSupported=1
         fi 
     fi
