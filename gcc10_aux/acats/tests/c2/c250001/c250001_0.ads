-- C250001.AU
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
--      Check that wide character literals are supported.
--      Check that wide character string literals are supported.
--
-- TEST DESCRIPTION:
--      This test is distributed in UTF-8 format.
--      The test defines Wide_Character and Wide_String objects, and assigns
--      and tests several sample values.
--
-- CHANGE HISTORY:
--      26 OCT 95   SAIC   Initial .A version
--      11 APR 96   SAIC   Minor robustness changes for 2.1
--      12 NOV 96   SAIC   Changed file extension to .AW
--      27 DEC 07   RLB    Converted to UTF-8 and changed file extension to .AU
--                         Changed to use dingbat and Greek characters.
--
--!

----------------------------------------------------------------- C250001_0

package C250001_0 is

  Sun : constant Wide_Character := '☼'; -- 16#263C#

  Male_Female_Suits : constant Wide_String := 
               "♀♂♠♣♥♦"; -- 16#2640#,16#2642#,16#2660#,16#2663#,16#2665#,16#2666#

  Faces : constant Wide_String := "☺☻"; -- 16#263A#,16#263B#

  Greek_to_Me : constant Wide_String := "Πλάτων"; -- Plato, from examples in Ada Standard
                 -- 16#03A0#,16#03BB#,16#03AC#,16#03C4#,16#03C9#,16#03BD#

end C250001_0;
