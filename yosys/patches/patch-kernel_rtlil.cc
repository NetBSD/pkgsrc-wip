$NetBSD$

Add a destructor guard that can be accessed after the destructors are run.

--- kernel/rtlil.cc.orig	2022-10-05 09:30:38.000000000 +0000
+++ kernel/rtlil.cc
@@ -30,6 +30,7 @@
 
 YOSYS_NAMESPACE_BEGIN
 
+bool RTLIL::IdString::destruct_guard_ok;
 RTLIL::IdString::destruct_guard_t RTLIL::IdString::destruct_guard;
 std::vector<char*> RTLIL::IdString::global_id_storage_;
 dict<char*, int, hash_cstr_ops> RTLIL::IdString::global_id_index_;
