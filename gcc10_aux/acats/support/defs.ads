-- MACROSUB.ADA
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-----------------------------------------------------------------------
--                                                                   --
--   THIS PROGRAM IS CALLED MACROSUB.  IT IS USED TO REPLACE THE     --
--   MACROS IN THE ACVC TEST SUITE WITH THEIR PROPER VALUES.  THE    --
--   STEPS LISTED BELOW SHOULD BE FOLLOWED TO ENSURE PROPER RUNNING  --
--   OF THE MACROSUB PROGRAM:                                        --
--                                                                   --
--           1) Edit the file MACRO.DFS (included with the testtape) --
--              and insert your macro values.  The macros which use  --
--              the value of MAX_IN_LEN are calculated automatically --
--              and do not need to be entered.                       --
--                                                                   --
--           2) Create a file called TSTTESTS.DAT which includes all --
--              of the .TST test file names and their directory      --
--              specifications, if necessary.  If a different name   --
--              other than TSTTESTS.DAT is used, this name must be   --
--              substituted in the MACROSUB.ADA file.                --
--                                                                   --
--           3) Compile and link MACROSUB.                           --
--                                                                   --
--           4) Run the MACROSUB program.                            --
--                                                                   --
--   WHEN THE PROGRAM FINISHES RUNNING, THE MACROS WILL HAVE BEEN    --
--   REPLACED WITH THE APPROPRIATE VALUES FROM MACRO.DFS.            --
--                                                                   --
--                                                                   --
--                                                                   --
-- HISTORY:                                                          --
--     BCB 04/17/90  CHANGED MODE OF CALC_MAX_VALS TO OUT.  CHANGED  --
--                   VALUE OF MAX_VAL_LENGTH FROM 512 TO 400.  ADDED --
--                   EXCEPTION HANDLER SO PROGRAM DOES NOT CRASH IF  --
--                   AN EXCEPTION IS RAISED.  ADDED MESSAGES TO      --
--                   REPORT PROGRESS OF PROGRAM.  CHANGED PROGRAM SO --
--                   IT DOES NOT ABORT IF A FILE CANNOT BE FOUND.    --
--                   MODIFIED PROGRAM SO IT ACCEPTS FILENAMES WITH   --
--                   VERSION NUMBERS.                                --
-----------------------------------------------------------------------

WITH TEXT_IO;
USE TEXT_IO;

PACKAGE DEFS IS

-----------------------------------------------------------------------
--                                                                   --
--   THIS PACKAGE IS USED BY MACROSUB.ADA, PARSEMAC.ADA, AND BY      --
--   GETSUBS.ADA.  THE PACKAGE CONTAINS VARIABLE DECLARATIONS WHICH  --
--   NEED TO BE KNOWN BY ALL OF THE PROCEDURES AND PACKAGES WHICH    --
--   MAKE UP THE PROGRAM.                                            --
--                                                                   --
-----------------------------------------------------------------------

     MAX_VAL_LENGTH : CONSTANT INTEGER := 400;

     SUBTYPE VAL_STRING IS STRING (1..MAX_VAL_LENGTH);

     TYPE REC_TYPE IS RECORD
          MACRO_NAME : STRING (1..80);
          NAME_LENGTH, VALUE_LENGTH : INTEGER;
          MACRO_VALUE : VAL_STRING;
     END RECORD;

     TYPE TABLE_TYPE IS ARRAY (1..100) OF REC_TYPE;

     SYMBOL_TABLE : TABLE_TYPE;

     NUM_MACROS : INTEGER;

END DEFS;
