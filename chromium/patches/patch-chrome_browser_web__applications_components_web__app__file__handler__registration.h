$NetBSD$

--- chrome/browser/web_applications/components/web_app_file_handler_registration.h.orig	2020-07-08 21:40:36.000000000 +0000
+++ chrome/browser/web_applications/components/web_app_file_handler_registration.h
@@ -38,7 +38,7 @@ void RegisterFileHandlersWithOs(const Ap
 // If a shim app was required, also removes the shim app.
 void UnregisterFileHandlersWithOs(const AppId& app_id, Profile* profile);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 using RegisterMimeTypesOnLinuxCallback =
     base::OnceCallback<bool(base::FilePath profile_path,
                             std::string file_contents)>;
