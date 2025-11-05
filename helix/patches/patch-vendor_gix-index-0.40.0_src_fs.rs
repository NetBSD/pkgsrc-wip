$NetBSD$

This is fixed upstream in a later version: https://github.com/GitoxideLabs/gitoxide/commit/00e89341cd89f58d031eee8a4e60f6ebdcd53185

--- ../vendor/gix-index-0.40.0/src/fs.rs.orig	2025-11-02 10:14:48.783898086 +0000
+++ ../vendor/gix-index-0.40.0/src/fs.rs
@@ -59,10 +59,8 @@ impl Metadata {
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let seconds = self.0.st_mtim.tv_sec;
 
-            #[cfg(not(any(target_os = "netbsd", target_os = "aix", target_os = "hurd")))]
+            #[cfg(not(any(target_os = "aix", target_os = "hurd")))]
             let nanoseconds = self.0.st_mtime_nsec;
-            #[cfg(target_os = "netbsd")]
-            let nanoseconds = self.0.st_mtimensec;
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let nanoseconds = self.0.st_mtim.tv_nsec;
 
@@ -88,10 +86,8 @@ impl Metadata {
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let seconds = self.0.st_ctim.tv_sec;
 
-            #[cfg(not(any(target_os = "netbsd", target_os = "aix", target_os = "hurd")))]
+            #[cfg(not(any(target_os = "aix", target_os = "hurd")))]
             let nanoseconds = self.0.st_ctime_nsec;
-            #[cfg(target_os = "netbsd")]
-            let nanoseconds = self.0.st_ctimensec;
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let nanoseconds = self.0.st_ctim.tv_nsec;
