
 WITH MACHINE_CODE; USE MACHINE_CODE;
PROCEDURE BD8004A_4 IS
     A : INTEGER;                                        -- ERROR:
BEGIN
     Asm_Insn'(Asm ("nop"));
END BD8004A_4;
