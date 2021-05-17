
WITH MACHINE_CODE; USE MACHINE_CODE;
PROCEDURE BD8004A_9 IS
     PROCEDURE M_C IS                                    -- ERROR:
     BEGIN
         Asm_Insn'(Asm ("nop"));
     END M_C;
BEGIN
     Asm_Insn'(Asm ("nop"));
END BD8004A_9;
