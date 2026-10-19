$NetBSD$
Fix missing include for TBB_INTERFACE_VERSION macro.

TODO: upstream patch.

--- openvdb/openvdb/thread/Threading.h.orig	2026-10-19 06:14:34.363842337 +0000
+++ openvdb/openvdb/thread/Threading.h
@@ -23,6 +23,7 @@
 #include <tbb/blocked_range.h>
 #include <tbb/task.h>
 #include <tbb/task_group.h>
+#include <tbb/version.h>
 
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
