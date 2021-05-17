
PACKAGE BODY C83024E_P3 IS

     PROCEDURE REQUIRE_BODY IS
     BEGIN
       NULL;
     END;

     PACKAGE BODY C83024E_PACK3 IS
          C : INTEGER := A;
          A : INTEGER := IDENT_INT(3);
     BEGIN
          IF A /= IDENT_INT(3) THEN
               FAILED ("INCORRECT VALUE FOR INNER HOMOGRAPH - 20");
          END IF;

          IF C83024E_P3.A /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR OUTER HOMOGRAPH - 21");
          END IF;

          IF C83024E_P3.B /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR OUTER VARIABLE - 22");
          END IF;

          IF C /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR INNER VARIABLE - 23");
          END IF;

          IF X /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE PASSED IN - 24");
          END IF;

          IF EQUAL(1,1) THEN
               X := A;
          ELSE
               NULL;
          END IF;
     END C83024E_PACK3;
END C83024E_P3;
