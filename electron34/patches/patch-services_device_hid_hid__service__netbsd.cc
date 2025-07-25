$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/device/hid/hid_service_netbsd.cc.orig	2025-07-08 14:12:31.298366303 +0000
+++ services/device/hid/hid_service_netbsd.cc
@@ -0,0 +1,27 @@
+// Copyright 2022 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/hid/hid_service_netbsd.h"
+
+#include "base/notreached.h"
+#include "services/device/hid/hid_connection.h"
+
+namespace device {
+
+HidServiceNetBSD::HidServiceNetBSD() = default;
+HidServiceNetBSD::~HidServiceNetBSD() = default;
+
+void HidServiceNetBSD::Connect(const std::string& device_id,
+                                bool allow_protected_reports,
+                                bool allow_fido_reports,
+                                ConnectCallback callback) {
+  NOTIMPLEMENTED_LOG_ONCE();
+  std::move(callback).Run(nullptr);
+}
+
+base::WeakPtr<HidService> HidServiceNetBSD::GetWeakPtr() {
+  return weak_factory_.GetWeakPtr();
+}
+
+}  // namespace device
