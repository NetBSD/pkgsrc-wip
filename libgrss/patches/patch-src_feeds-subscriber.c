$NetBSD: patch-src_feeds-subscriber.c,v 1.1 2014/11/25 12:51:28 thomasklausner Exp $

Fix build on NetBSD (inet_pton).

--- src/feeds-subscriber.c.orig	2012-03-04 00:55:20.000000000 +0000
+++ src/feeds-subscriber.c
@@ -18,6 +18,8 @@
  * Boston, MA  02110-1301, USA.
  */
 
+#include <arpa/inet.h>
+
 #include "feeds-subscriber.h"
 #include "feeds-subscriber-handler.h"
 #include "feeds-pubsubhubbub-subscriber.h"
