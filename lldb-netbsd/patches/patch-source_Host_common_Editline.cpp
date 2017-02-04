$NetBSD$

--- source/Host/common/Editline.cpp.orig	2017-02-04 18:35:35.000000000 +0000
+++ source/Host/common/Editline.cpp
@@ -22,6 +22,8 @@
 #include "lldb/Utility/SelectHelper.h"
 #include "lldb/Utility/StreamString.h"
 
+#include "llvm/Support/Threading.h"
+
 using namespace lldb_private;
 using namespace lldb_private::line_editor;
 
@@ -1151,8 +1153,8 @@ Editline::Editline(const char *editline_
     if (term_fd != -1) {
       static std::mutex *g_init_terminal_fds_mutex_ptr = nullptr;
       static std::set<int> *g_init_terminal_fds_ptr = nullptr;
-      static std::once_flag g_once_flag;
-      std::call_once(g_once_flag, [&]() {
+      LLVM_DEFINE_ONCE_FLAG(g_once_flag);
+      llvm::call_once(g_once_flag, [&]() {
         g_init_terminal_fds_mutex_ptr =
             new std::mutex(); // NOTE: Leak to avoid C++ destructor chain issues
         g_init_terminal_fds_ptr = new std::set<int>(); // NOTE: Leak to avoid
