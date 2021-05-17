-- C460005.A
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
--      Check that, for a view conversion of a tagged type that is the left 
--      side of an assignment statement, the assignment assigns to the 
--      corresponding part of the object denoted by the operand.
--
-- TEST DESCRIPTION:
--      View conversions of class-wide operands to specific types are
--      placed on the right and left sides of assignment statements, and
--      conversions of class-wide operands to class-wide types are used
--      as actual parameters to dispatching operations. In all cases, a
--      check is made that Constraint_Error is raised if the tag of the
--      operand does not identify a specific type covered by or descended
--      from the target type, and not raised otherwise.
--
--      For the cases where the view conversion is the left side of an
--      assignment statement, and Constraint_Error should not be raised,
--      an additional check is made that only the corresponding portion
--      of the operand is updated by the assignment. For example:
--
--         type T is tagged record
--            C1 : Integer := 0;
--         end record;
--
--         type DT is new T with record
--            C2 : Integer := 0;
--         end record;
--
--         A    : T       := (C1 => 5);
--         B    : DT      := (C1 => 0, C2 => 10);
--         CWDT : T'Class := B;
--
--         T(CWDT) := A;  -- Updates component C1; C2 remains unchanged.
--                        -- Value of CWDT is (C1 => 5, C2 => 10).
--
--
-- CHANGE HISTORY:
--      31 Jul 95   SAIC    Initial prerelease version.
--      22 Apr 96   SAIC    ACVC 2.1: Added a check for correct tag.
--      08 Sep 96   SAIC    ACVC 2.1: Modified Report.Test. 
--
--!

package C460005_0 is

   type Tag_Type is tagged record
      C1 : Natural;
   end record;

   procedure Proc (X : in out Tag_Type);


   type DTag_Type is new Tag_Type with record
      C2 : String (1 .. 5);
   end record;

   procedure Proc (X : in out DTag_Type);


   type DDTag_Type is new DTag_Type with record
      C3 : String (1 .. 5);
   end record;

   procedure Proc (X : in out DDTag_Type);

end C460005_0;
