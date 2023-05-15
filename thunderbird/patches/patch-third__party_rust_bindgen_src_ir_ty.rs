$NetBSD$

rust-bindgen upstream (#2338 and #2319), Self
Updates the bundled rust-bindgen crate to be compatible
with Clang/LLVM 16.

clang: Detect anonymous items explicitly, rather than relying on empty names.
In Clang 16, anonymous items may return names like `(anonymous union at ...)`
rather than emoty names.
The right way to detect them is using clang_Cursor_isAnonymous.
Fixes https://github.com/rust-lang/rust-bindgen/issues/2312
Closes https://github.com/rust-lang/rust-bindgen/pull/2316

ir: Don't crash with built-in unexposed types from libclang.
This fixes https://github.com/rust-lang/rust-bindgen/issues/2325

The issue is that `__bf16` is not exposed at all by libclang, which
causes us to crash. It's a bit of a shame libclang doesn't expose it but
there's no rust equivalent I think, so this should be ok for now.

Unfortunately no test because the header crashes older clang versions.

--- third_party/rust/bindgen/src/ir/ty.rs.orig	2023-04-03 19:42:41.000000000 +0200
+++ third_party/rust/bindgen/src/ir/ty.rs	2023-05-13 01:43:32.212969772 +0200
@@ -737,7 +737,12 @@
 
         let layout = ty.fallible_layout(ctx).ok();
         let cursor = ty.declaration();
-        let mut name = cursor.spelling();
+        let is_anonymous = cursor.is_anonymous();
+        let mut name = if is_anonymous {
+            None
+        } else {
+            Some(cursor.spelling()).filter(|n| !n.is_empty())
+        };
 
         debug!(
             "from_clang_ty: {:?}, ty: {:?}, loc: {:?}",
@@ -771,7 +776,7 @@
             if is_canonical_objcpointer && is_template_type_param {
                 // Objective-C generics are just ids with fancy name.
                 // To keep it simple, just name them ids
-                name = "id".to_owned();
+                name = Some("id".to_owned());
             }
         }
 
@@ -900,7 +905,7 @@
                                         return Err(ParseError::Recurse);
                                     }
                                 } else {
-                                    name = location.spelling();
+                                    name = Some(location.spelling());
                                 }
 
                                 let complex = CompInfo::from_ty(
@@ -942,7 +947,7 @@
                                                 CXType_Typedef
                                             );
 
-                                            name = current.spelling();
+                                            name = Some(current.spelling());
 
                                             let inner_ty = cur
                                                 .typedef_type()
@@ -1126,10 +1131,10 @@
                 CXType_Enum => {
                     let enum_ = Enum::from_ty(ty, ctx).expect("Not an enum?");
 
-                    if name.is_empty() {
+                    if !is_anonymous {
                         let pretty_name = ty.spelling();
                         if clang::is_valid_identifier(&pretty_name) {
-                            name = pretty_name;
+                            name = Some(pretty_name);
                         }
                     }
 
@@ -1144,12 +1149,12 @@
                     )
                     .expect("Not a complex type?");
 
-                    if name.is_empty() {
+                    if !is_anonymous {
                         // The pretty-printed name may contain typedefed name,
                         // but may also be "struct (anonymous at .h:1)"
                         let pretty_name = ty.spelling();
                         if clang::is_valid_identifier(&pretty_name) {
-                            name = pretty_name;
+                            name = Some(pretty_name);
                         }
                     }
 
@@ -1161,8 +1166,7 @@
                         location,
                         None,
                         ctx,
-                    )
-                    .expect("Not able to resolve vector element?");
+                    )?;
                     TypeKind::Vector(inner, ty.num_elements().unwrap())
                 }
                 CXType_ConstantArray => {
@@ -1189,7 +1193,9 @@
                 CXType_ObjCClass | CXType_ObjCInterface => {
                     let interface = ObjCInterface::from_ty(&location, ctx)
                         .expect("Not a valid objc interface?");
-                    name = interface.rust_name();
+                    if !is_anonymous {
+                        name = Some(interface.rust_name());
+                    }
                     TypeKind::ObjCInterface(interface)
                 }
                 CXType_Dependent => {
@@ -1207,7 +1213,7 @@
             }
         };
 
-        let name = if name.is_empty() { None } else { Some(name) };
+        name = name.filter(|n| !n.is_empty());
 
         let is_const = ty.is_const() ||
             (ty.kind() == CXType_ConstantArray &&
