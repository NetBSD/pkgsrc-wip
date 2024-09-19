$NetBSD$

--- src/VBox/Main/src-server/HostImpl.cpp.orig	2016-03-04 19:29:40.000000000 +0000
+++ src/VBox/Main/src-server/HostImpl.cpp
@@ -41,11 +41,11 @@
 #include "MediumImpl.h"
 #include "HostPower.h"
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <HostHardwareLinux.h>
 #endif
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <set>
 #endif
 
@@ -212,7 +212,7 @@ struct Host::Data
     bool                    fDVDDrivesListBuilt,
                             fFloppyDrivesListBuilt;
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /** Object with information about host drives */
     VBoxMainDriveInfo       hostDrives;
 #endif
@@ -288,6 +288,8 @@ HRESULT Host::init(VirtualBox *aParent)
     m->pUSBProxyService = new USBProxyServiceWindows(this);
 # elif defined(RT_OS_FREEBSD)
     m->pUSBProxyService = new USBProxyServiceFreeBSD(this);
+# elif defined(RT_OS_NETBSD)
+    m->pUSBProxyService = new USBProxyServiceNetBSD(this);
 # else
     m->pUSBProxyService = new USBProxyService(this);
 # endif
@@ -419,7 +421,7 @@ HRESULT Host::init(VirtualBox *aParent)
     m->f3DAccelerationSupported = false;
 #endif
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /* Extract the list of configured host-only interfaces */
     std::set<Utf8Str> aConfiguredNames;
     SafeArray<BSTR> aGlobalExtraDataKeys;
@@ -453,7 +455,7 @@ HRESULT Host::init(VirtualBox *aParent)
             LogRel(("failed to create %s, error (0x%x)\n", it->c_str(), r));
     }
 
-#endif /* defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) */
+#endif /* defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD) */
 
     /* Confirm a successful initialization */
     autoInitSpan.setSucceeded();
@@ -2074,7 +2076,7 @@ HRESULT Host::i_buildDVDDrivesList(Media
             i_getDVDInfoFromDevTree(list);
         }
 
-#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         if (RT_SUCCESS(m->hostDrives.updateDVDs()))
             for (DriveInfoList::const_iterator it = m->hostDrives.DVDBegin();
                 SUCCEEDED(rc) && it != m->hostDrives.DVDEnd(); ++it)
