
PACKAGE BODY C83024E_P2 IS

     PROCEDURE REQUIRE_BODY IS
     BEGIN
       NULL;
     END;

     PACKAGE BODY C83024E_PACK2 IS
     BEGIN
          IF A /= IDENT_INT(3) THEN
               FAILED ("INCORRECT VALUE FOR INNER HOMOGRAPH - 10");
          END IF;

          IF C83024E_P2.A /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR OUTER HOMOGRAPH - 11");
          END IF;

          IF C83024E_P2.B /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR OUTER VARIABLE - 12");
          END IF;

          IF C /= IDENT_INT(3) THEN
               FAILED ("INCORRECT VALUE FOR INNER VARIABLE - 13");
          END IF;

          IF X /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE PASSED IN - 14");
          END IF;

          IF EQUAL(1,1) THEN
               A := IDENT_INT(4);
          ELSE
               A := 1;
          END IF;
     END C83024E_PACK2;
END C83024E_P2;
