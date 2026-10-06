$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/compiler/escape-analysis.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/compiler/escape-analysis.cc
@@ -622,6 +622,16 @@ void ReduceNode(const Operator* op, Esca
       Node* value = current->ValueInput(1);
       const VirtualObject* vobject = current->GetVirtualObject(object);
       Variable var;
+      if (value->opcode() == IrOpcode::kTrustedHeapConstant) {
+        // TODO(dmercadier): enable escaping objects containing
+        // TrustedHeapConstants. This is currently disabled because it leads to
+        // bugs when Trusted HeapConstant and regular HeapConstant flow into the
+        // same Phi, which can then be marked as Compressed, messing up the
+        // tagging of the Trusted HeapConstant.
+        current->SetEscaped(object);
+        current->SetEscaped(value);
+        break;
+      }
       // BoundedSize fields cannot currently be materialized by the deoptimizer,
       // so we must not dematerialze them.
       if (vobject && !vobject->HasEscaped() &&
