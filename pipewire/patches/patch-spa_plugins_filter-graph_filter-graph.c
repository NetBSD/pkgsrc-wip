$NetBSD$

--- spa/plugins/filter-graph/filter-graph.c.orig	2025-07-29 19:42:37.820319590 +0000
+++ spa/plugins/filter-graph/filter-graph.c
@@ -31,6 +31,10 @@
 #include <spa/debug/log.h>
 #include <spa/filter-graph/filter-graph.h>
 
+#if defined(__NetBSD__)
+#define strdupa(s) strdup(s)
+#endif
+
 #include "audio-plugin.h"
 #include "audio-dsp-impl.h"
 
