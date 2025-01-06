$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/upload_list/upload_list.h.orig	2024-10-18 12:34:11.292005500 +0000
+++ components/upload_list/upload_list.h
@@ -82,6 +82,8 @@ class UploadList : public base::RefCount
   // overwrite the previously supplied one, and the first will not be called.
   void Load(base::OnceClosure callback);
 
+  void LoadSync();
+
   // Clears any data associated with the upload list, where the upload time or
   // capture time falls within the given range.
   void Clear(const base::Time& begin,
