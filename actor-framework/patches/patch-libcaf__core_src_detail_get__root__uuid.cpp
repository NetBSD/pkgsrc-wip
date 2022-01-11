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
@@ -125,6 +126,80 @@ std::string get_root_uuid() {
 
 } // namespace caf::detail
 
+#elif defined(CAF_NETBSD) || defined(CAF_BSD)
+
+#  include <sys/param.h>
+#  include <sys/types.h>
+#  include <sys/sysctl.h>
+
+#  include <cstdlib>
+#  include <string>
+
+#  include "caf/uuid.hpp"
+
+namespace caf {
+namespace detail {
+
+namespace {
+  std::string root_uuid;
+
+  std::string get_sysctl_uuid()
+  {
+#  if defined(__FreeBSD__)
+    int mib[2];
+    u_int mib_len = 2;
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_HOSTUUID;
+#  elif defined(__OpenBSD__)
+    int mib[2];
+    u_int mib_len = 2;
+    mib[0] = CTL_HW;
+    mib[1] = HW_UUID;
+#  elif defined(CAF_NETBSD)
+    int mib[3];
+    size_t mib_len = 3;
+    if (sysctlnametomib("machdep.dmi.system-uuid", mib, &mib_len)) {
+      return std::string{};
+    }
+#  endif
+    size_t uuid_len;
+    char *uuid_str;
+
+    if (sysctl(mib, mib_len, NULL, &uuid_len, NULL, (size_t)0)) {
+      return std::string{};
+    }
+
+    uuid_str = (char*)malloc(uuid_len);
+
+    if (sysctl(mib, mib_len, uuid_str, &uuid_len, NULL, (size_t)0)) {
+      free(uuid_str);
+      return std::string{};
+    }
+
+    std::string sc_uuid{uuid_str};
+    free(uuid_str);
+
+    return sc_uuid;
+  }
+
+} // namespace
+
+std::string get_root_uuid()
+{
+  if(root_uuid.empty()) {
+    root_uuid = get_sysctl_uuid();
+
+    if(root_uuid.empty() || (root_uuid.compare("00000000-0000-0000-0000-000000000000") == 0)) {
+      root_uuid = to_string(caf::uuid::random());
+    }
+  }
+
+  return root_uuid;
+}
+
+} // detail
+} // caf
+
 #elif defined(CAF_WINDOWS)
 
 #  include <algorithm>
@@ -192,7 +267,7 @@ std::string get_root_uuid() {
 } // namespace detail
 } // namespace caf
 
-#elif defined(CAF_IOS) || defined(CAF_ANDROID)
+#elif defined(CAF_IOS) || defined(CAF_ANDROID) || defined(CAF_SOLARIS)
 
 // return a randomly-generated UUID on mobile devices
 
