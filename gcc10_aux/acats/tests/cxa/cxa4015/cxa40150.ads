-- CXA4015.A
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
--      check the subprograms Count, Find_Token, Index, Index_Non_Blank, and
--      Move.
--      
-- TEST DESCRIPTION:
--      This test, when combined with tests CXA4013,14,16 will provide 
--      coverage of the functionality found in Ada.Strings.Wide_Fixed.  
--      This test contains many small, specific test cases, situations that 
--      although common in user environments, are often difficult to generate 
--      in large numbers in a application-based test.
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      02 Nov 95   SAIC    Corrected various accesssibility problems and
--                          expected result strings for ACVC 2.0.1.
--
--!

package CXA40150 is

   -- Wide Character mapping function defined for use with specific 
   -- versions of functions Index and Count.

   function AK_to_ZQ_Mapping (From : Wide_Character) return Wide_Character;

end CXA40150;
