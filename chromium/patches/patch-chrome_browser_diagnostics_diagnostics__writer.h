$NetBSD$

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -15,6 +15,10 @@ namespace diagnostics {
 // Console base class used internally.
 class SimpleConsole;
 
+#if defined(MACHINE)
+#undef MACHINE
+#endif
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
