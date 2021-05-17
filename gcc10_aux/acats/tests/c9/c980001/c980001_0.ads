-- C980001.A
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
--      Check that when a construct is aborted the execution of an Initialize
--      procedure as the last step of the default initialization of a
--      controlled object is abort-deferred.
--     
--      Check that when a construct is aborted the execution of a Finalize
--      procedure as part of the finalization of a controlled object is
--      abort-deferred.
--     
--      Check that an assignment operation to an object with a controlled
--      part is an abort-deferred operation.
--
-- TEST DESCRIPTION:
--      The controlled operations which are being tested call a subprogram
--      which guarantees that the enclosing operation becomes aborted.
--
--      Each object is created with a unique value to prevent optimizations
--      due to the values being the same.
--
--      Two protected objects are utilized to warrant that the operations
--      are delayed in their execution until such time that the abort is
--      processed.  The object Hold_Up is used to hold the targeted
--      operation in execution, the object Progress is used to communicate
--      to the driver software that progress is indeed being made. 
--
--
-- CHANGE HISTORY:
--      01 MAY 95   SAIC    Initial version
--      01 MAY 96   SAIC    Revised for 2.1
--      11 DEC 96   SAIC    Final revision for 2.1
--      02 DEC 97   EDS     Remove 2 calls to C980001_0.Hold_Up.Lock
--!

---------------------------------------------------------------- C980001_0

with Impdef;
with Ada.Finalization;
package C980001_0 is

  A_Little_While : constant Duration := Impdef.Switch_To_New_Task * 2.0;
  Enough_Time_For_The_Controlled_Operation_To_Happen : constant Duration
   := Impdef.Switch_To_New_Task * 4.0;

  function TC_Unique return Integer;

  type Sticks_In_Initialize is new Ada.Finalization.Controlled with record
    Item: Integer := TC_Unique;
  end record;
  procedure Initialize( AV: in out Sticks_In_Initialize );

  type Sticks_In_Adjust is new Ada.Finalization.Controlled with record
    Item: Integer := TC_Unique;
  end record;
  procedure Adjust    ( AV: in out Sticks_In_Adjust );

  type Sticks_In_Finalize is new Ada.Finalization.Controlled with record
    Item: Integer := TC_Unique;
  end record;
  procedure Finalize  ( AV: in out Sticks_In_Finalize );

  Initialize_Called : Boolean := False;
  Adjust_Called     : Boolean := False;
  Finalize_Called   : Boolean := False;

  protected type Sticker is
    entry Lock;
    procedure Unlock;
    function Is_Locked return Boolean;
  private
    Locked : Boolean := False;
  end Sticker;

  Hold_Up  : Sticker;
  Progress : Sticker;

  procedure Fail_And_Clear( Message : String );


end C980001_0;
