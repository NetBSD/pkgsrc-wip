$NetBSD$

--- src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2020-06-25 09:34:48.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2458,6 +2458,7 @@ void TracingServiceImpl::SnapshotClocks(
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&    \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD) &&    \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
   struct {
     clockid_t id;
