-- C250002.AU
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
--      Check that characters in Latin-1 above ASCII.Del can be used in
--      identifiers, character literals and strings.
-- 
-- TEST DESCRIPTION:
--      This test is distributed in UTF-8 format. The test defines Character
--      and String objects, assigns and tests several sample values that use
--      values in extended Latin-1 characters. Several Identifiers
--      used in this test also include extended Latin-1 Characters.
--      The extended characters used are documented in comments.
--
--      Note that C250001 checks Wide_Characters and Wide_Strings.
--
-- CHANGE HISTORY:
--      10 JAN 96   SAIC   Initial version
--      12 NOV 96   SAIC   Changed file extension to .AW
--      27 DEC 07   RLB    Converted to UTF-8, changed file extension to .AU
--
--!

----------------------------------------------------------------- C250002_0

package C250002_0 is

  type Tagged_À_Id is tagged record -- À -> 16#C0#
    Length, Width: Natural;
  end record;

  X_Char_A2 : constant Character := '¢'; -- ¢ -> 16#A2#

  X_Char_A3_Through_A9 : constant String := 
               "£¤¥¦§¨©"; -- 16#A3# through 16#A9#

  X_Char_AA_AB : constant String := "ª«"; -- ª« -> 16#AA# 16#AB#

end C250002_0;
