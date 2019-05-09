$NetBSD$

From OpenBSD xenocara

Make similiar changes to the i386 tsd dispatch assembly as libglvnd to
avoid a text relocation fixing the build with lld.

This time store the address of the GOT in ebx as required before calling
the PLT stub and change .balign value to match X86_ENTRY_SIZE as suggested
by naddy.

--- src/mapi/entry_x86_tsd.h.orig	2019-03-06 23:05:20.000000000 +0000
+++ src/mapi/entry_x86_tsd.h
@@ -31,18 +31,51 @@
 #define HIDDEN
 #endif
 
+#if defined(X86_TSD_OPENBSD)
+#define X86_ENTRY_SIZE 64
+#else
 #define X86_ENTRY_SIZE 32
+#endif
 
 __asm__(".text\n"
+#if defined(X86_TSD_OPENBSD)
+        ".balign " U_STRINGIFY(X86_ENTRY_SIZE) "\n"
+#else
         ".balign 32\n"
+#endif
         "x86_entry_start:");
 
+
+#if defined(X86_TSD_OPENBSD)
+#define STUB_ASM_ENTRY(func)        \
+   ".globl " func "\n"              \
+   ".type " func ", @function\n"    \
+   ".balign " U_STRINGIFY(X86_ENTRY_SIZE) "\n" \
+   func ":"
+#else
 #define STUB_ASM_ENTRY(func)        \
    ".globl " func "\n"              \
    ".type " func ", @function\n"    \
    ".balign 32\n"                   \
    func ":"
+#endif
 
+#if defined(X86_TSD_OPENBSD)
+#define STUB_ASM_CODE(slot)         \
+   "push %ebx\n\t"                  \
+   "call 1f\n"                      \
+   "1:\n\t"                         \
+   "popl %ebx\n\t"                  \
+   "addl $_GLOBAL_OFFSET_TABLE_+[.-1b], %ebx\n\t" \
+   "movl " ENTRY_CURRENT_TABLE "@GOT(%ebx), %eax\n\t" \
+   "mov (%eax), %eax\n\t"           \
+   "testl %eax, %eax\n\t"           \
+   "jne 1f\n\t"                     \
+   "call " ENTRY_CURRENT_TABLE_GET "@PLT\n" \
+   "1:\n\t"                         \
+   "pop %ebx\n\t"                   \
+   "jmp *(4 * " slot ")(%eax)"
+#else
 #define STUB_ASM_CODE(slot)         \
    "movl " ENTRY_CURRENT_TABLE ", %eax\n\t" \
    "testl %eax, %eax\n\t"           \
@@ -51,14 +84,20 @@ __asm__(".text\n"
    "1:\n\t"                         \
    "call " ENTRY_CURRENT_TABLE_GET "\n\t" \
    "jmp *(4 * " slot ")(%eax)"
+#endif
 
 #define MAPI_TMP_STUB_ASM_GCC
 #include "mapi_tmp.h"
 
 #ifndef MAPI_MODE_BRIDGE
 
+#if defined(X86_TSD_OPENBSD)
+__asm__(".balign " U_STRINGIFY(X86_ENTRY_SIZE) "\n"
+        "x86_entry_end:");
+#else
 __asm__(".balign 32\n"
         "x86_entry_end:");
+#endif
 
 #include <string.h>
 #include "u_execmem.h"
