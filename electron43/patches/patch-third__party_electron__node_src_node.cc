$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node.cc
@@ -790,12 +790,6 @@ static ExitCode ProcessGlobalArgsInterna
     return ExitCode::kInvalidCommandLineArgument2;
   }
 
-  // TODO(aduh95): remove this when the harmony-import-assertions flag
-  // is removed in V8.
-  if (std::find(v8_args.begin(), v8_args.end(),
-                "--no-harmony-import-assertions") == v8_args.end()) {
-    v8_args.emplace_back("--harmony-import-assertions");
-  }
   // TODO(aduh95): remove this when the harmony-import-attributes flag
   // is removed in V8.
   if (std::find(v8_args.begin(),
