$NetBSD$

--- ui/base/ime/ime_engine_handler_interface.h.orig	2017-02-02 02:03:13.000000000 +0000
+++ ui/base/ime/ime_engine_handler_interface.h
@@ -138,7 +138,7 @@ class UI_BASE_IME_EXPORT IMEEngineHandle
   // Hides the input view window (from API call).
   virtual void HideInputView() = 0;
 
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
   // Get the id of the IME extension.
   virtual std::string GetExtensionId() const = 0;
