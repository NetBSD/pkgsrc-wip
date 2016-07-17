$NetBSD$

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -18,7 +18,7 @@ class DiagnosticsWriter : public Diagnos
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
