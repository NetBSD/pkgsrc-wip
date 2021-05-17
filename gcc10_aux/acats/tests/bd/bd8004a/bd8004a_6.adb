
WITH MACHINE_CODE; USE MACHINE_CODE;
PROCEDURE BD8004A_6 IS
     TASK T IS                                           -- ERROR:
     END T;

     TASK BODY T IS
     BEGIN
          NULL;
     END T;
BEGIN
     Asm_Insn'(Asm ("nop"));
END BD8004A_6;
