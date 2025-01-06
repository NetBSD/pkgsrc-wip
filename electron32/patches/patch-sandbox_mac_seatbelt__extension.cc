$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/mac/seatbelt_extension.cc.orig	2024-10-18 12:34:31.993766300 +0000
+++ sandbox/mac/seatbelt_extension.cc
@@ -11,6 +11,7 @@
 #include "base/notreached.h"
 #include "sandbox/mac/seatbelt_extension_token.h"
 
+#if !IS_MAS_BUILD()
 // libsandbox private API.
 extern "C" {
 extern const char* APP_SANDBOX_READ;
@@ -22,6 +23,7 @@ char* sandbox_extension_issue_file(const
                                    const char* path,
                                    uint32_t flags);
 }
+#endif
 
 namespace sandbox {
 
@@ -50,7 +52,11 @@ std::unique_ptr<SeatbeltExtension> Seatb
 
 bool SeatbeltExtension::Consume() {
   DCHECK(!token_.empty());
+#if !IS_MAS_BUILD()
   handle_ = sandbox_extension_consume(token_.c_str());
+#else
+  handle_ = -1;
+#endif
   return handle_ > 0;
 }
 
@@ -62,7 +68,11 @@ bool SeatbeltExtension::ConsumePermanent
 }
 
 bool SeatbeltExtension::Revoke() {
+#if !IS_MAS_BUILD()
   int rv = sandbox_extension_release(handle_);
+#else
+  int rv = -1;
+#endif
   handle_ = 0;
   token_.clear();
   return rv == 0;
@@ -80,12 +90,14 @@ SeatbeltExtension::SeatbeltExtension(con
 char* SeatbeltExtension::IssueToken(SeatbeltExtension::Type type,
                                     const std::string& resource) {
   switch (type) {
+#if !IS_MAS_BUILD()
     case FILE_READ:
       return sandbox_extension_issue_file(APP_SANDBOX_READ, resource.c_str(),
                                           0);
     case FILE_READ_WRITE:
       return sandbox_extension_issue_file(APP_SANDBOX_READ_WRITE,
                                           resource.c_str(), 0);
+#endif
     default:
       NOTREACHED_IN_MIGRATION();
       return nullptr;
