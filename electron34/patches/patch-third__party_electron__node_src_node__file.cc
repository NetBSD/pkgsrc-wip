$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_file.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_file.cc
@@ -19,14 +19,11 @@
 // OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 // USE OR OTHER DEALINGS IN THE SOFTWARE.
 #include "node_file.h"  // NOLINT(build/include_inline)
-#include "ada.h"
 #include "aliased_buffer-inl.h"
 #include "memory_tracker-inl.h"
 #include "node_buffer.h"
-#include "node_errors.h"
 #include "node_external_reference.h"
 #include "node_file-inl.h"
-#include "node_metadata.h"
 #include "node_process-inl.h"
 #include "node_stat_watcher.h"
 #include "node_url.h"
@@ -3127,135 +3124,6 @@ constexpr std::array<std::string_view, 1
 
 }  // namespace
 
-void BindingData::LegacyMainResolve(const FunctionCallbackInfo<Value>& args) {
-  CHECK_GE(args.Length(), 1);
-  CHECK(args[0]->IsString());
-
-  Environment* env = Environment::GetCurrent(args);
-  auto isolate = env->isolate();
-
-  Utf8Value utf8_package_json_url(isolate, args[0]);
-  auto package_json_url =
-      ada::parse<ada::url_aggregator>(utf8_package_json_url.ToStringView());
-
-  if (!package_json_url) {
-    THROW_ERR_INVALID_URL(isolate, "Invalid URL");
-    return;
-  }
-
-  std::string package_initial_file = "";
-
-  ada::result<ada::url_aggregator> file_path_url;
-  std::optional<std::string> initial_file_path;
-  std::string file_path;
-
-  if (args.Length() >= 2 && args[1]->IsString()) {
-    auto package_config_main = Utf8Value(isolate, args[1]).ToString();
-
-    file_path_url = ada::parse<ada::url_aggregator>(
-        std::string("./") + package_config_main, &package_json_url.value());
-
-    if (!file_path_url) {
-      THROW_ERR_INVALID_URL(isolate, "Invalid URL");
-      return;
-    }
-
-    initial_file_path = node::url::FileURLToPath(env, *file_path_url);
-    if (!initial_file_path.has_value()) {
-      return;
-    }
-
-    node::url::FromNamespacedPath(&initial_file_path.value());
-
-    package_initial_file = *initial_file_path;
-
-    for (int i = 0; i < legacy_main_extensions_with_main_end; i++) {
-      file_path = *initial_file_path + std::string(legacy_main_extensions[i]);
-
-      switch (FilePathIsFile(env, file_path)) {
-        case BindingData::FilePathIsFileReturnType::kIsFile:
-          return args.GetReturnValue().Set(i);
-        case BindingData::FilePathIsFileReturnType::kIsNotFile:
-          continue;
-        case BindingData::FilePathIsFileReturnType::
-            kThrowInsufficientPermissions:
-          // the default behavior when do not have permission is to return
-          // and exit the execution of the method as soon as possible
-          // the internal function will throw the exception
-          return;
-        default:
-          UNREACHABLE();
-      }
-    }
-  }
-
-  file_path_url =
-      ada::parse<ada::url_aggregator>("./index", &package_json_url.value());
-
-  if (!file_path_url) {
-    THROW_ERR_INVALID_URL(isolate, "Invalid URL");
-    return;
-  }
-
-  initial_file_path = node::url::FileURLToPath(env, *file_path_url);
-  if (!initial_file_path.has_value()) {
-    return;
-  }
-
-  node::url::FromNamespacedPath(&initial_file_path.value());
-
-  for (int i = legacy_main_extensions_with_main_end;
-       i < legacy_main_extensions_package_fallback_end;
-       i++) {
-    file_path = *initial_file_path + std::string(legacy_main_extensions[i]);
-
-    switch (FilePathIsFile(env, file_path)) {
-      case BindingData::FilePathIsFileReturnType::kIsFile:
-        return args.GetReturnValue().Set(i);
-      case BindingData::FilePathIsFileReturnType::kIsNotFile:
-        continue;
-      case BindingData::FilePathIsFileReturnType::kThrowInsufficientPermissions:
-        // the default behavior when do not have permission is to return
-        // and exit the execution of the method as soon as possible
-        // the internal function will throw the exception
-        return;
-      default:
-        UNREACHABLE();
-    }
-  }
-
-  if (package_initial_file == "")
-    package_initial_file = *initial_file_path + ".js";
-
-  std::optional<std::string> module_base;
-
-  if (args.Length() >= 3 && args[2]->IsString()) {
-    Utf8Value utf8_base_path(isolate, args[2]);
-    auto base_url =
-        ada::parse<ada::url_aggregator>(utf8_base_path.ToStringView());
-
-    if (!base_url) {
-      THROW_ERR_INVALID_URL(isolate, "Invalid URL");
-      return;
-    }
-
-    module_base = node::url::FileURLToPath(env, *base_url);
-    if (!module_base.has_value()) {
-      return;
-    }
-  } else {
-    THROW_ERR_INVALID_ARG_TYPE(
-        isolate,
-        "The \"base\" argument must be of type string or an instance of URL.");
-    return;
-  }
-
-  THROW_ERR_MODULE_NOT_FOUND(isolate,
-                             "Cannot find package '%s' imported from %s",
-                             package_initial_file,
-                             *module_base);
-}
-
 void BindingData::MemoryInfo(MemoryTracker* tracker) const {
   tracker->TrackField("stats_field_array", stats_field_array);
   tracker->TrackField("stats_field_bigint_array", stats_field_bigint_array);
@@ -3355,19 +3223,6 @@ InternalFieldInfoBase* BindingData::Seri
   return info;
 }
 
-void BindingData::CreatePerIsolateProperties(IsolateData* isolate_data,
-                                             Local<ObjectTemplate> target) {
-  Isolate* isolate = isolate_data->isolate();
-
-  SetMethod(
-      isolate, target, "legacyMainResolve", BindingData::LegacyMainResolve);
-}
-
-void BindingData::RegisterExternalReferences(
-    ExternalReferenceRegistry* registry) {
-  registry->Register(BindingData::LegacyMainResolve);
-}
-
 static void CreatePerIsolateProperties(IsolateData* isolate_data,
                                        Local<ObjectTemplate> target) {
   Isolate* isolate = isolate_data->isolate();
@@ -3422,7 +3277,6 @@ static void CreatePerIsolateProperties(I
   SetMethod(isolate, target, "mkdtemp", Mkdtemp);
 
   StatWatcher::CreatePerIsolateProperties(isolate_data, target);
-  BindingData::CreatePerIsolateProperties(isolate_data, target);
 
   target->Set(
       FIXED_ONE_BYTE_STRING(isolate, "kFsStatsFieldsNumber"),
@@ -3495,7 +3349,6 @@ BindingData* FSReqBase::binding_data() {
 void RegisterExternalReferences(ExternalReferenceRegistry* registry) {
   registry->Register(Access);
   StatWatcher::RegisterExternalReferences(registry);
-  BindingData::RegisterExternalReferences(registry);
 
   registry->Register(GetFormatOfExtensionlessFile);
   registry->Register(Close);
