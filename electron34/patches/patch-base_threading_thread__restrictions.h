$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/threading/thread_restrictions.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/threading/thread_restrictions.h
@@ -132,6 +132,7 @@ class KeyStorageLinux;
 class NativeBackendKWallet;
 class NativeDesktopMediaList;
 class PartnerBookmarksReader;
+class ProcessSingleton;
 class Profile;
 class ProfileImpl;
 class ScopedAllowBlockingForProfile;
@@ -282,6 +283,9 @@ class BackendImpl;
 class InFlightIO;
 bool CleanupDirectorySync(const base::FilePath&);
 }  // namespace disk_cache
+namespace electron {
+class ScopedAllowBlockingForElectron;
+}  // namespace electron
 namespace enterprise_connectors {
 class LinuxKeyRotationCommand;
 }  // namespace enterprise_connectors
@@ -576,6 +580,7 @@ class BASE_EXPORT ScopedAllowBlocking {
   friend class ::DesktopNotificationBalloon;
   friend class ::FirefoxProfileLock;
   friend class ::GaiaConfig;
+  friend class ::ProcessSingleton;
   friend class ::ProfileImpl;
   friend class ::ScopedAllowBlockingForProfile;
   friend class ::StartupTabProviderImpl;
@@ -616,6 +621,7 @@ class BASE_EXPORT ScopedAllowBlocking {
   friend class crosapi::LacrosThreadTypeDelegate;
   friend class crypto::ScopedAllowBlockingForNSS;  // http://crbug.com/59847
   friend class drive::FakeDriveService;
+  friend class electron::ScopedAllowBlockingForElectron;
   friend class extensions::InstalledLoader;
   friend class extensions::UnpackedInstaller;
   friend class font_service::internal::MappedFontFile;
