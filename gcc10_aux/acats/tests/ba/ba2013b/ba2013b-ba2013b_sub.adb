
WITH BA2013B_PACK;
USE BA2013B_PACK;
SEPARATE (BA2013B)
PROCEDURE BA2013B_SUB IS
BEGIN
     
     IF NOT VAR THEN          -- ERROR: ONLY BA2013B.VAR VISIBLE.
          NULL;
     END IF;

     VAR := 5;                      -- OK.

     IF NOT BA2013B_PACK.VAR THEN   -- OK.
          NULL;
     END IF;

     IF F THEN                -- ERROR: ONLY BA2013B.F VISIBLE.
          NULL;
     END IF;

     F := 6.0;                      -- OK.

     IF BA2013B_PACK.F THEN         -- OK.
          NULL;
     END IF;

END BA2013B_SUB;
