$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/maglev/maglev-graph-builder.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/maglev/maglev-graph-builder.cc
@@ -12171,7 +12171,13 @@ ValueNode* MaglevGraphBuilder::BuildInli
           CreateHeapNumber(node->Cast<Float64Constant>()->value()),
           allocation_type);
     } else {
-      node = GetTaggedValue(node);
+      ValueNode* new_node = GetTaggedValue(node);
+      if (new_node != node && new_node->properties().can_allocate()) {
+        // TODO(olivf): Remove this and instead always clear when we
+        // emit an allocating instruction.
+        ClearCurrentAllocationBlock();
+      }
+      node = new_node;
     }
     values[i] = node;
   }
