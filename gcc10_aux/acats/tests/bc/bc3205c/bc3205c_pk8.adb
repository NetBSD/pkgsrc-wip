
PACKAGE BODY BC3205C_PK8 IS

     procedure Dummy is begin null; end Dummy;

     TYPE RC IS RECORD
          RCP : PVT;
          RCL : LMP;                      -- ERROR: LMP is indefinite.
     END RECORD;

BEGIN
     NULL;
END BC3205C_PK8;
