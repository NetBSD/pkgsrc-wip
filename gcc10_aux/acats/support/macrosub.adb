
WITH TEXT_IO, GETSUBS, PARSEMAC, DEFS;
USE TEXT_IO, GETSUBS, PARSEMAC, DEFS;

PROCEDURE MACROSUB IS

------------------------------------------------------------------------
--                                                                    --
--    MACROSUB IS THE MAIN PROGRAM THAT CALLS PROCEDURES IN TWO       --
--    PACKAGES, GETSUBS AND PARSEMAC.  THIS PROGRAM IS USED TO MAKE   --
--    THE MACRO SUBSTITUTIONS FOR TST TESTS IN THE ACVC TEST SUITE.   --
--                                                                    --
------------------------------------------------------------------------

     INFILE1, INFILE2, OUTFILE1     : FILE_TYPE;
     FNAME, MACRO                   : VAL_STRING;
     LENGTH, A_LENGTH, PTR,
     TEMP_MACRO_LENGTH, MACRO_LEN, FILE_COUNT : INTEGER := 0;
     A_LINE, TEMP_MACRO, TEMP_LINE, NEW_LINE : VAL_STRING;
     END_OF_LINE_SEARCH, FLAG       : BOOLEAN := FALSE;
     TESTS_FILE                     : CONSTANT STRING := "TSTTESTS.DAT";
     TSTTESTS,FILE_CRE              : EXCEPTION;

BEGIN
     PUT_LINE ("BEGINNING MACRO SUBSTITUTIONS.");
     FILL_TABLE;
     BEGIN
          OPEN (INFILE2, IN_FILE, TESTS_FILE);
     EXCEPTION
          WHEN NAME_ERROR =>
               PUT_LINE ("** ERROR: ERROR DURING OPENING OF " &
                         "TSTTESTS.DAT");
               RAISE TSTTESTS;
     END;
     WHILE NOT END_OF_FILE (INFILE2) LOOP
          GET_LINE (INFILE2, FNAME, LENGTH);
          FILE_COUNT := FILE_COUNT + 1;
          BEGIN
               OPEN (INFILE1, IN_FILE, FNAME(1..LENGTH));
          EXCEPTION
               WHEN NAME_ERROR =>
                    PUT_LINE ("** ERROR: ERROR DURING OPENING OF " &
                              FNAME(1..LENGTH) & ".");
                    FLAG := TRUE;
          END;
          IF NOT FLAG THEN
               PUT_LINE ("WORKING ON " & FNAME(1..LENGTH));
               IF FILE_COUNT = 70 THEN
                    PUT_LINE ("MACRO SUBSTITUTIONS HALF COMPLETED.");
               END IF;
               FOR I IN REVERSE 1 .. LENGTH LOOP
                    IF FNAME(I) = ';' THEN
                         LENGTH := I - 1;
                         EXIT;
                    END IF;
               END LOOP;
               IF FNAME (LENGTH-2..LENGTH) = "TST" THEN
                    FNAME (LENGTH-2..LENGTH) := "ADT";
               ELSIF FNAME (LENGTH-2..LENGTH) = "tst" THEN
                    FNAME (LENGTH-2..LENGTH) := "adt";
               END IF;
               BEGIN
                    CREATE (OUTFILE1, OUT_FILE, FNAME (1..LENGTH));
               EXCEPTION
                    WHEN OTHERS =>
                         PUT_LINE ("** ERROR: EXCEPTION RAISED DURING" &
                                   " ATTEMPTED CREATION OF " &
                                   FNAME(1..LENGTH) & ".");
                         RAISE FILE_CRE;
               END;
               WHILE NOT END_OF_FILE (INFILE1) LOOP
                    GET_LINE (INFILE1, A_LINE, A_LENGTH);
                    IF A_LENGTH > 0 AND A_LINE(1..2) /= "--" THEN
                         END_OF_LINE_SEARCH := FALSE;
                         PTR := 1;
                         WHILE NOT END_OF_LINE_SEARCH LOOP
                              LOOK_FOR_MACRO (A_LINE, A_LENGTH, PTR,
                                              MACRO, MACRO_LEN);
                              IF MACRO_LEN = 0 THEN
                                   END_OF_LINE_SEARCH := TRUE;
                              ELSE --  SEE WHICH MACRO IT IS
                                   WHICH_MACRO (MACRO, MACRO_LEN,
                                       TEMP_MACRO, TEMP_MACRO_LENGTH);
                              END IF;
                              IF NOT END_OF_LINE_SEARCH THEN
                                   IF PTR-MACRO_LEN-2 > 0 THEN
                                 -- IF MACRO IS NOT FIRST ON THE LINE
                                        NEW_LINE (1..PTR-MACRO_LEN-2)
                                         := A_LINE(1..PTR-MACRO_LEN -2);
                                 -- THE OLD LINE UNTIL THE DOLLAR SIGN
                                   END IF;
                                   NEW_LINE(PTR-MACRO_LEN-1 ..
                                            TEMP_MACRO_LENGTH +
                                            (PTR-MACRO_LEN) - 2) :=
                                       TEMP_MACRO(1..TEMP_MACRO_LENGTH);
                                   IF PTR <= A_LENGTH THEN
                                 -- IF MACRO IS NOT LAST ON THE LINE
                                        NEW_LINE (TEMP_MACRO_LENGTH +
                                             PTR-MACRO_LEN - 1 ..
                                             TEMP_MACRO_LENGTH - 1 +
                                             A_LENGTH - MACRO_LEN) :=
                                             A_LINE (PTR..A_LENGTH);
                                   ELSE
                                        END_OF_LINE_SEARCH := TRUE;
                                   END IF;
                                   A_LENGTH := A_LENGTH +
                                               TEMP_MACRO_LENGTH -
                                               MACRO_LEN - 1;
                                   A_LINE (1..A_LENGTH) :=
                                          NEW_LINE (1..A_LENGTH);
                                   PTR := PTR - MACRO_LEN +
                                          TEMP_MACRO_LENGTH - 1;
                              END IF;
                         END LOOP;
                    END IF;
                    PUT_LINE (OUTFILE1, A_LINE (1..A_LENGTH));
               END LOOP;
               CLOSE (OUTFILE1);
               CLOSE (INFILE1);
          ELSE
               FLAG := FALSE;
          END IF;
     END LOOP;
     CLOSE (INFILE2);
     PUT_LINE ("MACRO SUBSTITUTIONS COMPLETED.");
EXCEPTION
     WHEN MAC_FILE | LINE_LEN | TSTTESTS | FILE_CRE =>
          NULL;
     WHEN OTHERS =>
          PUT_LINE ("UNEXPECTED EXCEPTION RAISED");
END MACROSUB;
