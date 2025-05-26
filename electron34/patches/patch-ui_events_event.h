$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/events/event.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/events/event.h
@@ -587,6 +587,9 @@ class EVENTS_EXPORT MouseEvent : public 
 
   const PointerDetails& pointer_details() const { return pointer_details_; }
 
+  bool is_system_menu() const { return is_system_menu_; }
+  void set_is_system_menu(bool is_menu) { is_system_menu_ = is_menu; }
+
   // Event:
   std::string ToString() const override;
   std::unique_ptr<Event> Clone() const override;
@@ -619,6 +622,8 @@ class EVENTS_EXPORT MouseEvent : public 
 
   // Structure for holding pointer details for implementing PointerEvents API.
   PointerDetails pointer_details_;
+
+  bool is_system_menu_ = false;
 };
 
 class ScrollEvent;
