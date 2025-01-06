$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/tools/js2c.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/tools/js2c.cc
@@ -30,6 +30,7 @@ namespace js2c {
 int Main(int argc, char* argv[]);
 
 static bool is_verbose = false;
+static bool only_js = false;
 
 void Debug(const char* format, ...) {
   va_list arguments;
@@ -196,6 +197,7 @@ const char* kTemplate = R"(
 #include "node_builtins.h"
 #include "node_external_reference.h"
 #include "node_internals.h"
+#include "node_threadsafe_cow-inl.h"
 
 namespace node {
 
@@ -211,7 +213,11 @@ const ThreadsafeCopyOnWrite<BuiltinSourc
 }  // anonymous namespace
 
 void BuiltinLoader::LoadJavaScriptSource() {
-  source_ = global_source_map;
+  BuiltinSourceMap map = *source_.read();
+  BuiltinSourceMap new_map = *global_source_map.read();
+
+  map.merge(new_map);
+  source_ = ThreadsafeCopyOnWrite<BuiltinSourceMap>(map);
 }
 
 void RegisterExternalReferencesForInternalizedBuiltinCode(
@@ -228,6 +234,45 @@ UnionBytes BuiltinLoader::GetConfig() {
 }  // namespace node
 )";
 
+const char* kEmbedderTemplate = R"(
+#include "env-inl.h"
+#include "node_builtins.h"
+#include "node_external_reference.h"
+#include "node_internals.h"
+#include "node_threadsafe_cow-inl.h"
+
+namespace node {
+
+namespace builtins {
+
+%.*s
+namespace {
+const ThreadsafeCopyOnWrite<BuiltinSourceMap> global_source_map {
+  BuiltinSourceMap {
+%.*s
+  }  // BuiltinSourceMap
+
+};  // ThreadsafeCopyOnWrite
+}  // anonymous namespace
+
+void BuiltinLoader::LoadEmbedderJavaScriptSource() {
+  BuiltinSourceMap map = *source_.read();
+  BuiltinSourceMap new_map = *global_source_map.read();
+
+  map.merge(new_map);
+  source_ = ThreadsafeCopyOnWrite<BuiltinSourceMap>(map);
+}
+
+void EmbedderRegisterExternalReferencesForInternalizedBuiltinCode(
+  ExternalReferenceRegistry* registry) {
+%.*s
+}
+
+}  // namespace builtins
+
+}  // namespace node
+)";
+
 Fragment Format(const Fragments& definitions,
                 const Fragments& initializers,
                 const Fragments& registrations) {
@@ -237,13 +282,12 @@ Fragment Format(const Fragments& definit
   size_t init_size = init_buf.size();
   std::vector<char> reg_buf = Join(registrations, "\n");
   size_t reg_size = reg_buf.size();
-
-  size_t result_size =
-      def_size + init_size + reg_size + strlen(kTemplate) + 100;
+  size_t result_size = def_size + init_size + reg_size +
+          strlen(only_js ? kEmbedderTemplate: kTemplate) + 300;
   std::vector<char> result(result_size, 0);
   int r = snprintf(result.data(),
                    result_size,
-                   kTemplate,
+                   only_js ? kEmbedderTemplate: kTemplate,
                    static_cast<int>(def_buf.size()),
                    def_buf.data(),
                    static_cast<int>(init_buf.size()),
@@ -834,12 +878,15 @@ int JS2C(const FileList& js_files,
     }
   }
 
+  if (!only_js) {
   assert(FilenameIsConfigGypi(config));
   // "config.gypi" -> config_raw.
   int r = AddGypi("config", config, &definitions);
   if (r != 0) {
     return r;
   }
+  }
+
   Fragment out = Format(definitions, initializers, registrations);
   return WriteIfChanged(out, dest);
 }
@@ -865,6 +912,8 @@ int Main(int argc, char* argv[]) {
     std::string arg(argv[i]);
     if (arg == "--verbose") {
       is_verbose = true;
+    } else if (arg == "--only-js") {
+      only_js = true;
     } else if (arg == "--root") {
       if (i == argc - 1) {
         fprintf(stderr, "--root must be followed by a path\n");
@@ -913,6 +962,14 @@ int Main(int argc, char* argv[]) {
     }
   }
 
+  if (only_js) {
+    auto js_it = file_map.find(".js");
+
+    assert(file_map.size() == 1);
+    assert(js_it != file_map.end());
+
+    return JS2C(js_it->second, FileList(), std::string(), output);
+  } else {
   // Should have exactly 3 types: `.js`, `.mjs` and `.gypi`.
   assert(file_map.size() == 3);
   auto gypi_it = file_map.find(".gypi");
@@ -932,6 +989,7 @@ int Main(int argc, char* argv[]) {
   std::sort(mjs_it->second.begin(), mjs_it->second.end());
 
   return JS2C(js_it->second, mjs_it->second, gypi_it->second[0], output);
+  }
 }
 }  // namespace js2c
 }  // namespace node
@@ -940,4 +998,4 @@ NODE_MAIN(int argc, node::argv_type raw_
   char** argv;
   node::FixupMain(argc, raw_argv, &argv);
   return node::js2c::Main(argc, argv);
-}
+}
\ No newline at end of file
