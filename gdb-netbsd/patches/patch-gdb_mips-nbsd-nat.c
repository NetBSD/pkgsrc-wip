$NetBSD$

--- gdb/mips-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/mips-nbsd-nat.c
@@ -16,7 +16,9 @@
 
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
-
+#ifndef _KERNTYPES
+#define _KERNTYPES
+#endif
 #include "defs.h"
 #include "inferior.h"
 #include "regcache.h"
@@ -27,10 +29,14 @@
 #include <machine/reg.h>
 
 #include "mips-tdep.h"
+#include "nbsd-nat.h"
 #include "mips-nbsd-tdep.h"
 #include "inf-ptrace.h"
+#include "bsd-kvm.h"
+
+#include "machine/pcb.h"
 
-class mips_nbsd_nat_target final : public inf_ptrace_target
+class mips_nbsd_nat_target final : public nbsd_nat_target
 {
   void fetch_registers (struct regcache *, int) override;
   void store_registers (struct regcache *, int) override;
@@ -49,14 +55,16 @@ getregs_supplies (struct gdbarch *gdbarc
 void
 mips_nbsd_nat_target::fetch_registers (struct regcache *regcache, int regno)
 {
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   struct gdbarch *gdbarch = regcache->arch ();
   if (regno == -1 || getregs_supplies (gdbarch, regno))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
       
       mipsnbsd_supply_reg (regcache, (char *) &regs, regno);
@@ -69,7 +77,7 @@ mips_nbsd_nat_target::fetch_registers (s
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       mipsnbsd_supply_fpreg (regcache, (char *) &fpregs, regno);
@@ -79,19 +87,21 @@ mips_nbsd_nat_target::fetch_registers (s
 void
 mips_nbsd_nat_target::store_registers (struct regcache *regcache, int regno)
 {
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   struct gdbarch *gdbarch = regcache->arch ();
   if (regno == -1 || getregs_supplies (gdbarch, regno))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       mipsnbsd_fill_reg (regcache, (char *) &regs, regno);
 
-      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't write registers"));
 
       if (regno != -1)
@@ -103,18 +113,54 @@ mips_nbsd_nat_target::store_registers (s
     {
       struct fpreg fpregs; 
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       mipsnbsd_fill_fpreg (regcache, (char *) &fpregs, regno);
 
-      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't write floating point status"));
     }
 }
 
+static int
+mipsnbsd_supply_pcb (struct regcache *regcache, struct pcb *pcb)
+{
+  struct label_t sf;
+
+  sf = pcb->pcb_context;
+
+  /* really should test for n{32,64} abi for this register
+     unless this is purely the "n" ABI */
+
+  regcache->raw_supply (MIPS_S0_REGNUM, &sf.val[_L_S0]);
+  regcache->raw_supply (MIPS_S1_REGNUM, &sf.val[_L_S1]);
+  regcache->raw_supply (MIPS_S2_REGNUM, &sf.val[_L_S2]);
+  regcache->raw_supply (MIPS_S3_REGNUM, &sf.val[_L_S3]);
+  regcache->raw_supply (MIPS_S4_REGNUM, &sf.val[_L_S4]);
+  regcache->raw_supply (MIPS_S5_REGNUM, &sf.val[_L_S5]);
+  regcache->raw_supply (MIPS_S6_REGNUM, &sf.val[_L_S6]);
+  regcache->raw_supply (MIPS_S7_REGNUM, &sf.val[_L_S7]);
+
+  regcache->raw_supply (MIPS_S8_REGNUM, &sf.val[_L_S8]);
+
+  regcache->raw_supply (MIPS_T8_REGNUM, &sf.val[_L_T8]);
+
+  regcache->raw_supply (MIPS_GP_REGNUM, &sf.val[_L_GP]);
+
+  regcache->raw_supply (MIPS_SP_REGNUM, &sf.val[_L_SP]);
+  regcache->raw_supply (MIPS_RA_REGNUM, &sf.val[_L_RA]);
+  regcache->raw_supply (MIPS_PS_REGNUM, &sf.val[_L_SR]);
+
+  /* provide the return address of the savectx as the current pc */
+  regcache->raw_supply (MIPS_EMBED_PC_REGNUM, &sf.val[_L_RA]);
+
+  return 0;
+}
+
 void
 _initialize_mipsnbsd_nat (void)
 {
   add_inf_child_target (&the_mips_nbsd_nat_target);
+  bsd_kvm_add_target (mipsnbsd_supply_pcb);
 }
