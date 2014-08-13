$NetBSD: patch-plugins_imuxsock_imuxsock.c,v 1.2 2014/08/13 10:51:04 fhajny Exp $

Define _XPG4_2 on SunOS to pick up CMSG_* macros.

--- plugins/imuxsock/imuxsock.c.orig	2014-06-02 09:53:18.000000000 +0000
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
