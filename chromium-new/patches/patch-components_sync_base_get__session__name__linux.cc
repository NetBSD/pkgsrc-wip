$NetBSD$

--- components/sync/base/get_session_name_linux.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/sync/base/get_session_name_linux.cc
@@ -4,7 +4,7 @@
 
 #include "components/sync/base/get_session_name_linux.h"
 
-#include <limits.h>  // for HOST_NAME_MAX
+#include <limits.h>  // for _POSIX_HOST_NAME_MAX
 #include <unistd.h>  // for gethostname()
 
 #include "base/linux_util.h"
@@ -13,8 +13,8 @@ namespace syncer {
 namespace internal {
 
 std::string GetHostname() {
-  char hostname[HOST_NAME_MAX];
-  if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
+  char hostname[_POSIX_HOST_NAME_MAX];
+  if (gethostname(hostname, _POSIX_HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return base::GetLinuxDistro();
 }
