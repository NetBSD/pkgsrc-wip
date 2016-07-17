$NetBSD$

--- third_party/pdfium/pdfium.gyp.orig	2016-06-24 01:03:59.000000000 +0000
+++ third_party/pdfium/pdfium.gyp
@@ -75,7 +75,7 @@
       ['pdf_enable_xfa==1', {
         'defines': ['PDF_ENABLE_XFA'],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'conditions': [
           ['target_arch=="x64"', {
             'defines' : [ '_FX_CPU_=_FX_X64_', ],
