-- CXA4025.A
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
--      Check that the functionality found in packages Ada.Strings.Wide_Maps,
--      Ada.Strings.Wide_Fixed, and Ada.Strings.Wide_Maps.Wide_Constants
--      is available and produces correct results.
--
-- TEST DESCRIPTION:
--      This test validates the subprograms found in the various Wide_Map
--      and Wide_String packages.  It is based on the tests CXA4024 and
--      CXA4026, which are tests for the complementary "non-wide" packages.
--      
--      The functions found in CXA4025_0 provide mapping capability, when
--      used in conjunction with Wide_Character_Mapping_Function objects.
--
--       
-- CHANGE HISTORY:
--      23 Jun 95   SAIC    Initial prerelease version.
--      15 Apr 96   SAIC    Incorporated reviewer comments for ACVC 2.1.
--
--!

package CXA4025_0 is
   -- Functions used to supply mapping capability.
   function Map_To_Lower_Case (From : Wide_Character) return Wide_Character;
   function Map_To_Upper_Case (From : Wide_Character) return Wide_Character;
end CXA4025_0;
