$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/EditGCodeDialog.cpp.orig	2023-11-23 14:51:47.000000000 +0000
+++ src/slic3r/GUI/EditGCodeDialog.cpp
@@ -565,7 +565,7 @@ void ParamsModel::GetValue(wxVariant& va
 
     ParamsNode* node = static_cast<ParamsNode*>(item.GetID());
     if (col == (unsigned int)0)
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         variant << wxDataViewIconText(node->text, get_bmp_bundle(node->icon_name)->GetIconFor(m_ctrl->GetParent()));
 #else
         variant << DataViewBitmapText(node->text, get_bmp_bundle(node->icon_name)->GetBitmapFor(m_ctrl->GetParent()));
@@ -580,7 +580,7 @@ bool ParamsModel::SetValue(const wxVaria
 
     ParamsNode* node = static_cast<ParamsNode*>(item.GetID());
     if (col == (unsigned int)0) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         wxDataViewIconText data;
         data << variant;
         node->icon = data.GetIcon();
@@ -657,7 +657,7 @@ ParamsViewCtrl::ParamsViewCtrl(wxWindow 
     this->AssociateModel(model);
     model->SetAssociatedControl(this);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     wxDataViewIconTextRenderer* rd = new wxDataViewIconTextRenderer();
 #ifdef SUPPORTS_MARKUP
     rd->EnableMarkup(true);
