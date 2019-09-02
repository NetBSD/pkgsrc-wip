$NetBSD$

--- gdb/ppc-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/ppc-nbsd-nat.c
@@ -19,6 +19,7 @@
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
+#define _KMEMUSER
 #include "defs.h"
 
 #include <sys/types.h>
@@ -31,12 +32,15 @@
 #include "inferior.h"
 #include "regcache.h"
 
+#include "common/gdb_assert.h"
+
+#include "nbsd-nat.h"
 #include "ppc-tdep.h"
 #include "ppc-nbsd-tdep.h"
 #include "bsd-kvm.h"
 #include "inf-ptrace.h"
 
-struct ppc_nbsd_nat_target final : public inf_ptrace_target
+struct ppc_nbsd_nat_target final : public nbsd_nat_target
 {
   void fetch_registers (struct regcache *, int) override;
   void store_registers (struct regcache *, int) override;
@@ -88,13 +92,15 @@ void
 ppc_nbsd_nat_target::fetch_registers (struct regcache *regcache, int regnum)
 {
   struct gdbarch *gdbarch = regcache->arch ();
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   if (regnum == -1 || getregs_supplies (gdbarch, regnum))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
         perror_with_name (_("Couldn't get registers"));
 
       ppc_supply_gregset (&ppcnbsd_gregset, regcache,
@@ -105,7 +111,7 @@ ppc_nbsd_nat_target::fetch_registers (st
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get FP registers"));
 
       ppc_supply_fpregset (&ppcnbsd_fpregset, regcache,
@@ -117,19 +123,21 @@ void
 ppc_nbsd_nat_target::store_registers (struct regcache *regcache, int regnum)
 {
   struct gdbarch *gdbarch = regcache->arch ();
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   if (regnum == -1 || getregs_supplies (gdbarch, regnum))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       ppc_collect_gregset (&ppcnbsd_gregset, regcache,
 			   regnum, &regs, sizeof regs);
 
-      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't write registers"));
     }
 
@@ -137,13 +145,13 @@ ppc_nbsd_nat_target::store_registers (st
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get FP registers"));
 
       ppc_collect_fpregset (&ppcnbsd_fpregset, regcache,
 			    regnum, &fpregs, sizeof fpregs);
 
-      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't set FP registers"));
     }
 }
@@ -161,20 +169,20 @@ ppcnbsd_supply_pcb (struct regcache *reg
   if (pcb->pcb_sp == 0)
     return 0;
 
-  read_memory (pcb->pcb_sp, (gdb_byte *)&sf, sizeof sf);
-  regcache->raw_supply (tdep->ppc_cr_regnum, &sf.cr);
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 2, &sf.fixreg2);
+  read_memory (pcb->pcb_sp, (gdb_byte *)&sf, sizeof(sf));
+  regcache->raw_supply (tdep->ppc_cr_regnum, &sf.sf_cr);
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 2, &sf.sf_fixreg2);
   for (i = 0 ; i < 19 ; i++)
-    regcache->raw_supply (tdep->ppc_gp0_regnum + 13 + i, &sf.fixreg[i]);
+    regcache->raw_supply (tdep->ppc_gp0_regnum + 13 + i, &sf.sf_fixreg[i]);
 
-  read_memory(sf.sp, (gdb_byte *)&cf, sizeof(cf));
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 30, &cf.r30);
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 31, &cf.r31);
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 1, &cf.sp);
-
-  read_memory(cf.sp, (gdb_byte *)&cf, sizeof(cf));
-  regcache->raw_supply (tdep->ppc_lr_regnum, &cf.lr);
-  regcache->raw_supply (gdbarch_pc_regnum (gdbarch), &cf.lr);
+  read_memory(sf.sf_sp, (gdb_byte *)&cf, sizeof(cf));
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 30, &cf.cf_r30);
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 31, &cf.cf_r31);
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 1, &cf.cf_sp);
+
+  read_memory(cf.cf_sp, (gdb_byte *)&cf, sizeof(cf));
+  regcache->raw_supply (tdep->ppc_lr_regnum, &cf.cf_lr);
+  regcache->raw_supply (gdbarch_pc_regnum (gdbarch), &cf.cf_lr);
 
   return 1;
 }
