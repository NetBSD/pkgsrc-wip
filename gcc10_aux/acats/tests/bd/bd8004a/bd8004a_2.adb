
WITH MACHINE_CODE; USE MACHINE_CODE;
PROCEDURE BD8004A_2 IS
     TYPE REC IS                                         -- ERROR:
     RECORD
          NULL;
     END RECORD;
BEGIN
     Asm_Insn'(Asm ("nop"));
END BD8004A_2;
