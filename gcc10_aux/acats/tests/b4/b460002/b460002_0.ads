-- B460002.A
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
--      Check that if the target type of a type conversion is a general
--      access type, the accessibility level of the operand type must not
--      be statically deeper than that of the target type. Check for cases
--      where the type conversion occurs in the visible or private part of
--      an instance.
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the operand type must
--      be at the same or a less deep nesting level than the target type -- the
--      operand type must "live" as long as the target type. Nesting levels
--      are the run-time nestings of masters: block statements; subprogram,
--      task, and entry bodies; and accept statements. Packages are invisible
--      to accessibility rules.
--
--      Check access type conversions, using various combinations of operand
--      and target types, in both the visible and private parts of instances:
--
--      Target type        Operand type                Coverage           Part
--      ----------------------------------------------------------------------
--      Global to generic  Local to generic            Not covered
--              "          Global to generic           Not covered
--              "          Formal of generic           Not covered
--              "          Local derivative of formal  B460002_4.Target   Priv
--              "          Access discriminant         B460002_3.Target   Visi
--      Formal of generic  Local to generic            B460002_2.Target   Visi
--              "          Global to generic           Not covered
--              "          Formal of generic           B460002_5.Target   Visi
--              "          Local derivative of formal  Not covered
--              "          Access discriminant         B460002_6.Target   Priv
--      Local to generic   Local to generic            B460002_1.Target3  Priv
--              "          Global to generic           B460002_1.Target1  Visi
--              "          Formal of generic           B460002_1.Target4  Priv
--              "          Local derivative of formal  Not covered
--              "          Access discriminant         B460002_1.Target2  Visi
--
--      Include cases where the operand is a stand-alone access object, an
--      access discriminant, and a function call. Verify that an access
--      type conversion is illegal in an instance if the operand type has
--      a deeper accessibility level than the target type, and legal otherwise.
--
--
-- CHANGE HISTORY:
--      26 May 95   SAIC    Initial prerelease version.
--      01 May 96   Dianne  Added an instantiation using a derived access type.
--
--!

package B460002_0 is

   type Tagged_Type is tagged record
     I : Integer;
   end record;

   type External_Operand_Type_L0  is access all Tagged_Type;
   type External_Operand_Class_L0 is access all Tagged_Type'Class;

   type External_Target_Type_L0   is access all Tagged_Type;

   function Oper_Func return External_Operand_Class_L0;

   type Disc_Record_Type (D : access Tagged_Type'Class) is limited record
      B : Boolean;
   end record;

   Tag_Object : aliased Tagged_Type;
   Operand_L0 : External_Operand_Type_L0 := new Tagged_Type;
   AccDisc_L0 : Disc_Record_Type(Tag_Object'Access);

end B460002_0;
