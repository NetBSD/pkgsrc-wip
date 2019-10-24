$NetBSD$

Reason unknown (patch ported from version 6.03.2).

--- Engine/entry1.c.orig	2019-07-12 21:54:19.000000000 +0000
+++ Engine/entry1.c
@@ -1086,7 +1086,7 @@ OENTRY opcodlst_1[] = {
     (SUBR) chnset_opcode_init_S, (SUBR) chnset_opcode_perf_S, NULL },
   { "chnsetks",    S(CHNGET),_CW,           2,      "",             "SS",
     NULL, (SUBR) chnset_opcode_perf_S, NULL },
-  { "chnmix",      S(CHNGET),           _CB, 3,      "",             "aS",
+  { "chnmix",      S(CHNGET),           CSOUND_CB, 5,      "",             "aS",
     (SUBR) chnmix_opcode_init, (SUBR) notinit_opcode_stub  },
   { "chnclear",    S(CHNCLEAR),        _CW, 3,      "",             "W",
     (SUBR) chnclear_opcode_init, (SUBR) notinit_opcode_stub },
