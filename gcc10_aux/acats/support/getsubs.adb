
PACKAGE BODY GETSUBS IS

-----------------------------------------------------------------------
--                                                                   --
--    PROCEDURE CALC_MAX_VALS CALCULATES THE VALUE FOR THE MACRO     --
--    READ FROM MACRO.DFS IF ITS LENGTH IS EQUAL OR NEARLY EQUAL TO  --
--    MAX_IN_LEN.  IT THEN RETURNS A FLAG SET TO TRUE IF A VALUE WAS --
--    CALCULATED, FALSE IF ONE WAS NOT.                              --
--                                                                   --
-----------------------------------------------------------------------

     PROCEDURE CALC_MAX_VALS(INDEX, LENGTH, MAX_IN_LEN : IN INTEGER;
                             CALCULATED : OUT BOOLEAN) IS

     BEGIN

          IF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) = "BIG_ID1"
               THEN SYMBOL_TABLE (INDEX).MACRO_VALUE (1..MAX_IN_LEN) :=
               (1..(MAX_IN_LEN-1) => 'A') & "1";
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BIG_ID2" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..MAX_IN_LEN) := (1..(MAX_IN_LEN-1) => 'A') & "2";
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BIG_ID3" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..MAX_IN_LEN) := (1..(MAX_IN_LEN + 1)/2 => 'A') & "3" &
               ((MAX_IN_LEN + 1)/2 + 2..MAX_IN_LEN => 'A');
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BIG_ID4" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..MAX_IN_LEN) := (1..(MAX_IN_LEN + 1)/2 => 'A') & "4" &
               ((MAX_IN_LEN + 1)/2 + 2..MAX_IN_LEN => 'A');
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BIG_STRING1" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..(MAX_IN_LEN + 1)/2 + 2) :=
                          '"' & (1..(MAX_IN_LEN + 1)/2 => 'A') & '"';
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BIG_STRING2" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..MAX_IN_LEN - (MAX_IN_LEN + 1)/2 + 2) :=
               '"' & (2..MAX_IN_LEN - (MAX_IN_LEN + 1)/2 => 'A') &
               '1' & '"';
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "MAX_STRING_LITERAL" THEN SYMBOL_TABLE (INDEX).
               MACRO_VALUE (1..MAX_IN_LEN) := '"' &
               (1..MAX_IN_LEN-2 => 'A') & '"';
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BIG_INT_LIT" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..MAX_IN_LEN)  := (1..MAX_IN_LEN-3 => '0') & "298";
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BIG_REAL_LIT" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..MAX_IN_LEN) := (1..MAX_IN_LEN-5 => '0') & "690.0";
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "MAX_LEN_INT_BASED_LITERAL" THEN
               SYMBOL_TABLE (INDEX).
               MACRO_VALUE (1..MAX_IN_LEN) := "2:" &
               (1..MAX_IN_LEN - 5 => '0') & "11:";
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "MAX_LEN_REAL_BASED_LITERAL" THEN SYMBOL_TABLE (INDEX).
               MACRO_VALUE (1..MAX_IN_LEN) := "16:" &
               (1..MAX_IN_LEN - 7 => '0') & "F.E:";
               CALCULATED := TRUE;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BLANKS" THEN SYMBOL_TABLE (INDEX).MACRO_VALUE
               (1..MAX_IN_LEN-20) := (1..MAX_IN_LEN-20 => ' ');
               CALCULATED := TRUE;
          ELSE
               CALCULATED := FALSE;
          END IF;
          IF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
               "BLANKS" THEN SYMBOL_TABLE (INDEX).VALUE_LENGTH :=
               MAX_IN_LEN - 20;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
                "BIG_STRING1" THEN
               SYMBOL_TABLE (INDEX).VALUE_LENGTH :=
                           (MAX_IN_LEN + 1)/2 + 2;
          ELSIF SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) =
                "BIG_STRING2" THEN
               SYMBOL_TABLE (INDEX).VALUE_LENGTH :=
                      MAX_IN_LEN - (MAX_IN_LEN + 1)/2 + 2;
          ELSE SYMBOL_TABLE (INDEX).VALUE_LENGTH := MAX_IN_LEN;
          END IF;
     END CALC_MAX_VALS;

