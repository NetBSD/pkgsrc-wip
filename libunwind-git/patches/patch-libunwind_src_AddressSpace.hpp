$NetBSD$

--- libunwind/src/AddressSpace.hpp.orig	2016-01-21 13:29:48.000000000 +0000
+++ libunwind/src/AddressSpace.hpp
@@ -35,7 +35,7 @@ namespace libunwind {
 #include "Registers.hpp"
 
 #if _LIBUNWIND_ARM_EHABI
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 
 typedef void *_Unwind_Ptr;
 
@@ -61,7 +61,7 @@ extern EHTEntry __exidx_end;
 #endif // !defined(_LIBUNWIND_IS_BAREMETAL)
 #endif // _LIBUNWIND_ARM_EHABI
 
-#if defined(__CloudABI__) || defined(__FreeBSD__) || defined(__linux__)
+#if defined(__CloudABI__) || defined(__FreeBSD__) || defined(__linux__) || defined(__NetBSD__)
 #if _LIBUNWIND_SUPPORT_DWARF_UNWIND && _LIBUNWIND_SUPPORT_DWARF_INDEX
 #include <link.h>
 // Macro for machine-independent access to the ELF program headers. This
