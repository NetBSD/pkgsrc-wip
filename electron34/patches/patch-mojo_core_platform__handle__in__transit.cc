$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- mojo/core/platform_handle_in_transit.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ mojo/core/platform_handle_in_transit.cc
@@ -18,6 +18,7 @@
 
 #include "base/win/nt_status.h"
 #include "base/win/scoped_handle.h"
+#include "base/win/win_util.h"
 #include "mojo/public/cpp/platform/platform_handle_security_util_win.h"
 #endif
 
@@ -37,8 +38,8 @@ HANDLE TransferHandle(HANDLE handle,
 
   // Duplicating INVALID_HANDLE_VALUE passes a process handle. If you intend to
   // do this, you must open a valid process handle, not pass the result of
-  // GetCurrentProcess(). e.g. https://crbug.com/243339.
-  CHECK(handle != INVALID_HANDLE_VALUE);
+  // GetCurrentProcess() or GetCurrentThread(). e.g. https://crbug.com/243339.
+  CHECK(!base::win::IsPseudoHandle(handle));
 
   HANDLE out_handle;
   BOOL result =
@@ -164,17 +165,7 @@ bool PlatformHandleInTransit::TransferTo
 #if BUILDFLAG(IS_WIN)
 // static
 bool PlatformHandleInTransit::IsPseudoHandle(HANDLE handle) {
-  // Note that there appears to be no official documentation covering the
-  // existence of specific pseudo handle values. In practice it's clear that
-  // e.g. -1 is the current process, -2 is the current thread, etc. The largest
-  // negative value known to be an issue with DuplicateHandle in the fuzzer is
-  // -12.
-  //
-  // Note that there is virtually no risk of a real handle value falling within
-  // this range and being misclassified as a pseudo handle.
-  constexpr int kMinimumKnownPseudoHandleValue = -12;
-  const auto value = static_cast<int32_t>(reinterpret_cast<uintptr_t>(handle));
-  return value < 0 && value >= kMinimumKnownPseudoHandleValue;
+  return base::win::IsPseudoHandle(handle);
 }
 
 // static
