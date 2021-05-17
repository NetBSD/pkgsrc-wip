
PACKAGE BODY PARSEMAC IS

-----------------------------------------------------------------------
--    PROCEDURE LOOK_FOR_MACRO LOOKS FOR A DOLLAR SIGN WHICH SIGNALS --
--    THE START OF A MACRO IN THE *.TST FILES.  IT THEN COUNTS       --
--    CHARACTERS UNTIL A <LETTER>, <NUMBER>, OR <_> IS NOT FOUND.    --
--    RETURN PARAMETERS SEND THE BEGINNING POINTER AND LENGTH OF THE --
--    MACRO BACK TO THE MAIN PROGRAM.  ALSO RETURNED IS THE MACRO    --
--    STRING.                                                        --
-----------------------------------------------------------------------

     PROCEDURE LOOK_FOR_MACRO (A_LINE : IN STRING;
                               A_LENGTH : IN INTEGER;
                               PTR : IN OUT INTEGER;
                               MACRO : OUT STRING;
                               MACRO_LEN : IN OUT INTEGER) IS

     II, J : INTEGER := INTEGER'LAST;

     BEGIN
          FOR I IN PTR..A_LENGTH LOOP
               IF A_LINE (I) = '$' THEN
                    II := I+1;
                    EXIT;
               END IF;
               II := I;
          END LOOP;
          IF II < A_LENGTH THEN    -- DOLLAR SIGN IS FOUND.
               J := II;
               WHILE J <= A_LENGTH AND THEN ((A_LINE(J) IN 'A'..'Z') OR
                      (A_LINE(J) IN '0'..'9') OR
                       A_LINE(J) = '_') LOOP
                       J := J+1;
               END LOOP;
               J := J-1;
               MACRO_LEN := (J-II+1);
               MACRO (1..MACRO_LEN) := A_LINE (II .. J);
                             -- DON'T INCLUDE THE DOLLAR SIGN
               PTR := J+1;
          ELSE
               MACRO_LEN := 0;
          END IF;
     RETURN;
     END LOOK_FOR_MACRO;

------------------------------------------------------------------------
--    PROCEDURE WHICH_MACRO COMPARES THE INPUT MACRO STRING TO A      --
--    VALUE READ FROM MACRO.DFS AND STORED IN THE SYMBOL TABLE AND    --
--    RETURNS THE MACRO SUBSTITUTION STRING BACK TO THE MAIN PROGRAM. --
------------------------------------------------------------------------

     PROCEDURE WHICH_MACRO (MACRO : IN STRING;
                            MACRO_LEN : IN INTEGER;
                            TEMP_MACRO : OUT STRING;
                            TEMP_MACRO_LEN : IN OUT INTEGER) IS

     BEGIN
          FOR INDEX IN 1 .. NUM_MACROS LOOP
               IF MACRO (1..MACRO_LEN) =
                  SYMBOL_TABLE (INDEX).MACRO_NAME
                      (1..SYMBOL_TABLE (INDEX).NAME_LENGTH) THEN
                    TEMP_MACRO_LEN :=
                      SYMBOL_TABLE (INDEX).VALUE_LENGTH;
                    TEMP_MACRO (1..TEMP_MACRO_LEN) :=
                      SYMBOL_TABLE (INDEX).MACRO_VALUE
                        (1..TEMP_MACRO_LEN);
                    EXIT;
               END IF;
               IF INDEX = NUM_MACROS THEN
                    PUT_LINE ("** ERROR: MACRO " & MACRO (1..MACRO_LEN)
                              & " NOT FOUND.  UPDATE PROGRAM.");
                    TEMP_MACRO_LEN := MACRO_LEN;
                    TEMP_MACRO (1..TEMP_MACRO_LEN) :=
                       MACRO (1..MACRO_LEN);
               END IF;
          END LOOP;

     END WHICH_MACRO;

BEGIN
     NULL;
END PARSEMAC;
