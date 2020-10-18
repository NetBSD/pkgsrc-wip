$NetBSD$

Adjust to recent-ish NetBSD EV_SET(3) API.

--- tdutils/td/utils/port/detail/KQueue.cpp.orig	2020-01-31 00:47:49.000000000 +0000
+++ tdutils/td/utils/port/detail/KQueue.cpp
@@ -81,11 +81,7 @@ void KQueue::add_change(std::uintptr_t i
   if (changes_n_ == static_cast<int>(events_.size())) {
     flush_changes();
   }
-#if TD_NETBSD
-  auto set_udata = reinterpret_cast<std::intptr_t>(udata);
-#else
   auto set_udata = udata;
-#endif
   EV_SET(&events_[changes_n_], ident, filter, flags, fflags, data, set_udata);
   VLOG(fd) << "Subscribe [fd:" << ident << "] [filter:" << filter << "] [udata: " << udata << "]";
   changes_n_++;
