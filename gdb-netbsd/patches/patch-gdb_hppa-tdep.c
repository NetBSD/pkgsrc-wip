$NetBSD$

--- gdb/hppa-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/hppa-tdep.c
@@ -624,7 +624,7 @@ hppa32_register_name (struct gdbarch *gd
     "sr5",    "sr6",     "sr7",    "cr0",
     "cr8",    "cr9",     "ccr",    "cr12",
     "cr13",   "cr24",    "cr25",   "cr26",
-    "mpsfu_high","mpsfu_low","mpsfu_ovflo","pad",
+    "cr27",   "cr28",    "cr29",   "cr30",
     "fpsr",    "fpe1",   "fpe2",   "fpe3",
     "fpe4",   "fpe5",    "fpe6",   "fpe7",
     "fr4",     "fr4R",   "fr5",    "fr5R",
