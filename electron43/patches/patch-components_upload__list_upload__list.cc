$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/upload_list/upload_list.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/upload_list/upload_list.cc
@@ -65,6 +65,10 @@ void UploadList::Load(base::OnceClosure 
       base::BindOnce(&UploadList::OnLoadComplete, this));
 }
 
+void UploadList::LoadSync() {
+  uploads_ = LoadUploadList();
+}
+
 void UploadList::Clear(const base::Time& begin,
                        const base::Time& end,
                        base::OnceClosure callback) {
