$NetBSD$

--- content/renderer/pepper/pepper_media_device_manager.cc.orig	2017-02-02 02:02:54.000000000 +0000
+++ content/renderer/pepper/pepper_media_device_manager.cc
@@ -89,9 +89,10 @@ void PepperMediaDeviceManager::Enumerate
                  callback, ToMediaDeviceType(type)));
 #else
   base::ThreadTaskRunnerHandle::Get()->PostTask(
-      FROM_HERE,
-      base::Bind(&PepperMediaDeviceManager::DevicesEnumerated, AsWeakPtr(),
-                 callback, ToMediaDeviceType(type), MediaDeviceInfoArray()));
+      FROM_HERE, base::Bind(&PepperMediaDeviceManager::DevicesEnumerated,
+                            AsWeakPtr(), callback, ToMediaDeviceType(type),
+                            std::vector<MediaDeviceInfoArray>()));
+
 #endif
 }
 
