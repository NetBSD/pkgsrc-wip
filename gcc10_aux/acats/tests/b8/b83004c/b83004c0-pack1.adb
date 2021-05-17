
SEPARATE (B83004C0)
PACKAGE BODY PACK1 IS

     VAR1 : CONSTANT STRING := "HELLO";                        -- ERROR:
     CON1 : INTEGER := 1;                                      -- ERROR:
     INT : EXCEPTION;                                          -- ERROR:
     TYPE EXC1 IS NEW INTEGER;                                 -- ERROR:
     SUBTYPE P IS INTEGER RANGE 1..10;                         -- ERROR:
     PACKAGE INT_SUBTYPE IS                                    -- ERROR:
          X : INTEGER := 0;
     END INT_SUBTYPE;
     TASK FUN;                                                 -- ERROR:
     GENERIC
          TYPE NEW_TYPE IS PRIVATE;
     FUNCTION T RETURN NEW_TYPE;                               -- ERROR:
     PROCEDURE PROC1 (A : IN INTEGER; B : OUT BOOLEAN);        -- ERROR:

     TASK BODY T IS
     BEGIN
          NULL;
     END T;

     FUNCTION FUN RETURN INTEGER IS
     BEGIN
          RETURN 1;
     END FUN;

     PROCEDURE PROC1 (X : IN INTEGER; Y : OUT BOOLEAN) IS
     BEGIN
          IF X = 1 THEN
               Y := TRUE;
          ELSE
               Y := FALSE;
          END IF;
     END PROC1;

END PACK1;
