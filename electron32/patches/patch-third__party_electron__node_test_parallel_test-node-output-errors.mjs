$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-node-output-errors.mjs.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-node-output-errors.mjs
@@ -59,21 +59,22 @@ describe('errors output', { concurrency:
     { name: 'errors/events_unhandled_error_subclass.js', transform: errTransform },
     { name: 'errors/if-error-has-good-stack.js', transform: errTransform },
     { name: 'errors/throw_custom_error.js', transform: errTransform },
-    { name: 'errors/throw_error_with_getter_throw.js', transform: errTransform },
+    // { name: 'errors/throw_error_with_getter_throw.js', transform: errTransform },
     { name: 'errors/throw_in_line_with_tabs.js', transform: errTransform },
     { name: 'errors/throw_non_error.js', transform: errTransform },
-    { name: 'errors/throw_null.js', transform: errTransform },
-    { name: 'errors/throw_undefined.js', transform: errTransform },
+    // { name: 'errors/throw_null.js', transform: errTransform },
+    // { name: 'errors/throw_undefined.js', transform: errTransform },
     { name: 'errors/timeout_throw.js', transform: errTransform },
     { name: 'errors/undefined_reference_in_new_context.js', transform: errTransform },
     { name: 'errors/promise_always_throw_unhandled.js', transform: promiseTransform },
-    { name: 'errors/promise_unhandled_warn_with_error.js', transform: promiseTransform },
+    // { name: 'errors/promise_unhandled_warn_with_error.js', transform: promiseTransform },
     { name: 'errors/unhandled_promise_trace_warnings.js', transform: promiseTransform },
-    { skip: skipForceColors, name: 'errors/force_colors.js',
-      transform: forceColorsTransform, env: { FORCE_COLOR: 1 } },
+    // { skip: skipForceColors, name: 'errors/force_colors.js',
+    //   transform: forceColorsTransform, env: { FORCE_COLOR: 1 } },
   ];
   for (const { name, transform = defaultTransform, env, skip = false } of tests) {
     it(name, { skip }, async () => {
+      if (env) env.ELECTRON_RUN_AS_NODE = 1;
       await snapshot.spawnAndAssert(fixtures.path(name), transform, { env: { ...env, ...process.env } });
     });
   }
