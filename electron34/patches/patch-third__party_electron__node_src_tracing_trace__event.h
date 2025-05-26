$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/tracing/trace_event.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/tracing/trace_event.h
@@ -69,8 +69,16 @@ enum CategoryGroupEnabledFlags {
 // for best performance when tracing is disabled.
 // const uint8_t*
 //     TRACE_EVENT_API_GET_CATEGORY_GROUP_ENABLED(const char* category_group)
+#ifndef V8_USE_PERFETTO
 #define TRACE_EVENT_API_GET_CATEGORY_GROUP_ENABLED              \
   node::tracing::TraceEventHelper::GetCategoryGroupEnabled
+#else
+#define TRACE_EVENT_API_GET_CATEGORY_GROUP_ENABLED(category_group) \
+  ([](const char*) -> const uint8_t* { \
+    static uint8_t no = 0; \
+    return &no; \
+  })(category_group)
+#endif
 
 // Get the number of times traces have been recorded. This is used to implement
 // the TRACE_EVENT_IS_NEW_TRACE facility.
@@ -114,10 +122,15 @@ enum CategoryGroupEnabledFlags {
 //     const uint8_t* category_group_enabled,
 //     const char* name,
 //     uint64_t id)
+#ifndef V8_USE_PERFETTO
 #define TRACE_EVENT_API_UPDATE_TRACE_EVENT_DURATION                           \
   if (auto controller =                                                       \
          node::tracing::TraceEventHelper::GetTracingController())             \
       controller->UpdateTraceEventDuration
+#else
+#define TRACE_EVENT_API_UPDATE_TRACE_EVENT_DURATION(category_group_enabled, name, event_handle) \
+  (void)(category_group_enabled), (void)(name), (void)(event_handle)
+#endif
 
 // Adds a metadata event to the trace log. The |AppendValueAsTraceFormat| method
 // on the convertable value will be called at flush time.
@@ -319,10 +332,13 @@ class TraceEventHelper {
   static void SetAgent(Agent* agent);
 
   static inline const uint8_t* GetCategoryGroupEnabled(const char* group) {
+#ifndef V8_USE_PERFETTO
     v8::TracingController* controller = GetTracingController();
     static const uint8_t disabled = 0;
     if (UNLIKELY(controller == nullptr)) return &disabled;
     return controller->GetCategoryGroupEnabled(group);
+#endif
+    return 0;
   }
 };
 
@@ -460,6 +476,7 @@ static inline uint64_t AddTraceEventImpl
     const char* scope, uint64_t id, uint64_t bind_id, int32_t num_args,
     const char** arg_names, const uint8_t* arg_types,
     const uint64_t* arg_values, unsigned int flags) {
+#ifndef V8_USE_PERFETTO
   std::unique_ptr<v8::ConvertableToTraceFormat> arg_convertibles[2];
   if (num_args > 0 && arg_types[0] == TRACE_VALUE_TYPE_CONVERTABLE) {
     arg_convertibles[0].reset(reinterpret_cast<v8::ConvertableToTraceFormat*>(
@@ -469,13 +486,14 @@ static inline uint64_t AddTraceEventImpl
     arg_convertibles[1].reset(reinterpret_cast<v8::ConvertableToTraceFormat*>(
         static_cast<intptr_t>(arg_values[1])));
   }
-  // DCHECK(num_args, 2);
   v8::TracingController* controller =
       node::tracing::TraceEventHelper::GetTracingController();
   if (controller == nullptr) return 0;
   return controller->AddTraceEvent(phase, category_group_enabled, name, scope, id,
                                    bind_id, num_args, arg_names, arg_types,
                                    arg_values, arg_convertibles, flags);
+#endif
+  return 0;
 }
 
 static V8_INLINE uint64_t AddTraceEventWithTimestampImpl(
@@ -483,6 +501,7 @@ static V8_INLINE uint64_t AddTraceEventW
     const char* scope, uint64_t id, uint64_t bind_id, int32_t num_args,
     const char** arg_names, const uint8_t* arg_types,
     const uint64_t* arg_values, unsigned int flags, int64_t timestamp) {
+#ifndef V8_USE_PERFETTO
   std::unique_ptr<v8::ConvertableToTraceFormat> arg_convertables[2];
   if (num_args > 0 && arg_types[0] == TRACE_VALUE_TYPE_CONVERTABLE) {
     arg_convertables[0].reset(reinterpret_cast<v8::ConvertableToTraceFormat*>(
@@ -492,19 +511,21 @@ static V8_INLINE uint64_t AddTraceEventW
     arg_convertables[1].reset(reinterpret_cast<v8::ConvertableToTraceFormat*>(
         static_cast<intptr_t>(arg_values[1])));
   }
-  // DCHECK_LE(num_args, 2);
   v8::TracingController* controller =
       node::tracing::TraceEventHelper::GetTracingController();
   if (controller == nullptr) return 0;
   return controller->AddTraceEventWithTimestamp(
       phase, category_group_enabled, name, scope, id, bind_id, num_args,
       arg_names, arg_types, arg_values, arg_convertables, flags, timestamp);
+#endif
+  return 0;
 }
 
 static V8_INLINE void AddMetadataEventImpl(
     const uint8_t* category_group_enabled, const char* name, int32_t num_args,
     const char** arg_names, const uint8_t* arg_types,
     const uint64_t* arg_values, unsigned int flags) {
+#ifndef V8_USE_PERFETTO
   std::unique_ptr<v8::ConvertableToTraceFormat> arg_convertibles[2];
   if (num_args > 0 && arg_types[0] == TRACE_VALUE_TYPE_CONVERTABLE) {
     arg_convertibles[0].reset(reinterpret_cast<v8::ConvertableToTraceFormat*>(
@@ -520,6 +541,7 @@ static V8_INLINE void AddMetadataEventIm
   return agent->GetTracingController()->AddMetadataEvent(
       category_group_enabled, name, num_args, arg_names, arg_types, arg_values,
       arg_convertibles, flags);
+#endif
 }
 
 // Define SetTraceValue for each allowed type. It stores the type and
