
PACKAGE BODY CA1108A_PKG IS
     
     PROCEDURE SUB (X, Y : IN OUT INTEGER) IS SEPARATE;

     PROCEDURE PROC IS
          Y : INTEGER := 2;
     BEGIN
          Y := OTHER_PKG.I;
          IF Y /= 4 THEN
               FAILED ("OTHER_PKG VARIABLE NOT VISIBLE " &
                       "IN PACKAGE BODY PROCEDURE");
          END IF;
     END PROC;

     PROCEDURE CALL_SUBS (X, Y : IN OUT INTEGER) IS
     BEGIN
          SUB (X, Y);
     END CALL_SUBS;

BEGIN  

     J := F(J);            -- J => J + 1.
     IF J /= 3 THEN
          FAILED ("OTHER_PKG FUNCTION NOT VISIBLE IN " &
                  "PACKAGE BODY");
     END IF;

END CA1108A_PKG;
