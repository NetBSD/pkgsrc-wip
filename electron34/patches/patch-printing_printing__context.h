$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_context.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ printing/printing_context.h
@@ -206,6 +206,9 @@ class COMPONENT_EXPORT(PRINTING) Printin
 
   bool PrintingAborted() const { return abort_printing_; }
 
+  // Reinitializes the settings for object reuse.
+  void ResetSettings();
+
   int job_id() const { return job_id_; }
 
 #if BUILDFLAG(ENABLE_OOP_PRINTING)
@@ -224,9 +227,6 @@ class COMPONENT_EXPORT(PRINTING) Printin
       Delegate* delegate,
       ProcessBehavior process_behavior);
 
-  // Reinitializes the settings for object reuse.
-  void ResetSettings();
-
   // Does bookkeeping when an error occurs.
   virtual mojom::ResultCode OnError();
 
