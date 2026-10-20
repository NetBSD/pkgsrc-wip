$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/base/platform/platform-freebsd.cc.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/v8/src/base/platform/platform-freebsd.cc
@@ -48,7 +48,7 @@ static unsigned StringToLong(char* buffe
 }
 
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
-  std::vector<SharedLibraryAddress> result;
+  std::vector<SharedLibraryAddress> address_result;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
   size_t miblen = sizeof(mib) / sizeof(mib[0]);
   size_t buffer_size;
@@ -81,7 +81,7 @@ std::vector<OS::SharedLibraryAddress> OS
           } else {
             lib_name = std::string(path);
           }
-          result.push_back(SharedLibraryAddress(
+          address_result.push_back(SharedLibraryAddress(
               lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
               reinterpret_cast<uintptr_t>(map->kve_end)));
         }
@@ -90,7 +90,7 @@ std::vector<OS::SharedLibraryAddress> OS
       }
     }
   }
-  return result;
+  return address_result;
 }
 
 void OS::SignalCodeMovingGC() {}
