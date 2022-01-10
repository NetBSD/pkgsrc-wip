$NetBSD$

* Add Solaris support
* Use the native uuid api on NetBSD

--- libcaf_core/src/detail/get_root_uuid.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/src/detail/get_root_uuid.cpp
@@ -3,6 +3,7 @@
 // https://github.com/actor-framework/actor-framework/blob/master/LICENSE.
 
 #include "caf/detail/get_root_uuid.hpp"
+#include "caf/logger.hpp"
 #include "caf/config.hpp"
 
 #ifndef CAF_MACOS // not needed on Mac OS X
@@ -45,7 +46,7 @@ std::string get_root_uuid() {
 } // namespace detail
 } // namespace caf
 
-#elif defined(CAF_LINUX) || defined(CAF_BSD) || defined(CAF_CYGWIN)
+#elif defined(CAF_LINUX) || defined(CAF_CYGWIN)
 
 #  include <algorithm>
 #  include <fstream>
@@ -125,6 +126,50 @@ std::string get_root_uuid() {
 
 } // namespace caf::detail
 
+#elif defined(CAF_NETBSD)
+
+#  include <uuid.h>
+
+#  include <cstdlib>
+#  include <string>
+
+namespace caf {
+namespace detail {
+
+namespace {
+  uuid_t s_uuid;
+  bool s_uuid_need_init = true;
+}
+
+std::string get_root_uuid()
+{
+  std::string uuid;
+  char *uuid_str;
+  uint32_t status;
+  if(s_uuid_need_init) {
+    uuid_create(&s_uuid, &status);
+    if(status != uuid_s_ok) {
+      CAF_LOG_ERROR("failed to get uuid from uuid_create in get_root_uuid");
+      return uuid;
+    }
+    s_uuid_need_init = false;
+  }
+
+  uuid_to_string(&s_uuid, &uuid_str, &status);
+  if(status != uuid_s_ok) {
+    CAF_LOG_ERROR("failed to create uuid string using uuid_to_string in get_root_uuid");
+    return uuid;
+  }
+  uuid.assign(uuid_str);
+  free(uuid_str);
+
+  return uuid;
+}
+
+
+} // detail
+} // caf
+
 #elif defined(CAF_WINDOWS)
 
 #  include <algorithm>
@@ -192,7 +237,7 @@ std::string get_root_uuid() {
 } // namespace detail
 } // namespace caf
 
-#elif defined(CAF_IOS) || defined(CAF_ANDROID)
+#elif defined(CAF_IOS) || defined(CAF_ANDROID) || defined(CAF_SOLARIS) || defined(CAF_BSD)
 
 // return a randomly-generated UUID on mobile devices
 