-----------------------------------------------------------------------
--                                                                   --
--    PROCEDURE FILL_TABLE READS THE MACRO NAMES AND MACRO VALUES IN --
--    FROM MACRO.DFS AND STORES THEM IN THE SYMBOL TABLE.  PROCEDURE --
--    CALC_MAX_VALS IS CALLED TO DETERMINE IF THE MACRO VALUE SHOULD --
--    BE CALCULATED OR READ FROM MACRO.DFS.                          --
--                                                                   --
-----------------------------------------------------------------------

     PROCEDURE FILL_TABLE IS

          INFILE1 : FILE_TYPE;
          MACRO_FILE : CONSTANT STRING := "MACRO.DFS";
          A_LINE : VAL_STRING;
          I, INDEX, LENGTH, HOLD, A_LENGTH, NAME : INTEGER;
          MAX_IN_LEN : INTEGER := 1;
          CALCULATED : BOOLEAN;

     BEGIN
          INDEX := 1;
          BEGIN
               OPEN (INFILE1, IN_FILE, MACRO_FILE);
          EXCEPTION
               WHEN NAME_ERROR =>
                    PUT_LINE ("** ERROR: MACRO FILE " & MACRO_FILE &
                              " NOT FOUND.");
                    RAISE MAC_FILE;
          END;
          WHILE NOT END_OF_FILE (INFILE1) LOOP
               GET_LINE (INFILE1, A_LINE, A_LENGTH);
               IF A_LENGTH > 0 AND A_LINE (1..2) /= "--" AND
                  A_LINE (1) /= ' ' AND A_LINE (1) /= ASCII.HT THEN
                    I := 1;
                    WHILE I <= A_LENGTH AND THEN
                           ((A_LINE (I) IN 'A'..'Z') OR
                            (A_LINE (I) IN '0'..'9') OR
                            A_LINE (I) = '_') LOOP
                         I := I + 1;
                    END LOOP;
                    I := I - 1;
                    LENGTH := I;
                    BEGIN
                         SYMBOL_TABLE (INDEX).MACRO_NAME (1..LENGTH) :=
                              A_LINE (1..I);
                    EXCEPTION
                         WHEN CONSTRAINT_ERROR =>
                              PUT_LINE ("** ERROR: LINE LENGTH IS " &
                                        "GREATER THAN MAX_VAL_LENGTH.");
                              RAISE LINE_LEN;
                    END;
                    SYMBOL_TABLE (INDEX).NAME_LENGTH := I;
                    CALC_MAX_VALS (INDEX, LENGTH, MAX_IN_LEN,
                                   CALCULATED);
                    IF NOT CALCULATED THEN
                         I := I + 1;
                         WHILE A_LINE (I) = ' ' OR A_LINE (I) =
                           ASCII.HT LOOP
                              I := I + 1;
                              IF SYMBOL_TABLE (INDEX).MACRO_NAME
                                   (1..LENGTH) = "BLANKS" THEN
                                   EXIT;
                              END IF;
                         END LOOP;
                         HOLD := I;

-- MACRO VALUE BEGINS AT POSITION HOLD.
-- NOW FIND WHERE IT ENDS BY STARTING AT THE END OF THE INPUT
-- LINE AND SEARCHING BACKWARD FOR A NON-BLANK.

                         I := A_LENGTH;
                         WHILE I > HOLD AND THEN (A_LINE (I) = ' '
                            OR A_LINE(I) = ASCII.HT) LOOP
                              I := I - 1;
                         END LOOP;
                         LENGTH := I - HOLD + 1;
                         SYMBOL_TABLE (INDEX).MACRO_VALUE (1..LENGTH)
                              := A_LINE (HOLD..I);
                         SYMBOL_TABLE (INDEX).VALUE_LENGTH := LENGTH;
                         NAME := SYMBOL_TABLE (INDEX).NAME_LENGTH;
                         IF SYMBOL_TABLE (INDEX).MACRO_NAME (1..NAME) =
                              "MAX_IN_LEN" THEN MAX_IN_LEN :=
                              INTEGER'VALUE (SYMBOL_TABLE (INDEX).
                              MACRO_VALUE (1..LENGTH));
                         END IF;
                    END IF;
                    INDEX := INDEX + 1;
               END IF;
          END LOOP;
          NUM_MACROS := INDEX - 1;
          CLOSE (INFILE1);
     END FILL_TABLE;

BEGIN
     NULL;
END GETSUBS;
