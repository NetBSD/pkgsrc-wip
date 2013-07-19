$NetBSD: patch-deps_node__package_priv_base_env.sh,v 1.1 2013/07/19 10:38:57 fhajny Exp $

Substitute whoami for id across SunOS platforms.
Silence sudo (unneeded screen waste).
--- deps/node_package/priv/base/env.sh.orig	2013-07-09 22:00:35.000000000 +0000
+++ deps/node_package/priv/base/env.sh
@@ -44,7 +44,11 @@ fi
 # Registered process to wait for to consider start a success
 WAIT_FOR_PROCESS={{runner_wait_process}}
 
-WHOAMI=$(whoami)
+if [ `uname -s` = 'SunOS' ]; then
+    WHOAMI=$(/usr/xpg4/bin/id -un)
+else
+    WHOAMI=$(whoami)
+fi
 
 # Echo to stderr on errors
 echoerr() { echo "$@" 1>&2; }
@@ -166,7 +170,7 @@ check_user() {
             echoerr "sudo doesn't appear to be installed and your EUID isn't $RUNNER_USER" 1>&2
             exit 1
         fi
-        exec sudo -H -u $RUNNER_USER -i $RUNNER_SCRIPT_DIR/$RUNNER_SCRIPT $@
+        exec sudo -H -u $RUNNER_USER $RUNNER_SCRIPT_DIR/$RUNNER_SCRIPT $@
     fi
 }
 
