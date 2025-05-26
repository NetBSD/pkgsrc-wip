$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- mojo/public/cpp/platform/platform_handle.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ mojo/public/cpp/platform/platform_handle.h
@@ -13,6 +13,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "base/win/scoped_handle.h"
+#include "base/win/win_util.h"
 #elif BUILDFLAG(IS_FUCHSIA)
 #include <lib/zx/handle.h>
 #elif BUILDFLAG(IS_APPLE)
@@ -117,6 +118,9 @@ class COMPONENT_EXPORT(MOJO_CPP_PLATFORM
   bool is_valid() const { return is_valid_handle(); }
   bool is_valid_handle() const { return handle_.IsValid(); }
   bool is_handle() const { return type_ == Type::kHandle; }
+  bool is_pseudo_handle() const {
+    return base::win::IsPseudoHandle(handle_.get());
+  }
   const base::win::ScopedHandle& GetHandle() const { return handle_; }
   base::win::ScopedHandle TakeHandle() {
     DCHECK_EQ(type_, Type::kHandle);
