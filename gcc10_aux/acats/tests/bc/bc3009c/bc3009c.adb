
--
-- UNIT 2
--
PACKAGE BODY BC3009C IS

     GENERIC
     PACKAGE T IS
          PACKAGE NT IS NEW T;     -- ERROR: T DENOTES NON-GENERIC CURRENT
                                   -- INSTANCE, NOT THE GENERIC UNIT T
                                   -- (USER ATTEMPTED INSTANTIATION OF "SELF")
     END;

     PROCEDURE F IS
     BEGIN
          NULL;
     END;

BEGIN

     NULL;

END BC3009C;
