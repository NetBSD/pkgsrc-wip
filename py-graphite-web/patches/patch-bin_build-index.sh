$NetBSD: patch-bin_build-index.sh,v 1.1 2015/12/11 21:45:07 riz Exp $

Fix default paths.
--- bin/build-index.sh.orig	2019-08-05 16:56:40.170903148 +0000
+++ bin/build-index.sh
@@ -1,5 +1,5 @@
 #!/bin/bash
-export PYTHONPATH="/opt/graphite/webapp/:$PYTHONPATH"
+export PYTHONPATH="@GRAPHITE_DIR@/webapp/:$PYTHONPATH"
 BINDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
 
 ${BINDIR}/build-index
