
PACKAGE BODY BD5104A IS

     TASK BODY TASK1 IS
          FOR ENTRY1 USE AT ENTRY_ADDRESS;    -- ERROR:  ADDRESS CLAUSE
     BEGIN                                    -- CANNOT BE GIVEN IN
          ACCEPT ENTRY1;                      -- TASK BODY.
     END TASK1;

END BD5104A;
