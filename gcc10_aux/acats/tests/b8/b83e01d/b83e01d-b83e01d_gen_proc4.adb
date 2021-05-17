--**********

SEPARATE (B83E01D)
PROCEDURE B83E01D_GEN_PROC4 IS

     PARAM1 : INTEGER;                                   -- ERROR:

     PARAM1 : CONSTANT BOOLEAN := TRUE;                  -- ERROR:

     PARAM1 : CONSTANT := 5;                             -- ERROR:

     TYPE PARAM1 IS ARRAY(1 ..2) OF BOOLEAN;             -- ERROR:

     SUBTYPE PARAM1 IS INTEGER;                          -- ERROR:

     PACKAGE PARAM1 IS                                   -- ERROR:
     END;

BEGIN
    PARAM1:                                              -- ERROR:
     DECLARE
     BEGIN
          NULL;
     END PARAM1;
END B83E01D_GEN_PROC4;
