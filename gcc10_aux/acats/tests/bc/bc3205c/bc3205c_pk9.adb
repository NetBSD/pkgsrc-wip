
PACKAGE BODY BC3205C_PK9 IS

     procedure Dummy is begin null; end Dummy;

     TYPE RC IS RECORD
          RCP : PVT;                      -- ERROR: PVT is indefinite.
          RCL : LMP;
     END RECORD;

BEGIN
     NULL;
END BC3205C_PK9;
