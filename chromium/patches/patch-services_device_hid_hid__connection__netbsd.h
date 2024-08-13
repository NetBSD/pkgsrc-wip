$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/hid/hid_connection_netbsd.h.orig	2024-08-11 16:48:06.781305612 +0000
+++ services/device/hid/hid_connection_netbsd.h
@@ -0,0 +1,67 @@
+// Copyright (c) 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_CONNECTION_NETBSD_H_
+#define DEVICE_HID_HID_CONNECTION_NETBSD_H_
+
+#include <stddef.h>
+#include <stdint.h>
+
+#include "base/files/scoped_file.h"
+#include "base/memory/weak_ptr.h"
+#include "base/memory/ref_counted_memory.h"
+#include "base/task/sequenced_task_runner.h"
+#include "services/device/hid/hid_connection.h"
+
+namespace base {
+class SequencedTaskRunner;
+}
+
+namespace net {
+class IOBuffer;
+}
+
+namespace device {
+
+class HidConnectionNetBSD : public HidConnection {
+ public:
+  HidConnectionNetBSD(
+      scoped_refptr<HidDeviceInfo> device_info,
+      base::ScopedFD fd,
+      scoped_refptr<base::SequencedTaskRunner> blocking_task_runner,
+      bool allow_protected_reports,
+      bool allow_fido_reports);
+
+ private:
+  friend class base::RefCountedThreadSafe<HidConnectionNetBSD>;
+  class BlockingTaskRunnerHelper;
+
+  HidConnectionNetBSD(const HidConnectionNetBSD&) = delete;
+  HidConnectionNetBSD& operator=(const HidConnectionNetBSD&) = delete;
+
+  ~HidConnectionNetBSD() override;
+
+  // HidConnection implementation.
+  void PlatformClose() override;
+  void PlatformWrite(scoped_refptr<base::RefCountedBytes> buffer,
+                     WriteCallback callback) override;
+  void PlatformGetFeatureReport(uint8_t report_id,
+                                ReadCallback callback) override;
+  void PlatformSendFeatureReport(scoped_refptr<base::RefCountedBytes> buffer,
+                                 WriteCallback callback) override;
+
+  // |helper_| lives on the sequence to which |blocking_task_runner_| posts
+  // tasks so all calls must be posted there including this object's
+  // destruction.
+  std::unique_ptr<BlockingTaskRunnerHelper, base::OnTaskRunnerDeleter> helper_;
+
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
+
+  base::WeakPtrFactory<HidConnectionNetBSD> weak_factory_{this};
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_CONNECTION_FREEBSD_H_
