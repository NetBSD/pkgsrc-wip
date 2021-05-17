
WITH MACHINE_CODE; USE MACHINE_CODE;
PROCEDURE BD8004A_8 IS
     PROCEDURE PROC IS                                   -- ERROR:
     BEGIN
          NULL;
     END PROC;
BEGIN
     Asm_Insn'(Asm ("nop"));
END BD8004A_8;
