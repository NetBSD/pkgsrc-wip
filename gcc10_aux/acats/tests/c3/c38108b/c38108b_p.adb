
PACKAGE BODY C38108B_P IS
     TYPE INC (D : INTEGER) IS
          RECORD
               C : INTEGER;
          END RECORD;
     
     PROCEDURE ASSIGN (X : IN INTEGER; Y : IN OUT L) IS
     BEGIN
          Y := NEW INC(1);
          Y.C := X;
     END ASSIGN;

     FUNCTION "=" (X, Y : IN L) RETURN BOOLEAN IS
     BEGIN
          RETURN (X.C = Y.C);          
     END "=";

END C38108B_P;
