$NetBSD$

Only include local sendfile header if there is sendfile support, to
avoid #error for no sendfile implementation.

--- src/zm_eventstream.cpp.orig	2018-12-08 14:22:36.000000000 +0000
+++ src/zm_eventstream.cpp
@@ -39,7 +39,9 @@
 #include "zm_storage.h"
 #include "zm_monitor.h"
 
+#if HAVE_SENDFILE
 #include "zm_sendfile.h"
+#endif
 
 bool EventStream::loadInitialEventData( int monitor_id, time_t event_time ) {
   static char sql[ZM_SQL_SML_BUFSIZ];
