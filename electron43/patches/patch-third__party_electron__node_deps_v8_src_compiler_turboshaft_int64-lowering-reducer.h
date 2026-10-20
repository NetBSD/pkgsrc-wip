$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/compiler/turboshaft/int64-lowering-reducer.h.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/v8/src/compiler/turboshaft/int64-lowering-reducer.h
@@ -637,7 +637,7 @@ class Int64LoweringReducer : public Next
       result = __ Word32CountLeadingZeros(high);
     }
 
-    return __ Tuple<Word32, Word32>(result, __ Word32Constant(0));
+    return __ template Tuple<Word32, Word32>(result, __ Word32Constant(0));
   }
 
   V<Word32Pair> LowerCtz(V<Word32Pair> input) {
@@ -650,7 +650,7 @@ class Int64LoweringReducer : public Next
       result = __ Word32CountTrailingZeros(low);
     }
 
-    return __ Tuple<Word32, Word32>(result, __ Word32Constant(0));
+    return __ template Tuple<Word32, Word32>(result, __ Word32Constant(0));
   }
 
   V<Word32Pair> LowerPopCount(V<Word32Pair> input) {
