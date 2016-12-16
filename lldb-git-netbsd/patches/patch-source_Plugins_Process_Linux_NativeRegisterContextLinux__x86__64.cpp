$NetBSD$

--- source/Plugins/Process/Linux/NativeRegisterContextLinux_x86_64.cpp.orig	2016-12-14 14:10:24.000000000 +0000
+++ source/Plugins/Process/Linux/NativeRegisterContextLinux_x86_64.cpp
@@ -20,7 +20,9 @@
 #include "Plugins/Process/Utility/RegisterContextLinux_i386.h"
 #include "Plugins/Process/Utility/RegisterContextLinux_x86_64.h"
 
+#if !defined(__NetBSD__)
 #include <linux/elf.h>
+#endif
 
 using namespace lldb_private;
 using namespace lldb_private::process_linux;
@@ -223,7 +225,11 @@ static const RegisterSet g_reg_sets_x86_
 // On x86_64 NT_PRFPREG is used to access the FXSAVE area. On i386, we need to
 // use NT_PRXFPREG.
 static inline unsigned int fxsr_regset(const ArchSpec &arch) {
+#if !defined(__NetBSD__)
   return arch.GetAddressByteSize() == 8 ? NT_PRFPREG : NT_PRXFPREG;
+#else
+  return 0;
+#endif
 }
 
 // ----------------------------------------------------------------------------
