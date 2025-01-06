$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/module_wrap.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/module_wrap.cc
@@ -186,7 +186,9 @@ void ModuleWrap::New(const FunctionCallb
         export_names[i] = export_name_val.As<String>();
       }
 
-      module = Module::CreateSyntheticModule(isolate, url, export_names,
+
+      module = Module::CreateSyntheticModule(isolate, url,
+        v8::MemorySpan<const Local<String>>(export_names.begin(), export_names.end()),
         SyntheticModuleEvaluationStepsCallback);
     } else {
       ScriptCompiler::CachedData* cached_data = nullptr;
@@ -200,8 +202,7 @@ void ModuleWrap::New(const FunctionCallb
       }
 
       Local<String> source_text = args[2].As<String>();
-      ScriptOrigin origin(isolate,
-                          url,
+      ScriptOrigin origin(url,
                           line_offset,
                           column_offset,
                           true,                             // is cross origin
@@ -462,7 +463,6 @@ void ModuleWrap::Evaluate(const Function
 
   ShouldNotAbortOnUncaughtScope no_abort_scope(realm->env());
   TryCatchScope try_catch(realm->env());
-  Isolate::SafeForTerminationScope safe_for_termination(isolate);
 
   bool timed_out = false;
   bool received_signal = false;
@@ -587,11 +587,10 @@ void ModuleWrap::EvaluateSync(const Func
 
   if (module->IsGraphAsync()) {
     CHECK(env->options()->print_required_tla);
-    auto stalled = module->GetStalledTopLevelAwaitMessage(isolate);
-    if (stalled.size() != 0) {
-      for (auto pair : stalled) {
-        Local<v8::Message> message = std::get<1>(pair);
-
+    auto stalled_messages =
+        std::get<1>(module->GetStalledTopLevelAwaitMessages(isolate));
+    if (stalled_messages.size() != 0) {
+      for (auto& message : stalled_messages) {
         std::string reason = "Error: unexpected top-level await at ";
         std::string info =
             FormatErrorMessage(isolate, context, "", message, true);
@@ -752,7 +751,7 @@ MaybeLocal<Module> ModuleWrap::ResolveMo
   return module->module_.Get(isolate);
 }
 
-static MaybeLocal<Promise> ImportModuleDynamically(
+MaybeLocal<Promise> ImportModuleDynamically(
     Local<Context> context,
     Local<v8::Data> host_defined_options,
     Local<Value> resource_name,
@@ -817,12 +816,13 @@ void ModuleWrap::SetImportModuleDynamica
   Realm* realm = Realm::GetCurrent(args);
   HandleScope handle_scope(isolate);
 
-  CHECK_EQ(args.Length(), 1);
+  CHECK_EQ(args.Length(), 2);
   CHECK(args[0]->IsFunction());
   Local<Function> import_callback = args[0].As<Function>();
   realm->set_host_import_module_dynamically_callback(import_callback);
 
-  isolate->SetHostImportModuleDynamicallyCallback(ImportModuleDynamically);
+  if (args[1]->IsBoolean() && args[1]->BooleanValue(isolate))
+    isolate->SetHostImportModuleDynamicallyCallback(ImportModuleDynamically);
 }
 
 void ModuleWrap::HostInitializeImportMetaObjectCallback(
@@ -864,13 +864,14 @@ void ModuleWrap::SetInitializeImportMeta
   Realm* realm = Realm::GetCurrent(args);
   Isolate* isolate = realm->isolate();
 
-  CHECK_EQ(args.Length(), 1);
+  CHECK_EQ(args.Length(), 2);
   CHECK(args[0]->IsFunction());
   Local<Function> import_meta_callback = args[0].As<Function>();
   realm->set_host_initialize_import_meta_object_callback(import_meta_callback);
 
-  isolate->SetHostInitializeImportMetaObjectCallback(
-      HostInitializeImportMetaObjectCallback);
+  if (args[1]->IsBoolean() && args[1]->BooleanValue(isolate))
+    isolate->SetHostInitializeImportMetaObjectCallback(
+        HostInitializeImportMetaObjectCallback);
 }
 
 MaybeLocal<Value> ModuleWrap::SyntheticModuleEvaluationStepsCallback(
