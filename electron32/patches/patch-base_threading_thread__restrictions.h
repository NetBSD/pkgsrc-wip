$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/threading/thread_restrictions.h.orig	2024-10-18 12:33:59.854224700 +0000
+++ base/threading/thread_restrictions.h
@@ -136,6 +136,7 @@ class KeyStorageLinux;
 class NativeBackendKWallet;
 class NativeDesktopMediaList;
 class PartnerBookmarksReader;
+class ProcessSingleton;
 class Profile;
 class ProfileImpl;
 class ScopedAllowBlockingForProfile;
@@ -286,6 +287,9 @@ class BackendImpl;
 class InFlightIO;
 bool CleanupDirectorySync(const base::FilePath&);
 }  // namespace disk_cache
+namespace electron {
+class ScopedAllowBlockingForElectron;
+}  // namespace electron
 namespace enterprise_connectors {
 class LinuxKeyRotationCommand;
 }  // namespace enterprise_connectors
@@ -593,6 +597,7 @@ class BASE_EXPORT [[maybe_unused, nodisc
   friend class ::DesktopNotificationBalloon;
   friend class ::FirefoxProfileLock;
   friend class ::GaiaConfig;
+  friend class ::ProcessSingleton;
   friend class ::ProfileImpl;
   friend class ::ScopedAllowBlockingForProfile;
   friend class ::StartupTabProviderImpl;
@@ -633,6 +638,7 @@ class BASE_EXPORT [[maybe_unused, nodisc
   friend class crosapi::LacrosThreadTypeDelegate;
   friend class crypto::ScopedAllowBlockingForNSS;  // http://crbug.com/59847
   friend class drive::FakeDriveService;
+  friend class electron::ScopedAllowBlockingForElectron;
   friend class extensions::InstalledLoader;
   friend class extensions::UnpackedInstaller;
   friend class font_service::internal::MappedFontFile;
