$NetBSD$

--- gdb/vax-bsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/vax-bsd-nat.c
@@ -17,6 +17,9 @@
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
+#ifndef _KERNTYPES
+#define _KERNTYPES
+#endif
 #include "defs.h"
 #include "inferior.h"
 #include "regcache.h"
@@ -29,7 +32,13 @@
 #include "vax-tdep.h"
 #include "inf-ptrace.h"
 
+#ifdef __NetBSD__
+#include "nbsd-nat.h"
+struct vax_bsd_nat_target final : public nbsd_nat_target
+#else
 struct vax_bsd_nat_target final : public inf_ptrace_target
+#endif
+
 {
   void fetch_registers (struct regcache *, int) override;
   void store_registers (struct regcache *, int) override;
@@ -42,7 +51,7 @@ static vax_bsd_nat_target the_vax_bsd_na
 static void
 vaxbsd_supply_gregset (struct regcache *regcache, const void *gregs)
 {
-  const gdb_byte *regs = gregs;
+  const gdb_byte *regs = (const gdb_byte *)gregs;
   int regnum;
 
   for (regnum = 0; regnum < VAX_NUM_REGS; regnum++)
@@ -56,7 +65,7 @@ static void
 vaxbsd_collect_gregset (const struct regcache *regcache,
 			void *gregs, int regnum)
 {
-  gdb_byte *regs = gregs;
+  gdb_byte *regs = (gdb_byte *)gregs;
   int i;
 
   for (i = 0; i <= VAX_NUM_REGS; i++)
@@ -74,9 +83,11 @@ void
 vax_bsd_nat_target::fetch_registers (struct regcache *regcache, int regnum)
 {
   struct reg regs;
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
-  if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+  if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  lwp) == -1)
     perror_with_name (_("Couldn't get registers"));
 
   vaxbsd_supply_gregset (regcache, &regs);
@@ -89,14 +100,16 @@ void
 vax_bsd_nat_target::store_registers (struct regcache *regcache, int regnum)
 {
   struct reg regs;
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
-  if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+  if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
     perror_with_name (_("Couldn't get registers"));
 
   vaxbsd_collect_gregset (regcache, &regs, regnum);
 
-  if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+  if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  lwp) == -1)
     perror_with_name (_("Couldn't write registers"));
 }
 
