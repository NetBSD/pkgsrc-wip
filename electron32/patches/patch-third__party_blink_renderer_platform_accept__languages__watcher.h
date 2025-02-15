$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/accept_languages_watcher.h.orig	2025-02-15 18:06:05.472098097 +0000
+++ third_party/blink/renderer/platform/accept_languages_watcher.h
@@ -0,0 +1,22 @@
+// Copyright 2024 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_ACCEPT_LANGUAGES_WATCHER_H_
+#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_ACCEPT_LANGUAGES_WATCHER_H_
+
+#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
+
+namespace blink {
+
+// Helper class allowing DedicatedOrSharedWorkerFetchContextImpl to notify blink
+// upon an accept languages update. This class will be extended by
+// WorkerNavigator.
+class AcceptLanguagesWatcher : public GarbageCollectedMixin {
+ public:
+  virtual void NotifyUpdate() = 0;
+};
+
+}  // namespace blink
+
+#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_ACCEPT_LANGUAGES_WATCHER_H_
