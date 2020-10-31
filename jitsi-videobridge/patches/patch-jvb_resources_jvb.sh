$NetBSD$

Remove requirement on bash.

--- jvb/resources/jvb.sh.orig	2020-10-13 19:37:04.000000000 +0000
+++ jvb/resources/jvb.sh
@@ -1,6 +1,6 @@
-#!/bin/bash
+#!/bin/sh
 
-if [[ "$1" == "--help"  || $# -lt 1 ]]; then
+if [ "$1" = "--help" -o $# -lt 1 ]; then
     echo -e "Usage:"
     echo -e "$0 [OPTIONS], where options can be:"
     echo -e "\t--apis=APIS where APIS is a comma separated list of APIs to enable. Currently the only supported API is 'rest'. The default is none."
