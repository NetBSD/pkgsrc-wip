
PACKAGE BODY BC3205C_PK7 IS

     procedure Dummy is begin null; end Dummy;

     TYPE ARP IS ARRAY (INTEGER) OF PRV;
     TYPE ARL IS ARRAY (INTEGER) OF LIM;  -- ERROR: LIM is indefinite.

BEGIN
     NULL;
END BC3205C_PK7;
