$NetBSD$

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2016-11-10 20:02:10.000000000 +0000
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
