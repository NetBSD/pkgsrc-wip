$NetBSD$

* Add NetBSD support

--- ../vendor/linkme-impl-0.3.37/src/declaration.rs.orig	2006-07-24 03:21:28.000000000 +0200
+++ ../vendor/linkme-impl-0.3.37/src/declaration.rs	2026-11-09 17:12:08.132113605 +0100
@@ -144,31 +144,32 @@
                 target_os = "illumos",
                 target_os = "freebsd",
                 target_os = "openbsd",
+                target_os = "netbsd",
                 target_os = "psp",
             ))]
             #unsafe_extern extern "Rust" {
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_section_start)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_section_start)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_section_start)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_section_start)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"), link_name = #bsd_section_start)]
                 static LINKME_START: [<#ty as #linkme_path::#private::Slice>::Element; 0];
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_section_stop)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_section_stop)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_section_stop)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_section_stop)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"), link_name = #bsd_section_stop)]
                 static LINKME_STOP: [<#ty as #linkme_path::#private::Slice>::Element; 0];
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_dupcheck_start)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_dupcheck_start)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_dupcheck_start)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_dupcheck_start)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"), link_name = #bsd_dupcheck_start)]
                 static DUPCHECK_START: ();
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_dupcheck_stop)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_dupcheck_stop)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_dupcheck_stop)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_dupcheck_stop)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"), link_name = #bsd_dupcheck_stop)]
                 static DUPCHECK_STOP: ();
             }
 
@@ -201,11 +202,12 @@
                 target_os = "illumos",
                 target_os = "freebsd",
                 target_os = "openbsd",
+                target_os = "netbsd",
                 target_os = "psp",
             ))]
             #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), #unsafe_attr(#link_section_attr = #linux_section))]
             #[cfg_attr(target_os = "illumos", #unsafe_attr(#link_section_attr = #illumos_section))]
-            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), #unsafe_attr(#link_section_attr = #bsd_section))]
+            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"), #unsafe_attr(#link_section_attr = #bsd_section))]
             static mut LINKME_PLEASE: [<#ty as #linkme_path::#private::Slice>::Element; 0] = [];
 
             #used
@@ -213,7 +215,7 @@
             #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), #unsafe_attr(#link_section_attr = #macho_dupcheck))]
             #[cfg_attr(any(target_os = "uefi", target_os = "windows"), #unsafe_attr(#link_section_attr = #windows_dupcheck))]
             #[cfg_attr(target_os = "illumos", #unsafe_attr(#link_section_attr = #illumos_dupcheck))]
-            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), #unsafe_attr(#link_section_attr = #bsd_dupcheck))]
+            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"), #unsafe_attr(#link_section_attr = #bsd_dupcheck))]
             static DUPCHECK: #linkme_path::#private::isize = 1;
 
             #[cfg(not(any(
@@ -229,6 +231,7 @@
                 target_os = "illumos",
                 target_os = "freebsd",
                 target_os = "openbsd",
+                target_os = "netbsd",
                 target_os = "psp",
             )))]
             #unsupported_platform
@@ -291,7 +294,7 @@
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), #unsafe_attr(#link_section_attr = $macho_section))]
                 #[cfg_attr(any(target_os = "uefi", target_os = "windows"), #unsafe_attr(#link_section_attr = $windows_section))]
                 #[cfg_attr(target_os = "illumos", #unsafe_attr(#link_section_attr = $illumos_section))]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), #unsafe_attr(#link_section_attr = $bsd_section))]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"), #unsafe_attr(#link_section_attr = $bsd_section))]
                 $item
             };
         }
