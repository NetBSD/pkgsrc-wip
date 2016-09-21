$NetBSD$

Get rid of Bash

--- bin/get_version.sh.orig	2016-09-14 18:39:15.000000000 +0000
+++ bin/get_version.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 #
 # Usage: get_version.sh --version|--release|--full
 #
@@ -11,16 +11,16 @@ GITVER=$(cd $TOOLDIR ; git describe --ta
 if [ -z "$GITVER" ] ; then
 	# Get version information from file
 	if [ -e "$TOOLDIR/../.version" ] ; then
-		source "$TOOLDIR/../.version"
+		. "$TOOLDIR/../.version"
 	fi
 else
 	# Get version information from git
-	FULL=${GITVER:1}
+	FULL=${GITVER#?}
 	VERSION=${GITVER%%-*}
-	VERSION=${VERSION:1}
+	VERSION=${VERSION#?}
 	if [ "${GITVER#*-}" != "$GITVER" ] ; then
 		RELEASE=${GITVER#*-}
-		RELEASE=${RELEASE/-/.}
+		RELEASE=$(echo $RELEASE | tr - .)
 	fi
 fi
 
@@ -29,6 +29,6 @@ fi
 [ -z "$RELEASE" ] && RELEASE="1"
 [ -z "$FULL" ]    && FULL="$VERSION"
 
-[ "$1" == "--version" ] && echo -n "$VERSION"
-[ "$1" == "--release" ] && echo -n "$RELEASE"
-[ "$1" == "--full"    ] && echo -n "$FULL"
+[ "$1" = "--version" ] && echo -n "$VERSION"
+[ "$1" = "--release" ] && echo -n "$RELEASE"
+[ "$1" = "--full"    ] && echo -n "$FULL"
