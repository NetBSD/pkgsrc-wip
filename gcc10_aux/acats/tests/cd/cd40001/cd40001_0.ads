-- CD40001.A
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
-- OBJECTIVE:
--      Check that Enumeration_Representation_Clauses are supported for
--      codes in the range System.Min_Int..System.Max_Int.
--
-- TEST DESCRIPTION:
--      This test defines several types, and checks that the range of the 
--      enumeration clause is as expected.
--
-- APPLICABILITY CRITERIA:
--      All implementations must attempt to compile this test.
--
--      For implementations validating against Systems Programming Annex (C):
--        this test must execute and report PASSED.
--
--      For implementations not validating against Annex C:
--        this test may report compile time errors at one or more points
--        indicated by "-- ANX-C RQMT", in which case it may be graded as inapplicable.
--        Otherwise, the test must execute and report PASSED.
--
--
-- CHANGE HISTORY:
--      22 JUL 95   SAIC   Initial version
--      07 MAY 96   SAIC   Revised for 2.1
--      16 FEB 98   EDS    Modified Documentation.
--!

with System;
with Ada.Unchecked_Conversion;
package CD40001_0 is

  type Press_The_Bounds is ( Negative_Large, Positive_Large );

  for Press_The_Bounds use
      ( Negative_Large => System.Min_Int,                     -- ANX-C RQMT.
        Positive_Large => System.Max_Int );                   -- ANX-C RQMT.

  type Add_The_Bounds is 
    ( Monday, Tuesday, Wednesday, Thursday, Friday, Saturday);

  for Add_The_Bounds use
      ( Monday    => System.Min_Int,                          -- ANX-C RQMT.
        Tuesday   => System.Min_Int + 1,                      -- ANX-C RQMT.
        Wednesday => System.Min_Int + 2,                      -- ANX-C RQMT.
        Thursday  => System.Min_Int + 3,                      -- ANX-C RQMT.
        Friday    => System.Min_Int + 4,                      -- ANX-C RQMT.
        Saturday  => System.Min_Int + 5 );                    -- ANX-C RQMT.

  type Minus_The_Bounds is ( Jan, Feb, Mar, Apr);

  for Minus_The_Bounds use
      ( Apr => System.Max_Int,                                -- ANX-C RQMT.
        Mar => System.Max_Int - 1,                            -- ANX-C RQMT.
        Feb => System.Max_Int - 2,                            -- ANX-C RQMT.
        Jan => System.Max_Int - 3 );                          -- ANX-C RQMT.

  type TC_Integer is range System.Min_Int..System.Max_Int;

  procedure TC_Check_Press; 

  procedure TC_Check_Add; 

  procedure TC_Check_Minus; 

  function TC_Compare_Press is new Ada.Unchecked_Conversion 
    (Press_The_Bounds, TC_Integer);

  function TC_Compare_Add is new Ada.Unchecked_Conversion 
    (Add_The_Bounds, TC_Integer);

  function TC_Compare_Minus is new Ada.Unchecked_Conversion 
    (Minus_The_Bounds, TC_Integer);

end CD40001_0;
