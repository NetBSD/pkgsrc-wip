$NetBSD$

* Fix include on NetBSD for alloca

--- src/prebuilt/wasm2c_source_includes.cc.orig	2026-10-25 13:59:14.542368768 +0000
+++ src/prebuilt/wasm2c_source_includes.cc
@@ -20,7 +20,7 @@ R"w2c_template(#include <malloc.h>
 )w2c_template"
 R"w2c_template(#define alloca _alloca
 )w2c_template"
-R"w2c_template(#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+R"w2c_template(#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 )w2c_template"
 R"w2c_template(#include <stdlib.h>
 )w2c_template"
