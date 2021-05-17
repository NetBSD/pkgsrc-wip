-- CXA4012.A
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
--      Check that the types, operations, and other entities defined within
--      the package Ada.Strings.Wide_Maps are available and produce correct
--      results.
--
-- TEST DESCRIPTION:
--      This test demonstrates the availability and function of the types and
--      operations defined in package Ada.Strings.Wide_Maps.  It demonstrates
--      the use of these types and functions as they would be used in common
--      programming practice.
--      Wide_Character set creation, assignment, and comparison are evaluated
--      in this test.  Each of the functions provided in package
--      Ada.Strings.Wide_Maps is utilized in creating or manipulating set
--      objects, and the function results are evaluated for correctness.
--      Wide_Character sequences are examined using the functions provided for 
--      manipulating objects of this type.  Likewise, Wide_Character maps are
--      created, and their contents evaluated.  Exception raising conditions
--      from the function To_Mapping are also created.
--      Note: Throughout this test, the set logical operators are printed in
--      capital letters to enhance their visibility.
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      01 Nov 95   SAIC    Update and repair for ACVC 2.0.1.
-- 
--!

with Ada.Characters.Handling;
with Ada.Strings.Wide_Maps;

package CXA40120 is

   function Equiv (Ch : Character) return Wide_Character;
   function Equiv (Str : String) 
     return Ada.Strings.Wide_Maps.Wide_Character_Sequence;
   function X_Map(From : Wide_Character) return Wide_Character;

end CXA40120;
