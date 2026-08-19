$NetBSD$

Fix EV_SET on NetBSD — NetBSD's EV_SET macro uses static_cast<void*>(udata)
via __CAST, but the TD_NETBSD branch converts udata to intptr_t first,
causing invalid static_cast from long int to void*. Cast back to void*
before passing to EV_SET.

--- tdutils/td/utils/port/detail/KQueue.cpp.orig	2026-07-27 20:19:00.000000000 +0000
+++ tdutils/td/utils/port/detail/KQueue.cpp
@@ -89,9 +89,9 @@
 #if TD_NETBSD
   auto set_udata = reinterpret_cast<std::intptr_t>(udata);
 #else
   auto set_udata = udata;
 #endif
-  EV_SET(&events_[changes_n_], ident, filter, flags, fflags, data, set_udata);
+  EV_SET(&events_[changes_n_], ident, filter, flags, fflags, data, reinterpret_cast<void *>(set_udata));
   VLOG(fd) << "Subscribe [fd:" << ident << "] [filter:" << filter << "] [udata: " << udata << "]";
   changes_n_++;
 }
