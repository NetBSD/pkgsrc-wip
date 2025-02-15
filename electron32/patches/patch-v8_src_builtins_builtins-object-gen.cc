$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/builtins/builtins-object-gen.cc.orig	2024-10-18 12:48:35.148423200 +0000
+++ v8/src/builtins/builtins-object-gen.cc
@@ -486,6 +486,13 @@ TF_BUILTIN(ObjectAssign, ObjectBuiltinsA
     GotoIfNot(TaggedEqual(LoadElements(CAST(to)), EmptyFixedArrayConstant()),
               &slow_path);
 
+    // Ensure the properties field is not used to store a hash.
+    TNode<Object> properties = LoadJSReceiverPropertiesOrHash(to);
+    GotoIf(TaggedIsSmi(properties), &slow_path);
+    CSA_DCHECK(this,
+               Word32Or(TaggedEqual(properties, EmptyFixedArrayConstant()),
+                        IsPropertyArray(CAST(properties))));
+
     // Check if our particular source->target combination is fast clonable.
     // E.g., this ensures that we only have fast properties and in general that
     // the binary layout is compatible for `FastCloneJSObject`.
