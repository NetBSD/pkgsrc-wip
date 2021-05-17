
SEPARATE (SHARED_C94008D)
TASK BODY SHARE IS
     VARIABLE : HOLDER_TYPE;
BEGIN
     LOOP
          SELECT
               ACCEPT SET (VALUE : IN HOLDER_TYPE) DO
                    SHARED_C94008D.SET (VARIABLE, VALUE);
               END SET;
          OR
               ACCEPT UPDATE (VALUE : IN VALUE_TYPE) DO
                    SHARED_C94008D.UPDATE (VARIABLE, VALUE);
               END UPDATE;
          OR
               ACCEPT READ (VALUE : OUT HOLDER_TYPE) DO
                    VALUE := VARIABLE;
               END READ;
          OR
               TERMINATE;
          END SELECT;
     END LOOP;
END SHARE;
