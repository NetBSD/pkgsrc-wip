$NetBSD: patch-Source_JavaScriptCore_offlineasm_arm64.rb,v 1.2 2019/03/13 20:49:40 leot Exp $

Add support for FreeBSD and NetBSD.

From FreeBSD ports.

--- Source/JavaScriptCore/offlineasm/arm64.rb.orig	2022-08-31 07:59:51.730492400 +0000
+++ Source/JavaScriptCore/offlineasm/arm64.rb
@@ -1225,8 +1225,8 @@ class Instruction
             $asm.puts "Ljsc_llint_loh_ldr_#{uid}:"
             $asm.puts "ldr #{operands[1].arm64Operand(:quad)}, [#{operands[1].arm64Operand(:quad)}, #{operands[0].asmLabel}@GOTPAGEOFF]"
 
-            # On Linux, use ELF GOT relocation specifiers.
-            $asm.putStr("#elif OS(LINUX)")
+            # On Linux, FreeBSD and NetBSD, use ELF GOT relocation specifiers.
+            $asm.putStr("#elif OS(LINUX) || OS(FREEBSD) || OS(NETBSD)")
             $asm.puts "adrp #{operands[1].arm64Operand(:quad)}, :got:#{operands[0].asmLabel}"
             $asm.puts "ldr #{operands[1].arm64Operand(:quad)}, [#{operands[1].arm64Operand(:quad)}, :got_lo12:#{operands[0].asmLabel}]"
 
