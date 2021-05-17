--**********

SEPARATE (B83E01D)
FUNCTION B83E01D_PROC3(PARAM1,PARAM2, PARAM3, PARAM4, PARAM5 :
                                              INTEGER) RETURN BOOLEAN IS
     GENERIC
     PROCEDURE PARAM1;                                   -- ERROR:

     GENERIC
     FUNCTION PARAM2 RETURN BOOLEAN;                     -- ERROR:

     GENERIC
     PACKAGE PARAM3 IS                                   -- ERROR:
     END;

     GENERIC
     PROCEDURE PARAM;

     TASK PARAM4 IS                                      -- ERROR:
     END;

     PROCEDURE PARAM IS
     BEGIN
          NULL;
     END;

     PROCEDURE PARAM1 IS                        -- OPTIONAL ERROR:
     BEGIN
          NULL;
     END;

     FUNCTION PARAM2 RETURN BOOLEAN IS          -- OPTIONAL ERROR:
     BEGIN
          RETURN TRUE;
     END;

     PROCEDURE PARAM3 IS NEW PARAM;                      -- ERROR:

     TASK BODY PARAM4 IS                  -- OPTIONAL ERR MESSAGE.
     BEGIN
          NULL;
     END;

BEGIN
<<PARAM5>>     RETURN TRUE;                              -- ERROR:
END B83E01D_PROC3;
