-- B392004.A
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
--      Check that:
--      A dynamically tagged value is not allowed in an object or expression
--      for which the expected type is a specific tagged value (unless it is
--      a controlling operand on a dispatching operation).
--      An access-to-classwide type is not allowed in an expression for
--      which the expected type is an anonymous access to specific type
--      (unless it is a controlling operand on a dispatching operation).
--      A call on dispatching operation may not have both dynamically tagged
--      and statically tagged controlling operands.
--
-- TEST DESCRIPTION:
--      This test declares tagged types, a type extension, a tagged type
--      with discriminant, and some dispatching operations.  Verify that
--      compiler generates errors for all cases as described in the objective.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--      07 Feb 18   RLB     Added error location indicators to reflect common
--                          error reporting strategies.
--
--!

package B392004_0 is

   type Tagged_Type is tagged
     record
        Field : Boolean;
   end record;

   function No_Parm return Tagged_Type'class;

   function One_Parm (P : Tagged_Type) return Tagged_Type;

   procedure Proc_Specific_Type_Parms (P1, P2 : Tagged_Type);

   type New_Tagged_Type is new Tagged_Type with
     record
        New_Field : Integer;
   end record;

   -- Override inherited One_Parm.
   function One_Parm (P : New_Tagged_Type) return New_Tagged_Type;

   -- Override inherited Proc_Specific_Type_Parms.
   procedure Proc_Specific_Type_Parms (P1, P2 : New_Tagged_Type);

   type Access_To_Class_Wide_Type is access all Tagged_Type'class;

   type Rec_Anon_Acc_Disc (D : access Tagged_Type) is tagged limited
     record
        Other_Field : Integer;
   end record;

end B392004_0;
