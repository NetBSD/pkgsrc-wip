$NetBSD$

Remove requirement on bash.

--- resources/jicofo.sh.orig	2020-10-13 17:13:04.000000000 +0000
+++ resources/jicofo.sh
@@ -1,6 +1,6 @@
-#!/bin/bash
+#!/bin/sh
 
-if [[ "$1" == "--help"  || $# -lt 1 ]]; then
+if [ "$1" = "--help" -o $# -lt 1 ]; then
     echo -e "Usage:"
     echo -e "$0 [OPTIONS], where options can be:"
     echo -e "\t--host=HOST\t sets the hostname of the XMPP server (default: domain, if domain is set, localhost otherwise)"
