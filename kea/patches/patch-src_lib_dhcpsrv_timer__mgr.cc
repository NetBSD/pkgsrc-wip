$NetBSD$

* include map to not break build since std::map is used

--- src/lib/dhcpsrv/timer_mgr.cc.orig	2020-10-22 14:29:38.523508022 +0000
+++ src/lib/dhcpsrv/timer_mgr.cc
@@ -12,6 +12,7 @@
 #include <exceptions/exceptions.h>
 
 #include <functional>
+#include <map>
 #include <utility>
 
 using namespace isc;
