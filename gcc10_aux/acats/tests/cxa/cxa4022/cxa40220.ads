-- CXA4022.A
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
--      Check that the subprograms defined in package 
--      Ada.Strings.Wide_Unbounded are available, and that they produce 
--      correct results. Specifically, check the subprograms Count, Element,
--      Index, Replace_Element, To_Unbounded_Wide_String, and "&", ">", "<".
--      
-- TEST DESCRIPTION:
--      This test demonstrates the uses of many of the subprograms defined
--      in package Ada.Strings.Wide_Unbounded for use with unbounded wide 
--      strings.  The test simulates how unbounded wide strings 
--      will be processed in a user environment, using the subprograms 
--      provided in this package.
--
--      Taken in conjunction with tests CXA4021 and CXA4023, this test will 
--      constitute a test of the functionality contained in package
--      Ada.Strings.Wide Unbounded.  This test uses a variety
--      of the subprograms defined in the unbounded wide string package
--      in ways typical of common usage, with different combinations of
--      available subprograms being used to accomplish similar 
--      unbounded wide string processing goals.
--      
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      08 Nov 95   SAIC    Corrected accessibility level, type visibility,
--                          and subtest acceptance criteria problems for 
--                          ACVC 2.0.1
--
--!

with Ada.Characters.Handling;
with Ada.Strings;

package CXA40220 is

   -- The following two functions are used to translate character and string
   -- values to "Wide" values.  They will be applied to all the Wide_Bounded
   -- subprogram character and string parameters to simulate the use of non-
   -- character Wide_Characters and Wide_Strings in actual practice.
   -- Note: These functions do not actually return "equivalent" wide
   --       characters to their character inputs, just "non-character"
   --       wide characters.

   function Equiv (Ch : Character) return Wide_Character;

   function Equiv (Str : String) return Wide_String;


   -- Functions and access-to-subprogram value used to supply mapping
   -- capability to the appropriate versions of Count, Index, and 
   -- Translate.

   function AB_to_US_Mapping_Function (From : Wide_Character) 
     return Wide_Character;

   function AB_to_Blank_Mapping_Function (From : Wide_Character) 
     return Wide_Character;

end CXA40220;
