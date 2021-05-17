-- C450001.A
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
--     Check that operations on modular types perform correctly.
--
--     Check that loops over the range of a modular type do not over or
--     under run the loop.
--
-- TEST DESCRIPTION:
--     Check logical and arithmetic operations.
--     (Attributes are tested elsewhere)
--     Checks to make sure that:
--        for X in Mod_Type loop
--     doesn't do something silly like infinite loop.
--
--
-- CHANGE HISTORY:
--      20 SEP 95   SAIC   Initial version
--      20 FEB 96   SAIC   Added underrun cases for 2.1
--
--!

----------------------------------------------------------------- C450001_0

package C450001_0 is

  type Unsigned_8_Bit is mod 2**8;

  Shy_By_One : constant := 2**8-1;

  Heavy_By_Two : constant := 2**8+2;

  type Unsigned_Edge_8 is mod Shy_By_One;

  type Unsigned_Over_8 is mod Heavy_By_Two;

  procedure Loop_Check;

 -- embed some calls to Report.Ident_Int:

  function ID( U8B: Unsigned_8_Bit )  return Unsigned_8_Bit;
  function ID( UEB: Unsigned_Edge_8 ) return Unsigned_Edge_8;
  function ID( UOB: Unsigned_Over_8 ) return Unsigned_Over_8;

end C450001_0;
