$NetBSD$

* add NetBSD support
* add Solaris build , add defines and includes to fix solaris build

--- libcaf_core/src/detail/get_mac_addresses.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/src/detail/get_mac_addresses.cpp
@@ -7,7 +7,7 @@
 #include "caf/config.hpp"
 #include "caf/detail/scope_guard.hpp"
 
-#if defined(CAF_MACOS) || defined(CAF_BSD) || defined(CAF_IOS)
+#if defined(CAF_MACOS) || defined(CAF_BSD) || defined(CAF_IOS) || defined(CAF_NETBSD)
 
 #  include <arpa/inet.h>
 #  include <cerrno>
@@ -83,7 +83,7 @@ std::vector<iface_info> get_mac_addresse
 } // namespace detail
 } // namespace caf
 
-#elif defined(CAF_LINUX) || defined(CAF_ANDROID) || defined(CAF_CYGWIN)
+#elif defined(CAF_LINUX) || defined(CAF_ANDROID) || defined(CAF_CYGWIN) || defined(CAF_SOLARIS)
 
 #  include <algorithm>
 #  include <cctype>
@@ -101,6 +101,13 @@ std::vector<iface_info> get_mac_addresse
 #  include <unistd.h>
 #  include <vector>
 
+#  if defined(CAF_SOLARIS)
+#    include <sys/sockio.h>
+#    if !defined(ifr_hwaddr)
+#      define ifr_hwaddr ifr_addr
+#    endif
+#  endif
+
 namespace caf::detail {
 
 std::vector<iface_info> get_mac_addresses() {
