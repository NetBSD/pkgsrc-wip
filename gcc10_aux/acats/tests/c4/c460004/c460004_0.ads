-- C460004.A
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
--      Check that if the operand type of a type conversion is class-wide,
--      Constraint_Error is raised if the tag of the operand does not
--      identify a specific type that is covered by or descended from the
--      target type.
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
--      A specific type is descended from itself and from those types it is
--      directly or indirectly derived from. A specific type is covered by
--      itself and each class-wide type to whose class it belongs.
--      
--      A class-wide type T'Class is descended from T and those types which
--      T is descended from. A class-wide type is covered by each class-wide
--      type to whose class it belongs.
--      
--
-- CHANGE HISTORY:
--      19 Jul 95   SAIC    Initial prerelease version.
--      18 Apr 96   SAIC    ACVC 2.1: Added a check for correct tag.
--
--!
package C460004_0 is

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

   procedure NewProc (X : in DDTag_Type);

   function CWFunc (X : Tag_Type'Class) return Tag_Type'Class;

end C460004_0;
