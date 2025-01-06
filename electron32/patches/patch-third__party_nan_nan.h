$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/nan.h.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/nan.h
@@ -47,6 +47,7 @@
 #define NODE_18_0_MODULE_VERSION 108
 #define NODE_19_0_MODULE_VERSION 111
 #define NODE_20_0_MODULE_VERSION 115
+#define NODE_21_0_MODULE_VERSION 119
 
 #ifdef _MSC_VER
 # define NAN_HAS_CPLUSPLUS_11 (_MSC_VER >= 1800)
@@ -203,9 +204,11 @@ typedef v8::String::ExternalOneByteStrin
 template<typename T>
 class NonCopyablePersistentTraits :
     public v8::NonCopyablePersistentTraits<T> {};
+#if defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION <= 12 && V8_MINOR_VERSION < 5)
 template<typename T>
 class CopyablePersistentTraits :
     public v8::CopyablePersistentTraits<T> {};
+#endif
 
 template<typename T>
 class PersistentBase :
@@ -682,7 +685,13 @@ inline uv_loop_t* GetCurrentEventLoop() 
     v8::Isolate::GetCurrent()->SetAddHistogramSampleFunction(cb);
   }
 
-#if defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION > 4 ||                      \
+#if defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION > 11 ||                      \
+  (V8_MAJOR_VERSION == 11 && defined(V8_MINOR_VERSION) && V8_MINOR_VERSION >= 3))
+  inline bool IdleNotification(int idle_time_in_ms) {
+    v8::Isolate::GetCurrent()->MemoryPressureNotification(v8::MemoryPressureLevel::kModerate);
+    return true;
+  }
+#elif defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION > 4 ||                      \
   (V8_MAJOR_VERSION == 4 && defined(V8_MINOR_VERSION) && V8_MINOR_VERSION >= 3))
   inline bool IdleNotification(int idle_time_in_ms) {
     return v8::Isolate::GetCurrent()->IdleNotificationDeadline(
@@ -2517,7 +2526,9 @@ NAN_DEPRECATED inline void SetAccessor(
   , GetterCallback getter
   , SetterCallback setter
   , v8::Local<v8::Value> data
+#if (NODE_MODULE_VERSION < NODE_21_0_MODULE_VERSION)
   , v8::AccessControl settings
+#endif
   , v8::PropertyAttribute attribute
   , imp::Sig signature) {
   HandleScope scope;
@@ -2545,17 +2556,28 @@ NAN_DEPRECATED inline void SetAccessor(
     obj->SetInternalField(imp::kDataIndex, data);
   }
 
+#if (NODE_MODULE_VERSION >= NODE_21_0_MODULE_VERSION)
+  tpl->SetNativeDataProperty(
+      name
+    , getter_
+    , setter_
+    , obj
+    , attribute);
+#else
   tpl->SetAccessor(
       name
     , getter_
     , setter_
     , obj
+#if (NODE_MODULE_VERSION < NODE_21_0_MODULE_VERSION)
     , settings
+#endif
     , attribute
 #if (NODE_MODULE_VERSION < NODE_16_0_MODULE_VERSION)
     , signature
 #endif
   );
+#endif
 }
 
 inline void SetAccessor(
@@ -2564,7 +2586,9 @@ inline void SetAccessor(
   , GetterCallback getter
   , SetterCallback setter = 0
   , v8::Local<v8::Value> data = v8::Local<v8::Value>()
+#if (NODE_MODULE_VERSION < NODE_21_0_MODULE_VERSION)
   , v8::AccessControl settings = v8::DEFAULT
+#endif
   , v8::PropertyAttribute attribute = v8::None) {
   HandleScope scope;
 
@@ -2591,14 +2615,25 @@ inline void SetAccessor(
     obj->SetInternalField(imp::kDataIndex, data);
   }
 
+#if (NODE_MODULE_VERSION >= NODE_21_0_MODULE_VERSION)
+  tpl->SetNativeDataProperty(
+      name
+    , getter_
+    , setter_
+    , obj
+    , attribute);
+#else
   tpl->SetAccessor(
       name
     , getter_
     , setter_
     , obj
+#if (NODE_MODULE_VERSION < NODE_21_0_MODULE_VERSION)
     , settings
+#endif
     , attribute
   );
+#endif
 }
 
 inline bool SetAccessor(
@@ -2634,7 +2669,15 @@ inline bool SetAccessor(
       , New<v8::External>(reinterpret_cast<void *>(setter)));
   }
 
-#if (NODE_MODULE_VERSION >= NODE_6_0_MODULE_VERSION)
+#if (NODE_MODULE_VERSION >= NODE_21_0_MODULE_VERSION)
+  return obj->SetNativeDataProperty(
+      GetCurrentContext()
+    , name
+    , getter_
+    , setter_
+    , dataobj
+    , attribute).FromMaybe(false);
+#elif (NODE_MODULE_VERSION >= NODE_6_0_MODULE_VERSION)
   return obj->SetAccessor(
       GetCurrentContext()
     , name
