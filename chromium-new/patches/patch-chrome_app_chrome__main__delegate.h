$NetBSD$

--- chrome/app/chrome_main_delegate.h.orig	2016-06-24 01:02:10.000000000 +0000
+++ chrome/app/chrome_main_delegate.h
@@ -38,7 +38,7 @@ class ChromeMainDelegate : public conten
       const std::string& process_type) override;
   bool ShouldSendMachPort(const std::string& process_type) override;
   bool DelaySandboxInitialization(const std::string& process_type) override;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   void ZygoteStarting(
       ScopedVector<content::ZygoteForkDelegate>* delegates) override;
   void ZygoteForked() override;
