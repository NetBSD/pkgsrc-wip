$NetBSD: patch-plugins_imuxsock_imuxsock.c,v 1.1 2014/07/28 10:59:10 fhajny Exp $

Define _XPG4_2 on SunOS to pick up CMSG_* macros.

--- plugins/imuxsock/imuxsock.c.orig	2013-09-03 10:31:42.000000000 +0000
+++ plugins/imuxsock/imuxsock.c
@@ -25,6 +25,9 @@
  *
  * A copy of the GPL can be found in the file "COPYING" in this distribution.
  */
+#ifdef __sun
+#define _XPG4_2
+#endif
 #include "config.h"
 #include "rsyslog.h"
 #include <stdlib.h>
