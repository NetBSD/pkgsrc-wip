$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/maglev/maglev-graph-builder.cc.orig	2024-10-18 12:48:35.380421900 +0000
+++ v8/src/maglev/maglev-graph-builder.cc
@@ -1347,7 +1347,14 @@ DeoptFrame MaglevGraphBuilder::GetDeoptF
           if (result_size == 0 ||
               !base::IsInRange(reg.index(), result_location.index(),
                                result_location.index() + result_size - 1)) {
-            AddDeoptUse(node);
+            // Receiver and closure values have to be materialized, even if
+            // they don't otherwise escape.
+            if (reg == interpreter::Register::receiver() ||
+                reg == interpreter::Register::function_closure()) {
+              node->add_use();
+            } else {
+              AddDeoptUse(node);
+            }
           }
         });
     AddDeoptUse(ret.closure());
