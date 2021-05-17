-- CXA4019.A
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
--      Check that the subprograms defined in package Ada.Strings.Wide_Bounded
--      are available, and that they produce correct results, especially 
--      under conditions where truncation of the result is required.  
--      Specifically, check the subprograms Append, Count with non-Identity
--      maps, Index with non-Identity maps, Index with Set parameters, 
--      Insert (function and procedure), Replace_Slice (function and 
--      procedure), To_Bounded_Wide_String, and Translate (function and 
--      procedure).
--
-- TEST DESCRIPTION:
--      This test, in conjunction with tests CXA4017, CXA4018, and CXA4020, 
--      will provide coverage of the most common usages of the functionality
--      found in the Ada.Strings.Wide_Bounded package.  It deals in large part
--      with truncation effects and options.  This test contains many small, 
--      specific test cases, situations that are often difficult to generate 
--      in large numbers in an application-based test.  These cases represent 
--      specific usage paradigms in-the-small.
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      06 Nov 95   SAIC    Corrected expected result string in subtest for
--                          ACVC 2.0.1.
--                          Moved function Dog_to_Cat_Mapping to library
--                          level to correct accessibility problem in test.
--      22 Aug 96   SAIC    Corrected three subtests identified in reviewer
--                          comments.
--      17 Feb 97   PWB.CTA Corrected result strings for Translate and Insert
--
--!

package CXA40190 is

   -- Wide Character mapping function defined for use with specific 
   -- versions of functions Index and Count.

   function Dog_to_Cat_Mapping (From : Wide_Character) 
        return Wide_Character;

end CXA40190;
