$NetBSD$

Fix build with clang.

--- src/emu/hiscore.c.orig	2017-03-16 20:39:20.000000000 +0000
+++ src/emu/hiscore.c
@@ -36,7 +36,7 @@ static void copy_to_memory (running_mach
 	int i;
 	address_space *targetspace;
 
-	if (strstr(machine.system().source_file,"cinemat.c") > 0)
+	if (strstr(machine.system().source_file,"cinemat.c") != NULL)
 	{
 		targetspace = &machine.cpu[cpu]->memory().space(AS_DATA);
 	}
@@ -56,7 +56,7 @@ static void copy_from_memory (running_ma
 	int i;
 	address_space *targetspace;
 
-	if (strstr(machine.system().source_file,"cinemat.c") > 0)
+	if (strstr(machine.system().source_file,"cinemat.c") != NULL)
 	{
 		targetspace = &machine.cpu[cpu]->memory().space(AS_DATA);
 	}
@@ -154,7 +154,7 @@ static int safe_to_load (running_machine
 	memory_range *mem_range = state.mem_range;
 	address_space *srcspace;
 
-	if (strstr(machine.system().source_file,"cinemat.c") > 0)
+	if (strstr(machine.system().source_file,"cinemat.c") != NULL)
 	{
 		srcspace = &machine.cpu[mem_range->cpu]->memory().space(AS_DATA);
 	}
@@ -309,7 +309,7 @@ void hiscore_init (running_machine &mach
 
 	while (mem_range)
 	{
-		if (strstr(machine.system().source_file,"cinemat.c") > 0)
+		if (strstr(machine.system().source_file,"cinemat.c") != NULL)
 		{
 			initspace = &machine.cpu[mem_range->cpu]->memory().space(AS_DATA);
 			initspace->write_byte(mem_range->addr, ~mem_range->start_value);
