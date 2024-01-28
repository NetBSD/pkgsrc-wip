$NetBSD$

Allow exceptions for now.

--- application.cpp.orig	2024-01-07 18:25:42.000000000 +0000
+++ application.cpp
@@ -243,10 +243,6 @@ wxLayoutDirection Application::GetLayout
 
 int Application::OnRun()
 {
-#if wxUSE_EXCEPTIONS
-#error why is wxWidgets uncaught exception handling enabled!?
-#endif
-
     //exception => Windows: let it crash and create mini dump!!! Linux/macOS: std::exception::what() logged to console
         [[maybe_unused]] const int rc = wxApp::OnRun();
     return static_cast<int>(exitCode_);
