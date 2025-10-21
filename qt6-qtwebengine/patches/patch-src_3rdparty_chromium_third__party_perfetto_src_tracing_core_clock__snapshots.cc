$NetBSD$

treat bsd like apple

--- src/3rdparty/chromium/third_party/perfetto/src/tracing/core/clock_snapshots.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/core/clock_snapshots.cc
@@ -25,6 +25,7 @@ namespace perfetto {
 ClockSnapshotVector CaptureClockSnapshots() {
   ClockSnapshotVector snapshot_data;
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
   struct {
