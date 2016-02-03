$NetBSD$

--- src/debug/ee/controller.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ee/controller.h
@@ -540,6 +540,8 @@ class DebuggerPatchTable : private CHash
 {
     VPTR_BASE_CONCRETE_VTABLE_CLASS(DebuggerPatchTable);
 
+    virtual ~DebuggerPatchTable() = default;
+
     friend class DebuggerRCThread;
 private:
     //incremented so that we can get DPT-wide unique PIDs.
