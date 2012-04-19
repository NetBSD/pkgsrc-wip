$NetBSD: patch-bin_zkServer.sh,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $

Use awk instead of grep/sed, and Bash echo for better portability.
--- bin/zkServer.sh.orig	2012-02-06 10:48:39.000000000 +0000
+++ bin/zkServer.sh
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/usr/bin/bash
 
 # Licensed to the Apache Software Foundation (ASF) under one or more
 # contributor license agreements.  See the NOTICE file distributed with
@@ -81,7 +81,7 @@ fi
 echo "Using config: $ZOOCFG" >&2
 
 if [ -z $ZOOPIDFILE ]; then
-    ZOO_DATADIR=$(grep "^[[:space:]]*dataDir" "$ZOOCFG" | sed -e 's/.*=//')
+    ZOO_DATADIR=$(awk -F= '{ if ($1=="dataDir") print $2}' "$ZOOCFG")
     if [ ! -d "$ZOO_DATADIR" ]; then
         mkdir -p "$ZOO_DATADIR"
     fi
@@ -106,7 +106,7 @@ start)
     -cp "$CLASSPATH" $JVMFLAGS $ZOOMAIN "$ZOOCFG" > "$_ZOO_DAEMON_OUT" 2>&1 < /dev/null &
     if [ $? -eq 0 ]
     then
-      if /bin/echo -n $! > "$ZOOPIDFILE"
+      if echo -n $! > "$ZOOPIDFILE"
       then
         sleep 1
         echo STARTED
@@ -155,7 +155,7 @@ status)
     # -q is necessary on some versions of linux where nc returns too quickly, and no stat result is output
     STAT=`$JAVA "-Dzookeeper.log.dir=${ZOO_LOG_DIR}" "-Dzookeeper.root.logger=${ZOO_LOG4J_PROP}" \
              -cp "$CLASSPATH" $JVMFLAGS org.apache.zookeeper.client.FourLetterWordMain localhost \
-             $(grep "^[[:space:]]*clientPort" "$ZOOCFG" | sed -e 's/.*=//') srvr 2> /dev/null    \
+             $(awk -F= '{if ($1=="clientPort") print $2}' "$ZOOCFG") srvr 2> /dev/null    \
           | grep Mode`
     if [ "x$STAT" = "x" ]
     then
