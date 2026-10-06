$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/include/v8-object.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/include/v8-object.h
@@ -22,6 +22,8 @@ class Function;
 class FunctionTemplate;
 template <typename T>
 class PropertyCallbackInfo;
+class Module;
+class UnboundScript;
 
 /**
  * A private symbol
@@ -532,6 +534,21 @@ class V8_EXPORT Object : public Value {
         index);
   }
 
+  /**
+   * Warning: These are Node.js-specific extentions used to avoid breaking
+   * changes in Node.js v20.x. They do not exist in V8 upstream and will
+   * not exist in Node.js v21.x. Node.js embedders and addon authors should
+   * not use them from v20.x.
+   */
+#ifndef NODE_WANT_INTERNALS
+  V8_DEPRECATED("This extention should only be used by Node.js core")
+#endif
+  void SetInternalFieldForNodeCore(int index, Local<Module> value);
+#ifndef NODE_WANT_INTERNALS
+  V8_DEPRECATED("This extention should only be used by Node.js core")
+#endif
+  void SetInternalFieldForNodeCore(int index, Local<UnboundScript> value);
+
   /** Same as above, but works for TracedReference. */
   V8_INLINE static void* GetAlignedPointerFromInternalField(
       const BasicTracedReference<Object>& object, int index) {
