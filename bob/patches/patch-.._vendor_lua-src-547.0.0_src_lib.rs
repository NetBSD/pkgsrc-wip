$NetBSD: $

* Fix build on NetBSD earmv{6,7}hf
* https://github.com/mlua-rs/lua-src-rs/issues/18

--- ../vendor/lua-src-547.0.0/src/lib.rs.orig	2026-04-27 16:25:47.910850386 +0000
+++ ../vendor/lua-src-547.0.0/src/lib.rs	2026-04-27 16:26:44.169681330 +0000
@@ -85,7 +85,7 @@
             _ if target.contains("linux") => {
                 config.define("LUA_USE_LINUX", None);
             }
-            _ if target.ends_with("bsd") => {
+            _ if target.contains("bsd") => {
                 config.define("LUA_USE_LINUX", None);
             }
             _ if target.contains("apple-darwin") => {
