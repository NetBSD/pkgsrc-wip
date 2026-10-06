$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/nan_persistent_12_inl.h.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/nan_persistent_12_inl.h
@@ -129,4 +129,15 @@ class Global : public v8::UniquePersiste
 };
 #endif
 
+#if defined(V8_MAJOR_VERSION) && ((V8_MAJOR_VERSION >= 12 && V8_MINOR_VERSION >= 5) || V8_MAJOR_VERSION >= 13)
+template<typename T>
+struct CopyablePersistentTraits {
+  typedef v8::Persistent<T, CopyablePersistentTraits<T> > CopyablePersistent;
+  static const bool kResetInDestructor = true;
+  template<typename S, typename M>
+  static inline void Copy(const v8::Persistent<S, M> &source,
+                          CopyablePersistent *dest) {}
+};
+#endif
+
 #endif  // NAN_PERSISTENT_12_INL_H_
