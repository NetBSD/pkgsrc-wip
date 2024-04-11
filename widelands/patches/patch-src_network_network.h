$NetBSD$

Fix building against boost.

--- src/network/network.h.orig	2024-04-01 04:20:25.359497690 +0000
+++ src/network/network.h
@@ -21,7 +21,7 @@
 
 #include <functional>
 
-#include <asio.hpp>
+#include <boost/asio.hpp>
 
 #include "base/string.h"
 #include "base/wexception.h"
@@ -32,6 +32,8 @@
 
 constexpr size_t kNetworkBufferSize = 512;
 
+using namespace boost;
+
 /**
  * Simple structure to hold the IP address and port of a server.
  * This structure must not contain a hostname but only IP addresses.
