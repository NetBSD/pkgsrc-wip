
PACKAGE BODY BC3205C_PK6 IS

     procedure Dummy is begin null; end Dummy;

     TYPE ARP IS ARRAY (INTEGER) OF PRV;  -- ERROR: PRV is indefinite.
     TYPE ARL IS ARRAY (INTEGER) OF LIM;

BEGIN
     NULL;
END BC3205C_PK6;
