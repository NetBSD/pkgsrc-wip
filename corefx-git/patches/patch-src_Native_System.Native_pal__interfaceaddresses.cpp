$NetBSD$

--- src/Native/System.Native/pal_interfaceaddresses.cpp.orig	2016-02-07 13:49:29.000000000 +0000
+++ src/Native/System.Native/pal_interfaceaddresses.cpp
@@ -8,6 +8,7 @@
 #include "pal_utilities.h"
 
 #include <assert.h>
+#include <sys/types.h>
 #include <ifaddrs.h>
 #include <net/if.h>
 #include <netinet/in.h>
