--**********

SEPARATE (B83E01D)
PROCEDURE B83E01D_GEN_PROC5 IS

     PARAM1 : EXCEPTION;                                 -- ERROR:

     PROCEDURE PARAM1 IS                                 -- ERROR:
     BEGIN
          NULL;
     END;

     FUNCTION PARAM1 RETURN BOOLEAN IS                   -- ERROR:
     BEGIN
          RETURN TRUE;
     END;

BEGIN
  PARAM1:                                                -- ERROR:
     FOR I IN 1 .. 2 LOOP
          NULL;
     END LOOP PARAM1;

END B83E01D_GEN_PROC5;
