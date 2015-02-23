$NetBSD: patch-deps_node__package_priv_base_env.sh,v 1.4 2015/02/23 17:32:17 fhajny Exp $

Substitute whoami for id across SunOS platforms.
Let us substitute run dir.

--- deps/node_package/priv/base/env.sh.orig	2015-02-11 20:15:28.000000000 +0000
+++ deps/node_package/priv/base/env.sh
@@ -30,7 +30,7 @@ APP_VERSION={{app_version}}
 # Variables needed to support creation of .pid files
 # PID directory and pid file name of this app
 # ex: /var/run/riak & /var/run/riak/riak.pid
-RUN_DIR="/var/run" # for now hard coded unless we find a platform that differs
+RUN_DIR="@RIAK_RUN@" # for now hard coded unless we find a platform that differs
 PID_DIR=$RUN_DIR/$RUNNER_SCRIPT
 PID_FILE=$PID_DIR/$RUNNER_SCRIPT.pid
 
@@ -44,7 +44,11 @@ fi
 # Registered process to wait for to consider start a success
 WAIT_FOR_PROCESS={{runner_wait_process}}
 
-WHOAMI=`whoami`
+if [ `uname -s` = 'SunOS' ]; then
+    WHOAMI=$(/usr/xpg4/bin/id -un)
+else
+    WHOAMI=$(whoami)
+fi
 
 # Echo to stderr on errors
 echoerr() { echo "$@" 1>&2; }
