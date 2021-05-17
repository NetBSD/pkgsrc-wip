
WITH SYSTEM; USE SYSTEM;
WITH REPORT; USE REPORT;
WITH C94005B_PKG; USE C94005B_PKG;
WITH F;
PROCEDURE C94005B IS


BEGIN
     TEST ("C94005B", "CHECK THAT IF A TASK TYPE IS DECLARED IN A " &
                      "LIBRARY PACKAGE, ANY BLOCKS, SUBPROGRAMS, OR " &
                      "TASKS THAT DECLARE OBJECTS OF THAT TYPE DO " &
                      "WAIT FOR TERMINATION OF SUCH OBJECTS");

     --------------------------------------------------

     GLOBAL := IDENT_INT (0);

     DECLARE -- (A)

          T : TT;

     BEGIN -- (A)

          T.E (IDENT_INT(1));

     END; -- (A)

     IF GLOBAL /= 1 THEN
          FAILED ("DEPENDENT TASK NOT TERMINATED BEFORE " &
                  "BLOCK EXIT - (A)");
     END IF;

     --------------------------------------------------

     GLOBAL := IDENT_INT (0);

     DECLARE -- (B)

          I : INTEGER;

     BEGIN -- (B)

          I := F ;

          IF GLOBAL /= 2 THEN
               FAILED ("DEPENDENT TASK NOT TERMINATED BEFORE " &
                       "FUNCTION EXIT - (B)");
          END IF;

     END; -- (B)

     --------------------------------------------------

     GLOBAL := IDENT_INT (0);

     DECLARE -- (C)

          TASK TSK IS
               ENTRY ENT;
          END TSK;

          TASK BODY TSK IS
               T : TT;
          BEGIN
               T.E (IDENT_INT(3));
          END TSK;

     BEGIN -- (C)

          WHILE NOT TSK'TERMINATED LOOP
               DELAY 0.1;
          END LOOP;

          IF GLOBAL /= 3 THEN
               FAILED ("DEPENDENT TASK NOT TERMINATED BEFORE " &
                       "TASK EXIT - (C)");
          END IF;

     END; -- (C)

     --------------------------------------------------

     RESULT;
END C94005B;
