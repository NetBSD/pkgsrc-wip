$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/hid/hid_service_netbsd.h.orig	2024-08-27 11:35:21.432490325 +0000
+++ services/device/hid/hid_service_netbsd.h
@@ -0,0 +1,49 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_SERVICE_NETBSD_H_
+#define DEVICE_HID_HID_SERVICE_NETBSD_H_
+
+#include <string>
+
+#include "base/memory/ref_counted.h"
+#include "base/memory/weak_ptr.h"
+#include "base/timer/timer.h"
+#include "services/device/hid/hid_service.h"
+#include "net/base/io_buffer.h"
+
+namespace device {
+
+class HidServiceNetBSD : public HidService {
+ public:
+  HidServiceNetBSD();
+
+  HidServiceNetBSD(const HidServiceNetBSD&) = delete;
+  HidServiceNetBSD& operator=(const HidServiceNetBSD&) = delete;
+
+  ~HidServiceNetBSD() override;
+
+  void Connect(const std::string& device_guid,
+               bool allow_protected_reports,
+	       bool allow_fido_reports,
+               ConnectCallback connect) override;
+  base::WeakPtr<HidService> GetWeakPtr() override;
+
+ private:
+  struct ConnectParams;
+  class BlockingTaskRunnerHelper;
+
+  static void OpenOnBlockingThread(std::unique_ptr<ConnectParams> params);
+  static void FinishOpen(std::unique_ptr<ConnectParams> params);
+
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  // |helper_| lives on the sequence |blocking_task_runner_| posts to and holds
+  // a weak reference back to the service that owns it.
+  std::unique_ptr<BlockingTaskRunnerHelper, base::OnTaskRunnerDeleter> helper_;
+  base::WeakPtrFactory<HidServiceNetBSD> weak_factory_{this};
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_SERVICE_FREEBSD_H_
