-- C641001.A
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
--      Check that actual parameters passed by reference are view converted
--      to the nominal subtype of the formal parameter.
--
-- TEST DESCRIPTION:
--      Check that sliding is allowed for formal parameters, especially
--      check cases that would have caused errors in Ada'83.
--      Check that length check for a formal parameter (esp out mode)
--      is performed before the call, not after.
--
--  notes: 6.2; by reference ::= tagged, task, protected,
--                       limited (nonprivate), or composite containing such
--         4.6; view conversion
--
--
-- CHANGE HISTORY:
--      26 JAN 96   SAIC   Initial version
--      04 NOV 96   SAIC   Commentary revision for release 2.1
--      27 FEB 97   PWB.CTA Corrected reference to the wrong string
--!

----------------------------------------------------------------- C641001_0

package C641001_0 is

  subtype String_10 is String(1..10);

  procedure Check_String_10( S : out String_10; Start, Stop: Natural );

  procedure Check_Illegal_Slice_Reference( Slice_Passed : in out String;
                                           Index: Natural );

  type Tagged_Data(Bound: Natural) is tagged record
    Data_Item : String(1..Bound) := (others => '*');
  end record;

  type Tag_List is array(Natural range <>) of Tagged_Data(5);

  subtype Tag_List_10 is Tag_List(1..10);

  procedure Check_Tag_Slice( TL : in out Tag_List_10 );

  procedure Check_Out_Tagged_Data( Formal : out Tagged_Data );

end C641001_0;
