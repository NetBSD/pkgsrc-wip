
PACKAGE BODY C93005G_PK1 IS

-- THIS TASK IS CALLED IF AN UNACTIVATED TASK
-- IS EVER INCORRECTLY ACTIVATED.  IT REPORTS FAILURE.

     TASK T IS
          ENTRY E;
     END;

     -- ***********************************************
     -- START OF DEFINITIONS FOR MUST NOT TERMINATE TASKS
     -- ***********************************************

-- COUNT OF TASKS THAT MUST NOT BE TERMINATED AND
-- ARE STILL ACTIVE.

     MNT_COUNT : INTEGER := 0;

-- TASK TO SYNCHRONIZE THE MNT_COUNT VARIABLE

     TASK MNT_COUNTER IS
          ENTRY INCR;
          ENTRY DECR;
     END MNT_COUNTER;

-- SYNCHRONIZING TASK

     TASK BODY MNT_COUNTER IS
     BEGIN
          LOOP
               SELECT
                    ACCEPT INCR DO
                         MNT_COUNT := MNT_COUNT +1;
                    END INCR;

               OR  ACCEPT DECR DO
                         MNT_COUNT := MNT_COUNT -1;
                    END DECR;

               OR  TERMINATE;

               END SELECT;
          END LOOP;
     END MNT_COUNTER;

-- INCREMENT THE MNT_COUNT WHEN A TASK IS CREATED
--
     FUNCTION F RETURN INTEGER IS
     BEGIN
          MNT_COUNTER.INCR;
          RETURN 0;
     END F;

-- CHECK THAT THE MUST NOT BE TERMINATED TASKS ARE
-- NOT YET TERMINATED AND THAT THE SYNCRHONIZING TASK
-- ITSELF IS NOT TERMINATED.
--
     PROCEDURE CHECK IS
     BEGIN
          IF MNT_COUNT /= 0 OR MNT_COUNTER'TERMINATED THEN
               FAILED ("SOME MUST-NOT-TERMINATE TASK WAS PREMATURELY " &
                       "TERMINATED");
          END IF;
-- RESET THE COUNT FOR THE NEXT SUBTEST:
          MNT_COUNT := 0;
     END CHECK;

-- A MUST NOT BE TERMINATED TASK.  DELAY LONG ENOUGH
-- TO BE THE LAST TASK OF A SCOPE TO TERMINATE.   THEN
-- DECREMENT THE COUNTER.
--
     TASK BODY MNT_TASK IS
     BEGIN
          DELAY 5.0;
          MNT_COUNTER.DECR;
     END MNT_TASK;

     -- ***********************************************
     -- END OF DEFINITIONS FOR MUST NOT TERMINATE TASKS
     -- ***********************************************

     TASK BODY T IS
     BEGIN
          LOOP
               SELECT
                    ACCEPT E DO
                         FAILED ("SOME TYPE U TASK WAS ACTIVATED");
                    END E;

               OR   TERMINATE;
               END SELECT;
          END LOOP;
     END T;

     -- TASKS OF TYPE UNACTIVATED MUST NEVER BE ACTIVATED.
     --
     TASK BODY UNACTIVATED IS
     BEGIN
          T.E;
     END UNACTIVATED;
END C93005G_PK1;
