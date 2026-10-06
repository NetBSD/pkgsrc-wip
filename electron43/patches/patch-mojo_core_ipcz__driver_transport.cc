$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- mojo/core/ipcz_driver/transport.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ mojo/core/ipcz_driver/transport.cc
@@ -34,6 +34,7 @@
 #include "third_party/ipcz/include/ipcz/ipcz.h"
 
 #if BUILDFLAG(IS_WIN)
+#include "base/win/win_util.h"
 #include "mojo/public/cpp/platform/platform_handle_security_util_win.h"
 #endif
 
@@ -135,10 +136,12 @@ bool EncodeHandle(PlatformHandle& handle
                   HandleOwner handle_owner,
                   HandleData& out_handle_data,
                   bool is_remote_process_untrusted) {
+  CHECK(handle.is_valid());
   // Duplicating INVALID_HANDLE_VALUE passes a process handle. If you intend to
   // do this, you must open a valid process handle, not pass the result of
-  // GetCurrentProcess(). e.g. https://crbug.com/243339.
-  CHECK(handle.is_valid());
+  // GetCurrentProcess() or GetCurrentThread(). e.g. https://crbug.com/243339.
+  CHECK(!handle.is_pseudo_handle());
+
   if (handle_owner == HandleOwner::kSender) {
     // Nothing to do when sending handles that belong to us. The recipient must
     // be sufficiently privileged and equipped to duplicate such handles to
@@ -178,6 +181,10 @@ PlatformHandle DecodeHandle(HandleData d
                             HandleOwner handle_owner,
                             Transport& from_transport) {
   const HANDLE handle = DataToHandle(data);
+  // Do not decode sentinel values used by Windows (INVALID_HANDLE_VALUE &
+  // GetCurrentThread()).
+  CHECK(!base::win::IsPseudoHandle(handle));
+
   if (handle_owner == HandleOwner::kRecipient) {
     if (from_transport.destination_type() != Transport::kBroker &&
         !from_transport.is_peer_trusted() && !remote_process.is_current()) {
