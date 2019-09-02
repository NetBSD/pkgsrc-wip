$NetBSD$

--- gdb/gdbserver/netbsd-x86_64-low.c.orig	2019-09-02 20:02:23.503455942 +0000
+++ gdb/gdbserver/netbsd-x86_64-low.c
@@ -0,0 +1,383 @@
+/* Copyright (C) 2010-2019 Free Software Foundation, Inc.
+
+   This file is part of GDB.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 3 of the License, or
+   (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
+
+#include "server.h"
+#include "netbsd-low.h"
+#include <limits.h>
+#include <sys/ptrace.h>
+#include "gdbsupport/x86-xstate.h"
+#include "arch/amd64.h"
+#include "x86-tdesc.h"
+#include "tdesc.h"
+
+static int use_xml;
+
+/* The index of various registers inside the regcache.  */
+
+enum netbsd_x86_64_gdb_regnum
+{
+  AMD64_RAX_REGNUM,             /* %rax */
+  AMD64_RBX_REGNUM,             /* %rbx */
+  AMD64_RCX_REGNUM,             /* %rcx */
+  AMD64_RDX_REGNUM,             /* %rdx */
+  AMD64_RSI_REGNUM,             /* %rsi */
+  AMD64_RDI_REGNUM,             /* %rdi */
+  AMD64_RBP_REGNUM,             /* %rbp */
+  AMD64_RSP_REGNUM,             /* %rsp */
+  AMD64_R8_REGNUM,              /* %r8 */
+  AMD64_R9_REGNUM,              /* %r9 */
+  AMD64_R10_REGNUM,             /* %r10 */
+  AMD64_R11_REGNUM,             /* %r11 */
+  AMD64_R12_REGNUM,             /* %r12 */
+  AMD64_R13_REGNUM,             /* %r13 */
+  AMD64_R14_REGNUM,             /* %r14 */
+  AMD64_R15_REGNUM,             /* %r15 */
+  AMD64_RIP_REGNUM,             /* %rip */
+  AMD64_EFLAGS_REGNUM,          /* %eflags */
+  AMD64_CS_REGNUM,              /* %cs */
+  AMD64_SS_REGNUM,              /* %ss */
+  AMD64_DS_REGNUM,              /* %ds */
+  AMD64_ES_REGNUM,              /* %es */
+  AMD64_FS_REGNUM,              /* %fs */
+  AMD64_GS_REGNUM,              /* %gs */
+  AMD64_ST0_REGNUM = 24,        /* %st0 */
+  AMD64_ST1_REGNUM,             /* %st1 */
+  AMD64_FCTRL_REGNUM = AMD64_ST0_REGNUM + 8,
+  AMD64_FSTAT_REGNUM = AMD64_ST0_REGNUM + 9,
+  AMD64_FTAG_REGNUM = AMD64_ST0_REGNUM + 10,
+  AMD64_XMM0_REGNUM = 40,       /* %xmm0 */
+  AMD64_XMM1_REGNUM,            /* %xmm1 */
+  AMD64_MXCSR_REGNUM = AMD64_XMM0_REGNUM + 16,
+  AMD64_YMM0H_REGNUM,           /* %ymm0h */
+  AMD64_YMM15H_REGNUM = AMD64_YMM0H_REGNUM + 15,
+  AMD64_BND0R_REGNUM = AMD64_YMM15H_REGNUM + 1,
+  AMD64_BND3R_REGNUM = AMD64_BND0R_REGNUM + 3,
+  AMD64_BNDCFGU_REGNUM,
+  AMD64_BNDSTATUS_REGNUM,
+  AMD64_XMM16_REGNUM,
+  AMD64_XMM31_REGNUM = AMD64_XMM16_REGNUM + 15,
+  AMD64_YMM16H_REGNUM,
+  AMD64_YMM31H_REGNUM = AMD64_YMM16H_REGNUM + 15,
+  AMD64_K0_REGNUM,
+  AMD64_K7_REGNUM = AMD64_K0_REGNUM + 7,
+  AMD64_ZMM0H_REGNUM,
+  AMD64_ZMM31H_REGNUM = AMD64_ZMM0H_REGNUM + 31,
+  AMD64_PKRU_REGNUM,
+  AMD64_FSBASE_REGNUM,
+  AMD64_GSBASE_REGNUM
+};
+
+/* The fill_function for the general-purpose register set.  */
+
+static void
+netbsd_x86_64_fill_gregset (struct regcache *regcache, char *buf)
+{
+  struct reg *r;
+
+  r = (struct reg *)buf;
+
+#define netbsd_x86_64_collect_gp(regnum, fld) do { \
+  collect_register (regcache, regnum, &r->regs[_REG_##fld]); \
+  printf("collect_register(%p, %d, %p -> %lx)\n", regcache, regnum, &r->regs[_REG_##fld], r->regs[_REG_##fld]); \
+  } while (0)
+
+  netbsd_x86_64_collect_gp (AMD64_RAX_REGNUM, RAX);
+  netbsd_x86_64_collect_gp (AMD64_RBX_REGNUM, RBX);
+  netbsd_x86_64_collect_gp (AMD64_RCX_REGNUM, RCX);
+  netbsd_x86_64_collect_gp (AMD64_RDX_REGNUM, RDX);
+  netbsd_x86_64_collect_gp (AMD64_RSI_REGNUM, RSI);
+  netbsd_x86_64_collect_gp (AMD64_RDI_REGNUM, RDI);
+  netbsd_x86_64_collect_gp (AMD64_RBP_REGNUM, RBP);
+  netbsd_x86_64_collect_gp (AMD64_RSP_REGNUM, RSP);
+  netbsd_x86_64_collect_gp (AMD64_R8_REGNUM, R8);
+  netbsd_x86_64_collect_gp (AMD64_R9_REGNUM, R9);
+  netbsd_x86_64_collect_gp (AMD64_R10_REGNUM, R10);
+  netbsd_x86_64_collect_gp (AMD64_R11_REGNUM, R11);
+  netbsd_x86_64_collect_gp (AMD64_R12_REGNUM, R12);
+  netbsd_x86_64_collect_gp (AMD64_R13_REGNUM, R13);
+  netbsd_x86_64_collect_gp (AMD64_R14_REGNUM, R14);
+  netbsd_x86_64_collect_gp (AMD64_R15_REGNUM, R15);
+  netbsd_x86_64_collect_gp (AMD64_RIP_REGNUM, RIP);
+  netbsd_x86_64_collect_gp (AMD64_EFLAGS_REGNUM, RFLAGS);
+  netbsd_x86_64_collect_gp (AMD64_CS_REGNUM, CS);
+  netbsd_x86_64_collect_gp (AMD64_SS_REGNUM, SS);
+  netbsd_x86_64_collect_gp (AMD64_DS_REGNUM, DS);
+  netbsd_x86_64_collect_gp (AMD64_ES_REGNUM, ES);
+  netbsd_x86_64_collect_gp (AMD64_FS_REGNUM, FS);
+  netbsd_x86_64_collect_gp (AMD64_GS_REGNUM, GS);
+}
+
+/* The store_function for the general-purpose register set.  */
+
+static void
+netbsd_x86_64_store_gregset (struct regcache *regcache, const char *buf)
+{
+  struct reg *r;
+
+  r = (struct reg *)buf;
+
+#define netbsd_x86_64_supply_gp(regnum, fld) do { \
+  supply_register (regcache, regnum, &r->regs[_REG_##fld]); \
+  printf("supply_register(%p, %d, %p -> %lx)\n", regcache, regnum, &r->regs[_REG_##fld], r->regs[_REG_##fld]); \
+  } while(0)
+
+  netbsd_x86_64_supply_gp (AMD64_RAX_REGNUM, RAX);
+  netbsd_x86_64_supply_gp (AMD64_RBX_REGNUM, RBX);
+  netbsd_x86_64_supply_gp (AMD64_RCX_REGNUM, RCX);
+  netbsd_x86_64_supply_gp (AMD64_RDX_REGNUM, RDX);
+  netbsd_x86_64_supply_gp (AMD64_RSI_REGNUM, RSI);
+  netbsd_x86_64_supply_gp (AMD64_RDI_REGNUM, RDI);
+  netbsd_x86_64_supply_gp (AMD64_RBP_REGNUM, RBP);
+  netbsd_x86_64_supply_gp (AMD64_RSP_REGNUM, RSP);
+  netbsd_x86_64_supply_gp (AMD64_R8_REGNUM, R8);
+  netbsd_x86_64_supply_gp (AMD64_R9_REGNUM, R9);
+  netbsd_x86_64_supply_gp (AMD64_R10_REGNUM, R10);
+  netbsd_x86_64_supply_gp (AMD64_R11_REGNUM, R11);
+  netbsd_x86_64_supply_gp (AMD64_R12_REGNUM, R12);
+  netbsd_x86_64_supply_gp (AMD64_R13_REGNUM, R13);
+  netbsd_x86_64_supply_gp (AMD64_R14_REGNUM, R14);
+  netbsd_x86_64_supply_gp (AMD64_R15_REGNUM, R15);
+  netbsd_x86_64_supply_gp (AMD64_RIP_REGNUM, RIP);
+  netbsd_x86_64_supply_gp (AMD64_EFLAGS_REGNUM, RFLAGS);
+  netbsd_x86_64_supply_gp (AMD64_CS_REGNUM, CS);
+  netbsd_x86_64_supply_gp (AMD64_SS_REGNUM, SS);
+  netbsd_x86_64_supply_gp (AMD64_DS_REGNUM, DS);
+  netbsd_x86_64_supply_gp (AMD64_ES_REGNUM, ES);
+  netbsd_x86_64_supply_gp (AMD64_FS_REGNUM, FS);
+  netbsd_x86_64_supply_gp (AMD64_GS_REGNUM, GS);
+}
+
+#if 0
+/* Extract the first 16 bits of register REGNUM in the REGCACHE,
+   and store these 2 bytes at DEST.
+
+   This is useful to collect certain 16bit registers which are known
+   by GDBserver as 32bit registers (such as the Control Register
+   for instance).  */
+
+static void
+collect_16bit_register (struct regcache *regcache, int regnum, char *dest)
+{
+  gdb_byte word[4];
+
+  collect_register (regcache, regnum, word);
+  memcpy (dest, word, 2);
+}
+#endif
+
+#if 0
+/* The fill_function for the floating-point register set.  */
+
+static void
+netbsd_x86_64_fill_fpregset (struct regcache *regcache, char *buf)
+{
+  int i;
+
+  /* Collect %st0 .. %st7.  */
+  for (i = 0; i < 8; i++)
+    collect_register (regcache, I386_ST0_REGNUM + i,
+                      buf + offsetof (usr_fcontext_t, ufc_reg)
+		      + i * sizeof (struct ufp387_real));
+
+  /* Collect the other FPU registers.  */
+  collect_16bit_register (regcache, x86_64_FCTRL_REGNUM,
+                          buf + offsetof (usr_fcontext_t, ufc_control));
+  collect_16bit_register (regcache, I386_FSTAT_REGNUM,
+                          buf + offsetof (usr_fcontext_t, ufc_status));
+  collect_16bit_register (regcache, I386_FTAG_REGNUM,
+                          buf + offsetof (usr_fcontext_t, ufc_tag));
+  collect_register (regcache, I386_FISEG_REGNUM,
+                    buf + offsetof (usr_fcontext_t, ufc_inst_sel));
+  collect_register (regcache, I386_FIOFF_REGNUM,
+                    buf + offsetof (usr_fcontext_t, ufc_inst_off));
+  collect_register (regcache, I386_FOSEG_REGNUM,
+                    buf + offsetof (usr_fcontext_t, ufc_data_sel));
+  collect_register (regcache, I386_FOOFF_REGNUM,
+                    buf + offsetof (usr_fcontext_t, ufc_data_off));
+#if !defined(netbsdOS_178)
+  collect_16bit_register (regcache, I386_FOP_REGNUM,
+                          buf + offsetof (usr_fcontext_t, ufc_opcode));
+
+  /* Collect the XMM registers.  */
+  for (i = 0; i < 8; i++)
+    collect_register (regcache, I386_XMM0_REGNUM + i,
+                      buf + offsetof (usr_fcontext_t, uxmm_reg)
+		      + i * sizeof (struct uxmm_register));
+  collect_register (regcache, I386_MXCSR_REGNUM,
+                    buf + offsetof (usr_fcontext_t, usse_mxcsr));
+#endif
+}
+#endif
+
+#if 0
+/* This is the supply counterpart for collect_16bit_register:
+   It extracts a 2byte value from BUF, and uses that value to
+   set REGNUM's value in the regcache.
+
+   This is useful to supply the value of certain 16bit registers
+   which are known by GDBserver as 32bit registers (such as the Control
+   Register for instance).  */
+
+static void
+supply_16bit_register (struct regcache *regcache, int regnum, const char *buf)
+{
+  gdb_byte word[4];
+
+  memcpy (word, buf, 2);
+  memset (word + 2, 0, 2);
+  supply_register (regcache, regnum, word);
+}
+#endif
+
+#if 0
+/* The store_function for the floating-point register set.  */
+
+static void
+netbsd_x86_64_store_fpregset (struct regcache *regcache, const char *buf)
+{
+  int i;
+
+  /* Store the %st0 .. %st7 registers.  */
+  for (i = 0; i < 8; i++)
+    supply_register (regcache, I386_ST0_REGNUM + i,
+                     buf + offsetof (usr_fcontext_t, ufc_reg)
+		     + i * sizeof (struct ufp387_real));
+
+  /* Store the other FPU registers.  */
+  supply_16bit_register (regcache, I386_FCTRL_REGNUM,
+                         buf + offsetof (usr_fcontext_t, ufc_control));
+  supply_16bit_register (regcache, I386_FSTAT_REGNUM,
+                         buf + offsetof (usr_fcontext_t, ufc_status));
+  supply_16bit_register (regcache, I386_FTAG_REGNUM,
+                         buf + offsetof (usr_fcontext_t, ufc_tag));
+  supply_register (regcache, I386_FISEG_REGNUM,
+                   buf + offsetof (usr_fcontext_t, ufc_inst_sel));
+  supply_register (regcache, I386_FIOFF_REGNUM,
+                   buf + offsetof (usr_fcontext_t, ufc_inst_off));
+  supply_register (regcache, I386_FOSEG_REGNUM,
+                   buf + offsetof (usr_fcontext_t, ufc_data_sel));
+  supply_register (regcache, I386_FOOFF_REGNUM,
+                   buf + offsetof (usr_fcontext_t, ufc_data_off));
+#if !defined(LYNXOS_178)
+  supply_16bit_register (regcache, I386_FOP_REGNUM,
+                         buf + offsetof (usr_fcontext_t, ufc_opcode));
+
+  /* Store the XMM registers.  */
+  for (i = 0; i < 8; i++)
+    supply_register (regcache, I386_XMM0_REGNUM + i,
+                     buf + offsetof (usr_fcontext_t, uxmm_reg)
+		     + i * sizeof (struct uxmm_register));
+  supply_register (regcache, I386_MXCSR_REGNUM,
+                   buf + offsetof (usr_fcontext_t, usse_mxcsr));
+#endif
+}
+#endif
+
+/* Implements the netbsd_target_ops.arch_setup routine.  */
+
+static void
+netbsd_x86_64_arch_setup (void)
+{
+  struct target_desc *tdesc
+    = amd64_create_target_description (X86_XSTATE_SSE_MASK, false, false, false);
+
+  init_target_desc (tdesc, amd64_expedite_regs);
+
+  netbsd_tdesc = tdesc;
+}
+
+/* Update all the target description of all processes; a new GDB
+   connected, and it may or not support xml target descriptions.  */
+
+static void
+x86_64_netbsd_update_xmltarget (void)
+{
+  struct thread_info *saved_thread = current_thread;
+
+  /* Before changing the register cache's internal layout, flush the
+     contents of the current valid caches back to the threads, and
+     release the current regcache objects.  */
+  regcache_release ();
+
+  for_each_process ([] (process_info *proc) {
+    int pid = proc->pid;
+
+    /* Look up any thread of this process.  */
+    current_thread = find_any_thread_of_pid (pid);
+
+    the_low_target.arch_setup ();
+  });
+
+  current_thread = saved_thread;
+}
+
+/* Process qSupported query, "xmlRegisters=". */
+
+static void
+netbsd_x86_64_process_qsupported (char **features, int count)
+{
+  int i;
+
+  /* Return if gdb doesn't support XML.  If gdb sends "xmlRegisters="
+     with "i386" in qSupported query, it supports x86 XML target
+     descriptions.  */
+  use_xml = 0;
+  for (i = 0; i < count; i++)
+    {
+      const char *feature = features[i];
+
+      if (startswith (feature, "xmlRegisters="))
+        {
+          char *copy = xstrdup (feature + 13);
+          char *p;
+
+          for (p = strtok (copy, ","); p != NULL; p = strtok (NULL, ","))
+            {
+              if (strcmp (p, "i386") == 0)
+                {
+                  use_xml = 1;
+                  break;
+                }
+            }
+
+          free (copy);
+        }
+    }
+  x86_64_netbsd_update_xmltarget ();
+}
+
+/* Description of all the x86-netbsd register sets.  */
+
+struct netbsd_regset_info netbsd_target_regsets[] = {
+  /* General Purpose Registers.  */
+  {PT_GETREGS, PT_SETREGS, sizeof(struct reg),
+   netbsd_x86_64_fill_gregset, netbsd_x86_64_store_gregset},
+  /* Floating Point Registers.  */
+#if 0
+  { PTRACE_GETFPREGS, PTRACE_SETFPREGS, sizeof(usr_fcontext_t),
+    netbsd_x86_64_fill_fpregset, netbsd_x86_64_store_fpregset },
+#endif
+  /* End of list marker.  */
+  {0, 0, -1, NULL, NULL }
+};
+
+/* The netbsd_target_ops vector for x86-netbsd.  */
+
+struct netbsd_target_ops the_low_target = {
+  netbsd_x86_64_arch_setup,
+  netbsd_x86_64_process_qsupported,
+};
