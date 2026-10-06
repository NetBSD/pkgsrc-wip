$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/win/win_util.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/win/win_util.h
@@ -46,6 +46,25 @@ struct NativeLibraryLoadError;
 
 namespace win {
 
+inline bool IsPseudoHandle(HANDLE h) {
+  // Note that there appears to be no official documentation covering the
+  // existence of specific pseudo handle values. In practice it's clear that
+  // e.g. -1 is the current process, -2 is the current thread, etc. The largest
+  // negative value known to be an issue with DuplicateHandle in fuzzers is
+  // -12.
+  //
+  // Note that there is virtually no risk of a real handle value falling within
+  // this range and being misclassified as a pseudo handle.
+  //
+  // Cast through uintptr_t and then unsigned int to make the truncation to
+  // 32 bits explicit. Handles are size of-pointer but are always 32-bit values.
+  // https://msdn.microsoft.com/en-us/library/aa384203(VS.85).aspx says:
+  // 64-bit versions of Windows use 32-bit handles for interoperability.
+  constexpr int kMinimumKnownPseudoHandleValue = -12;
+  const auto value = static_cast<int32_t>(reinterpret_cast<uintptr_t>(h));
+  return value < 0 && value >= kMinimumKnownPseudoHandleValue;
+}
+
 inline uint32_t HandleToUint32(HANDLE h) {
   // Cast through uintptr_t and then unsigned int to make the truncation to
   // 32 bits explicit. Handles are size of-pointer but are always 32-bit values.
