
PACKAGE BODY BC3205C_PK3 IS

     procedure Dummy is begin null; end Dummy;

     TYPE AP IS ACCESS P;
     TYPE AL IS ACCESS L;
     NP : AP := NEW P;
     NL : AL := NEW L;                    -- ERROR: L is indefinite.

BEGIN
     NULL;
END BC3205C_PK3;
