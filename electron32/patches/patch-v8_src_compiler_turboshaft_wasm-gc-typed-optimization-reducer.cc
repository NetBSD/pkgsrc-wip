$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/compiler/turboshaft/wasm-gc-typed-optimization-reducer.cc.orig	2024-10-18 12:48:35.276422500 +0000
+++ v8/src/compiler/turboshaft/wasm-gc-typed-optimization-reducer.cc
@@ -45,9 +45,23 @@ void WasmGCTypeAnalyzer::Run() {
         // defines more precise types than the previous iteration).
         if (needs_revisit) {
           block_to_snapshot_[loop_header.index()] = MaybeSnapshot(snapshot);
-          // This will push the successors of the loop header to the iterator
-          // stack, so the loop body will be visited in the next iteration.
-          iterator.MarkLoopForRevisitSkipHeader();
+          if (block.index() != loop_header.index()) {
+            // This will push the successors of the loop header to the iterator
+            // stack, so the loop body will be visited in the next iteration.
+            iterator.MarkLoopForRevisitSkipHeader();
+          } else {
+            // A single-block loop doesn't have any successors which would be
+            // re-evaluated and which might trigger another re-evaluation of the
+            // loop header.
+            // TODO(mliedtke): This is not a great design: We don't just
+            // schedule revisiting the loop header but afterwards we revisit it
+            // once again to evaluate whether we need to revisit it more times,
+            // so for single block loops the revisitation count will always be a
+            // multiple of 2. While this is inefficient, single-block loops are
+            // rare and are either endless loops or need to trigger an exception
+            // (e.g. a wasm trap) to terminate.
+            iterator.MarkLoopForRevisit();
+          }
         }
       }
     }
@@ -269,6 +283,25 @@ void WasmGCTypeAnalyzer::ProcessAllocate
                       wasm::ValueType::Ref(type_index));
 }
 
+wasm::ValueType WasmGCTypeAnalyzer::GetTypeForPhiInput(const PhiOp& phi,
+                                                       int input_index) {
+  OpIndex phi_id = graph_.Index(phi);
+  OpIndex input = ResolveAliases(phi.input(input_index));
+  // If the input of the phi is in the same block as the phi and appears
+  // before the phi, don't use the predecessor value.
+
+  if (current_block_->begin().id() <= input.id() && input.id() < phi_id.id()) {
+    // Phi instructions have to be at the beginning of the block, so this can
+    // only happen for inputs that are also phis. Furthermore, this is only
+    // possible in loop headers of loops and only for the backedge-input.
+    DCHECK(graph_.Get(input).Is<PhiOp>());
+    DCHECK(current_block_->IsLoop());
+    DCHECK_EQ(input_index, 1);
+    return types_table_.Get(input);
+  }
+  return types_table_.GetPredecessorValue(input, input_index);
+}
+
 void WasmGCTypeAnalyzer::ProcessPhi(const PhiOp& phi) {
   // The result type of a phi is the union of all its input types.
   // If any of the inputs is the default value ValueType(), there isn't any type
@@ -281,12 +314,10 @@ void WasmGCTypeAnalyzer::ProcessPhi(cons
     RefineTypeKnowledge(graph_.Index(phi), GetResolvedType((phi.input(0))));
     return;
   }
-  wasm::ValueType union_type =
-      types_table_.GetPredecessorValue(ResolveAliases(phi.input(0)), 0);
+  wasm::ValueType union_type = GetTypeForPhiInput(phi, 0);
   if (union_type == wasm::ValueType()) return;
   for (int i = 1; i < phi.input_count; ++i) {
-    wasm::ValueType input_type =
-        types_table_.GetPredecessorValue(ResolveAliases(phi.input(i)), i);
+    wasm::ValueType input_type = GetTypeForPhiInput(phi, i);
     if (input_type == wasm::ValueType()) return;
     // <bottom> types have to be skipped as an unreachable predecessor doesn't
     // change our type knowledge.
