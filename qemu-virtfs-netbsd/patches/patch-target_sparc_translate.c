$NetBSD: patch-target_sparc_translate.c,v 1.2 2023/05/06 19:22:37 ryoon Exp $

Patch from upstream (not integrated there yet) to work around %pc/%npc
being set to invalid values via ptrace, triggered by the NetBSD ptrace
ATF tests. Real hardware seems to hardcode the lower bits to zero too.

--- target/sparc/translate.c.orig	2023-03-28 20:31:55.000000000 +0000
+++ target/sparc/translate.c
@@ -4324,6 +4324,7 @@ static void disas_sparc_insn(DisasContex
 
                                     r_tsptr = tcg_temp_new_ptr();
                                     gen_load_trap_state_at_tl(r_tsptr, cpu_env);
+                                    tcg_gen_andi_tl(cpu_tmp0, cpu_tmp0, ~3);
                                     tcg_gen_st_tl(cpu_tmp0, r_tsptr,
                                                   offsetof(trap_state, tpc));
                                 }
@@ -4334,6 +4335,7 @@ static void disas_sparc_insn(DisasContex
 
                                     r_tsptr = tcg_temp_new_ptr();
                                     gen_load_trap_state_at_tl(r_tsptr, cpu_env);
+                                    tcg_gen_andi_tl(cpu_tmp0, cpu_tmp0, ~3);
                                     tcg_gen_st_tl(cpu_tmp0, r_tsptr,
                                                   offsetof(trap_state, tnpc));
                                 }
