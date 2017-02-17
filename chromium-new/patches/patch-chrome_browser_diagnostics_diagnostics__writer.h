$NetBSD$

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2017-02-02 02:02:48.000000000 +0000
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -19,7 +19,7 @@ class DiagnosticsWriter : public Diagnos
  public:
   // The type of formatting done by this writer.
   enum FormatType {
-    MACHINE,
+    THEMACHINE,
     LOG,
     HUMAN
   };
