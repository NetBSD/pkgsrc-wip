
WITH TEXT_IO;
USE TEXT_IO;
WITH DEFS;
USE DEFS;

PACKAGE PARSEMAC IS

------------------------------------------------------------------------
--                                                                    --
--   THIS PACKAGE IS USED BY MACROSUB.ADA FOR FINDING A MACRO TO      --
--   SUBSTITUTE.  MACRO SUBSTITUTIONS ARE MADE IN *.TST TESTS IN THE  --
--   ACVC TEST SUITE.  THIS PROCEDURE IS CURRENTLY SET UP FOR ACVC    --
--   VERSION 1.10.                                                    --
--                                                                    --
------------------------------------------------------------------------

     PROCEDURE LOOK_FOR_MACRO (A_LINE : IN STRING;
                               A_LENGTH : IN INTEGER;
                               PTR : IN OUT INTEGER;
                               MACRO : OUT STRING;
                               MACRO_LEN : IN OUT INTEGER);


     PROCEDURE WHICH_MACRO (MACRO : IN STRING;
                            MACRO_LEN : IN INTEGER;
                            TEMP_MACRO : OUT STRING;
                            TEMP_MACRO_LEN : IN OUT INTEGER);

END PARSEMAC;
