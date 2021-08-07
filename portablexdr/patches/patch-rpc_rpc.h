$NetBSD$

Remove config.h include, unclear where that file is supposed to come
from but it breaks consumers when installed.

--- rpc/rpc.h.orig	2009-01-12 15:55:23.000000000 +0000
+++ rpc/rpc.h
@@ -1,3 +1,2 @@
-#include "config.h"
 #include <rpc/types.h>
 #include <rpc/xdr.h>
