$NetBSD: patch-protobuf_genproto.gypi,v 1.1 2013/01/14 06:21:30 ryo-on Exp $

* Use system's protoc command.

--- protobuf/genproto.gypi.orig	2012-08-31 05:37:07.000000000 +0000
+++ protobuf/genproto.gypi
@@ -36,7 +36,7 @@
   'conditions': [
     ['OS!="linux"', {
       'variables': {
-        'protoc_command%': '<(relative_dir)/<(mozc_build_tools_dir)/protoc<(EXECUTABLE_SUFFIX)',
+        'protoc_command%': 'protoc<(EXECUTABLE_SUFFIX)',
       },
     }, {  # else
       'conditions': [
