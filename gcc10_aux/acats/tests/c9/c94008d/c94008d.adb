
WITH REPORT; USE REPORT;
WITH SYSTEM; USE SYSTEM;
WITH SHARED_C94008D, COUNTER_C94008D, EVENTS_C94008D;
USE  COUNTER_C94008D, EVENTS_C94008D;
PROCEDURE C94008D IS

     PACKAGE TRACE IS
          NEW SHARED_C94008D (EVENT_TYPE, CHARACTER, ("....", 0));
     PACKAGE TERMINATE_COUNT IS
          NEW SHARED_C94008D (INTEGER, INTEGER, 0);

     PROCEDURE EVENT (VAR : CHARACTER) RENAMES TRACE.UPDATE;

     FUNCTION ENTER_TERMINATE RETURN BOOLEAN IS
     BEGIN
          TERMINATE_COUNT.UPDATE (1);
          RETURN TRUE;
     END ENTER_TERMINATE;

BEGIN
     TEST ("C94008D", "CHECK CORRECT OPERATION OF SELECT WITH " &
                      "TERMINATE ALTERNATIVE FROM AN INNER BLOCK");

     DECLARE

          TASK T1 IS
               ENTRY E1;
          END T1;

          TASK BODY T1 IS
          BEGIN
               DECLARE

                    TASK T2 IS
                         ENTRY E2;
                    END T2;

                    TASK BODY T2 IS
                    BEGIN
                         DELAY 10.0;

                         IF TERMINATE_COUNT.GET /= 1 THEN
                              DELAY 20.0;
                         END IF;

                         IF TERMINATE_COUNT.GET /= 1 THEN
                              FAILED ("30 SECOND DELAY NOT ENOUGH");
                         END IF;

                         IF T1'TERMINATED OR NOT T1'CALLABLE THEN
                              FAILED ("T1 PREMATURELY TERMINATED");
                         END IF;

                         EVENT ('A');

                         SELECT
                              ACCEPT E2;
                         OR TERMINATE;
                         END SELECT;

                         FAILED ("TERMINATE NOT SELECTED IN T2");
                    END T2;

               BEGIN
                    BEGIN
                         EVENT ('B');

                         SELECT
                              ACCEPT E1;
                         OR WHEN ENTER_TERMINATE => TERMINATE;
                         END SELECT;

                         FAILED ("TERMINATE NOT SELECTED IN T1");
                    END;
               END;
          END T1;

     BEGIN
          EVENT ('C');
     EXCEPTION
          WHEN OTHERS => FAILED ("EXCEPTION RECEIVED IN MAIN");
     END;

     IF TRACE.GET.TRACE(3) = '.' OR TRACE.GET.TRACE(4) /= '.' THEN
          FAILED ("ALL EVENTS NOT PROCESSED CORRECTLY");
     END IF;

     COMMENT ("EXECUTION ORDER WAS " & TRACE.GET.TRACE);

     RESULT;
END C94008D;
