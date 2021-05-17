-- CXA4014.A
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
--      Check that the subprograms defined in package Ada.Strings.Wide_Fixed
--      are available, and that they produce correct results.  Specifically, 
--      check the subprograms Find_Token, Head, Index, Index_Non_Blank, Move,
--      Overwrite, and Replace_Slice, Tail, and Translate. 
--      Use the access-to-subprogram mapping version of Translate (function
--      and procedure).
--
-- TEST DESCRIPTION:
--      This test demonstrates how certain wide fixed string operations could
--      be used in wide string information processing.  A procedure is defined
--      that will extract portions of a 50 character string that correspond to
--      certain data items (i.e., name, address, state, zip code). These
--      parsed items will then be added to the appropriate fields of data
--      base elements.  These data base elements are then compared for
--      accuracy against a similar set of predefined data base
--      elements.
--      A variety of wide fixed string processing subprograms are used in this
--      test.  Each parsing operation attempts to use a different combination
--      of the available subprograms to accomplish the same goal, therefore
--      continuity of approach to wide string parsing is not seen in this
--      test.
--      However, a wide variety of possible approaches are demonstrated, while
--      exercising a large number of the total predefined subprograms of
--      package Ada.Strings.Wide_Fixed.
--      
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      02 Nov 95   SAIC    Update and repair for ACVC 2.0.1.
--
--!

package CXA40140 is

   UnderScore  : Wide_Character := '_';
   Blank       : Wide_Character := ' ';

   -- Function providing a mapping to a blank Wide_Character.
   function US_to_Blank_Map (From : Wide_Character) return Wide_Character;

end CXA40140;
