$NetBSD: patch-ext__common__EventedMessageServer.h,v 1.2 2012/05/11 09:14:40 fhajny Exp $

Explicitly error out if HAS_ALLOCA_H_ not defined.
--- ext/common/EventedMessageServer.h.orig	2011-11-28 11:51:11.000000000 +0000
+++ ext/common/EventedMessageServer.h
@@ -31,6 +31,8 @@
 #include <cstdlib>
 #ifdef HAS_ALLOCA_H_
 	#include <alloca.h>
+#else
+	#error "alloca is required."
 #endif
 #include "EventedServer.h"
 #include "MessageReadersWriters.h"
