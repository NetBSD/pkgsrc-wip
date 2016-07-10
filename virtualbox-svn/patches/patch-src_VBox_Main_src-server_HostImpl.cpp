$NetBSD$

--- src/VBox/Main/src-server/HostImpl.cpp.orig	2016-07-10 20:33:47.000000000 +0000
+++ src/VBox/Main/src-server/HostImpl.cpp
@@ -47,11 +47,11 @@
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
 
@@ -214,7 +214,7 @@ struct Host::Data
     bool                    fDVDDrivesListBuilt,
                             fFloppyDrivesListBuilt;
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /** Object with information about host drives */
     VBoxMainDriveInfo       hostDrives;
 #endif
@@ -407,7 +407,7 @@ HRESULT Host::init(VirtualBox *aParent)
     m->f3DAccelerationSupported = false;
 #endif
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /* Extract the list of configured host-only interfaces */
     std::set<Utf8Str> aConfiguredNames;
     SafeArray<BSTR> aGlobalExtraDataKeys;
@@ -441,7 +441,7 @@ HRESULT Host::init(VirtualBox *aParent)
             LogRel(("failed to create %s, error (0x%x)\n", it->c_str(), r));
     }
 
-#endif /* defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) */
+#endif /* defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD) */
 
     /* Confirm a successful initialization */
     autoInitSpan.setSucceeded();
@@ -2087,7 +2087,7 @@ HRESULT Host::i_buildDVDDrivesList(Media
             i_getDVDInfoFromDevTree(list);
         }
 
-#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         if (RT_SUCCESS(m->hostDrives.updateDVDs()))
             for (DriveInfoList::const_iterator it = m->hostDrives.DVDBegin();
                 SUCCEEDED(rc) && it != m->hostDrives.DVDEnd(); ++it)
