$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/maglev/maglev-phi-representation-selector.cc.orig	2024-10-18 12:48:35.384421800 +0000
+++ v8/src/maglev/maglev-phi-representation-selector.cc
@@ -329,7 +329,8 @@ void MaglevPhiRepresentationSelector::En
   // should be tagged. We'll thus insert tagging operation on the untagged phi
   // inputs of {phi}.
 
-  for (int i = 0; i < phi->input_count(); i++) {
+  const int skip_backedge = phi->is_loop_phi() ? 1 : 0;
+  for (int i = 0; i < phi->input_count() - skip_backedge; i++) {
     ValueNode* input = phi->input(i).node();
     if (Phi* phi_input = input->TryCast<Phi>()) {
       phi->change_input(i, EnsurePhiTagged(phi_input, phi->predecessor_at(i),
