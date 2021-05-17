-- CB40005.A
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
--      Check that exceptions raised in non-generic code can be handled by
--      a procedure in a generic package.  Check that the exception identity
--      can be properly retrieved from the generic code and used by the
--      non-generic code.
--
-- TEST DESCRIPTION:
--      This test models a possible usage paradigm for the type:
--        Ada.Exceptions.Exception_Occurrence.
--
--      A generic package takes access to procedure types (allowing it to
--      be used at any accessibility level) and defines a "fail soft"
--      procedure that takes designators to a procedure to call, a
--      procedure to call in the event that it fails, and a function to
--      call to determine the next action.
--
--      In the event an exception occurs on the call to the first procedure,
--      the exception is stored in a stack; along with the designator to the
--      procedure that caused it; allowing the procedure to be called again,
--      or the exception to be re-raised.
--
--      A full implementation of such a tool would use a more robust storage
--      mechanism, and would provide a more flexible interface.
--
--
-- CHANGE HISTORY:
--      29 Mar 96   SAIC   Initial version
--      12 Nov 96   SAIC   Revised for 2.1 release
--      19 Mar 07   RLB    Restructured to eliminate illegal (by Amendment 1)
--                         returns.
--
--!

----------------------------------------------------------------- CB40005_0

with Ada.Exceptions;
generic
  type Proc_Pointer is access procedure;
  type Func_Pointer is access function return Proc_Pointer;
package CB40005_0 is -- Fail_Soft


  procedure Fail_Soft_Call( Proc_To_Call : Proc_Pointer;
                            Proc_To_Call_On_Exception : Proc_Pointer := null;
                            Retry_Routine : Func_Pointer := null );

  function Top_Event_Exception return Ada.Exceptions.Exception_Occurrence_Access;

  function Top_Event_Procedure return Proc_Pointer;

  procedure Pop_Event;

  function Event_Stack_Size return Natural;

end CB40005_0; -- Fail_Soft
