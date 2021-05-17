--**********

SEPARATE (B83E01D)
FUNCTION B83E01D_GEN_PROC6 RETURN BOOLEAN IS
     TASK PARAM1 IS                                      -- ERROR:
     END;

     TASK BODY PARAM1 IS                  -- OPTIONAL ERR MESSAGE.
     BEGIN
          NULL;
     END;

BEGIN
<<PARAM1>>     RETURN TRUE;                              -- ERROR:
END B83E01D_GEN_PROC6;
