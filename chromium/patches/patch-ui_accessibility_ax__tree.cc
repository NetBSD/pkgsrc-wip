$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/ax_tree.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ ui/accessibility/ax_tree.cc
@@ -867,7 +867,7 @@ bool AXTree::ComputeNodeIsIgnoredChanged
   return old_node_is_ignored != new_node_is_ignored;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ExtraAnnouncementNodes::ExtraAnnouncementNodes(AXNode* root) {
   assertive_node_ = CreateNode("assertive", root);
   polite_node_ = CreateNode("polite", root);
@@ -960,7 +960,7 @@ AXNode* AXTree::GetFromId(AXNodeID id) c
 
 void AXTree::Destroy() {
   base::ElapsedThreadTimer timer;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ClearExtraAnnouncementNodes();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -2187,7 +2187,7 @@ void AXTree::NotifyNodeAttributesWillCha
                     new_data);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AXTree::ClearExtraAnnouncementNodes() {
   if (!extra_announcement_nodes_) {
     return;
@@ -2576,7 +2576,7 @@ bool AXTree::CreateNewChildVector(
     AXTreeUpdateState* update_state) {
   DCHECK(GetTreeUpdateInProgressState());
   bool success = true;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If the root node has children added, clear the extra announcement nodes,
   // which should always have their indices as the last two children of the root
   // node. They will be recreated if needed, and given the correct indices.
