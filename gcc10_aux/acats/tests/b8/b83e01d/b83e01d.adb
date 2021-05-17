-- B83E01D.ADA

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
-- OBJECTIVE:
--     CHECK THAT A FORMAL PARAMETER OF A SUBPROGRAM SUBUNIT AND A
--     GENERIC SUBPROGRAM SUBUNIT CANNOT  BE IDENTICAL TO ANY OTHER
--     IDENTIFIERS DECLARED IN THE SUBPROGRAM.

-- HISTORY:
--     DHH 09/13/88  CREATED ORIGINAL TEST.
--     EDS 06/01/98  In lines 302 and 307, 
--                   change "-- ERROR:" to "-- OPTIONAL ERROR:"

PROCEDURE B83E01D IS

     GENERIC
     PROCEDURE B83E01D_GEN_PROC1(PARAM1, PARAM2, PARAM3, PARAM4,
                                 PARAM5, PARAM6, PARAM7 : INTEGER);

     GENERIC
     PROCEDURE B83E01D_GEN_PROC2(PARAM1, PARAM2, PARAM3,
                                 PARAM4 : INTEGER);

     GENERIC
     FUNCTION B83E01D_GEN_PROC3(PARAM1, PARAM2 : INTEGER)
                                                         RETURN BOOLEAN;

     GENERIC
          TYPE PARAM1 IS (<>);
          TYPE PARAM2 IS (<>);
          TYPE PARAM3 IS (<>);
          TYPE PARAM4 IS (<>);
          TYPE PARAM5 IS (<>);
          TYPE PARAM6 IS (<>);
          TYPE PARAM7 IS (<>);
     PROCEDURE B83E01D_GEN_PROC4;

     GENERIC
          TYPE PARAM1 IS (<>);
          TYPE PARAM2 IS (<>);
          TYPE PARAM3 IS (<>);
          TYPE PARAM4 IS (<>);
     PROCEDURE B83E01D_GEN_PROC5;

     GENERIC
          TYPE PARAM1 IS (<>);
          TYPE PARAM2 IS (<>);
     FUNCTION B83E01D_GEN_PROC6 RETURN BOOLEAN;

     PROCEDURE B83E01D_GEN_PROC1(PARAM1, PARAM2, PARAM3, PARAM4,
                                 PARAM5, PARAM6, PARAM7 : INTEGER)
                                                           IS SEPARATE;

     PROCEDURE B83E01D_GEN_PROC2(PARAM1, PARAM2, PARAM3,
                                 PARAM4 : INTEGER) IS SEPARATE;

     FUNCTION B83E01D_GEN_PROC3(PARAM1, PARAM2 : INTEGER) RETURN BOOLEAN
                                                           IS SEPARATE;

     PROCEDURE B83E01D_GEN_PROC4 IS SEPARATE;

     PROCEDURE B83E01D_GEN_PROC5 IS SEPARATE;

     FUNCTION B83E01D_GEN_PROC6 RETURN BOOLEAN IS SEPARATE;

     PROCEDURE B83E01D_PROC1(PARAM1, PARAM2, PARAM3, PARAM4,
                                 PARAM5, PARAM6, PARAM7 : INTEGER)
                                                           IS SEPARATE;

     PROCEDURE B83E01D_PROC2(PARAM1, PARAM2, PARAM3, PARAM4 : INTEGER)
                                                           IS SEPARATE;

     FUNCTION B83E01D_PROC3(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5 :
                                   INTEGER) RETURN BOOLEAN IS SEPARATE;
BEGIN
     NULL;
END B83E01D;
