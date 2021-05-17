
WITH MACHINE_CODE; USE MACHINE_CODE;
PROCEDURE BD8004A_5 IS
     PACKAGE P IS                                        -- ERROR:
     END P;
BEGIN
     Asm_Insn'(Asm ("nop"));
END BD8004A_5;
