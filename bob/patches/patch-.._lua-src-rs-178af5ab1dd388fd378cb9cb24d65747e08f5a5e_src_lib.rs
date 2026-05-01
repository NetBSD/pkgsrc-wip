$NetBSD$

* Fix build on NetBSD earmv{6,7}hf
* https://github.com/mlua-rs/lua-src-rs/issues/18

--- ../lua-src-rs-178af5ab1dd388fd378cb9cb24d65747e08f5a5e/src/lib.rs.orig	2026-05-01 16:35:10.188500428 +0000
+++ ../lua-src-rs-178af5ab1dd388fd378cb9cb24d65747e08f5a5e/src/lib.rs
@@ -136,7 +136,7 @@ impl Build {
             _ if target.contains("linux") => {
                 config.define("LUA_USE_LINUX", None);
             }
-            _ if target.ends_with("bsd") => {
+            _ if target.contains("bsd") => {
                 config.define("LUA_USE_LINUX", None);
             }
             _ if target.ends_with("illumos") => {
