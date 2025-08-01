$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/hid/hid_connection_fido.h.orig	2025-07-24 17:00:09.201544118 +0000
+++ services/device/hid/hid_connection_fido.h
@@ -0,0 +1,60 @@
+// Copyright 2014 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef SERVICES_DEVICE_HID_HID_CONNECTION_LINUX_H_
+#define SERVICES_DEVICE_HID_HID_CONNECTION_LINUX_H_
+
+#include <stddef.h>
+#include <stdint.h>
+
+#include "base/files/scoped_file.h"
+#include "base/memory/weak_ptr.h"
+#include "base/task/sequenced_task_runner.h"
+#include "services/device/hid/hid_connection.h"
+
+namespace base {
+class SequencedTaskRunner;
+}
+
+namespace device {
+
+class HidConnectionFido : public HidConnection {
+ public:
+  HidConnectionFido(
+      scoped_refptr<HidDeviceInfo> device_info,
+      base::ScopedFD fd,
+      scoped_refptr<base::SequencedTaskRunner> blocking_task_runner,
+      bool allow_protected_reports,
+      bool allow_fido_reports);
+  HidConnectionFido(HidConnectionFido&) = delete;
+  HidConnectionFido& operator=(HidConnectionFido&) = delete;
+
+ private:
+  friend class base::RefCountedThreadSafe<HidConnectionFido>;
+  class BlockingTaskRunnerHelper;
+
+  ~HidConnectionFido() override;
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
+
+  base::WeakPtrFactory<HidConnectionFido> weak_factory_{this};
+};
+
+}  // namespace device
+
+#endif  // SERVICES_DEVICE_HID_HID_CONNECTION_LINUX_H_
