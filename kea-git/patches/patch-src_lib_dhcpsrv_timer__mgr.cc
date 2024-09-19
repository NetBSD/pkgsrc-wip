$NetBSD$

* include map to fix build breaks since std::map is used

--- src/lib/dhcpsrv/timer_mgr.cc.orig	2020-12-12 08:24:07.447946607 +0000
+++ src/lib/dhcpsrv/timer_mgr.cc
@@ -15,6 +15,7 @@
 #include <boost/scoped_ptr.hpp>
 
 #include <functional>
+#include <map>
 #include <utility>
 
 using namespace isc;
