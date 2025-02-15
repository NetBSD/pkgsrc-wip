$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/compiler/turboshaft/wasm-gc-typed-optimization-reducer.h.orig	2024-10-18 12:48:35.276422500 +0000
+++ v8/src/compiler/turboshaft/wasm-gc-typed-optimization-reducer.h
@@ -80,6 +80,8 @@ class WasmGCTypeAnalyzer {
   void ProcessPhi(const PhiOp& phi);
   void ProcessTypeAnnotation(const WasmTypeAnnotationOp& type_annotation);
 
+  wasm::ValueType GetTypeForPhiInput(const PhiOp& phi, int input_index);
+
   void CreateMergeSnapshot(const Block& block);
   bool CreateMergeSnapshot(base::Vector<const Snapshot> predecessors,
                            base::Vector<const bool> reachable);
