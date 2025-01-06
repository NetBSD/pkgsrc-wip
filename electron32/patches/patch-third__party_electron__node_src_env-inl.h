$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/env-inl.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/env-inl.h
@@ -62,31 +62,6 @@ inline uv_loop_t* IsolateData::event_loo
   return event_loop_;
 }
 
-inline void IsolateData::SetCppgcReference(v8::Isolate* isolate,
-                                           v8::Local<v8::Object> object,
-                                           void* wrappable) {
-  v8::CppHeap* heap = isolate->GetCppHeap();
-  CHECK_NOT_NULL(heap);
-  v8::WrapperDescriptor descriptor = heap->wrapper_descriptor();
-  uint16_t required_size = std::max(descriptor.wrappable_instance_index,
-                                    descriptor.wrappable_type_index);
-  CHECK_GT(object->InternalFieldCount(), required_size);
-
-  uint16_t* id_ptr = nullptr;
-  {
-    Mutex::ScopedLock lock(isolate_data_mutex_);
-    auto it =
-        wrapper_data_map_.find(descriptor.embedder_id_for_garbage_collected);
-    CHECK_NE(it, wrapper_data_map_.end());
-    id_ptr = &(it->second->cppgc_id);
-  }
-
-  object->SetAlignedPointerInInternalField(descriptor.wrappable_type_index,
-                                           id_ptr);
-  object->SetAlignedPointerInInternalField(descriptor.wrappable_instance_index,
-                                           wrappable);
-}
-
 inline uint16_t* IsolateData::embedder_id_for_cppgc() const {
   return &(wrapper_data_->cppgc_id);
 }
