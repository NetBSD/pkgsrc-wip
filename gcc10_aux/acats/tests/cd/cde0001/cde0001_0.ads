-- CDE0001.A
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
--      Check that the following names can be used in the declaration of a
--      generic formal parameter (object, array type, or access type) without 
--      causing freezing of the named type:
--        (1) The name of a private type,
--        (2) A name that denotes a subtype of a private type, and
--        (3) A name that denotes a composite type with a subcomponent of a
--           private type (or subtype).
--      Check for untagged and tagged types.
--
-- TEST DESCRIPTION:
--      This transition test defines private and limited private types,
--      subtypes of these private types, records and arrays of both types and
--      subtypes, a tagged type and a private extension.
--      This test creates examples where the above types are used in the 
--      definition of several generic formal type parameters (object, array 
--      type, or access type) in both visible and private parts.  These 
--      visible and private generic packages are instantiated in the body of 
--      the public child and the private child, respectively.  
--      The main program utilizes the functions declared in the public child
--      to verify results of the instantiations.
--
--      Inspired by B74103F.ADA.
--
--
-- CHANGE HISTORY:
--      12 Mar 96   SAIC    Initial version for ACVC 2.1.
--      05 Oct 96   SAIC    ACVC 2.1: Added pragma Elaborate for CDE0001.
--      21 Nov 98   RLB     Added pragma Elaborate for CDE0001 to CDE0001_3.
--!

package CDE0001_0 is

   subtype Small_Int is Integer range 1 .. 2;

   type Private_Type    is private;
   type Limited_Private is limited private;

   subtype Private_Subtype         is Private_Type;
   subtype Limited_Private_Subtype is Limited_Private;

   type Array_Of_LP_Subtype is array (1..2) of Limited_Private_Subtype;

   type Rec_Of_Limited_Private is
     record
        C1 : Limited_Private;
     end record;

   type Rec_Of_Private_SubType is 
     record
        C1 : Private_SubType;
     end record;

   type Tag_Type is tagged
     record
        C1 : Small_Int;
     end record;

   type New_TagType is new Tag_Type with private;

   generic               

      Formal_Obj01 : in out Private_Type;              -- Formal objects defined
      Formal_Obj02 : in out Limited_Private;           -- by names of private 
      Formal_Obj03 : in out Private_Subtype;           -- types, names that
      Formal_Obj04 : in out Limited_Private_Subtype;   -- denotes subtypes of 
      Formal_Obj05 : in out New_TagType;               -- the private types.

   package CDE0001_1 is
      procedure Assign_Objects;

   end CDE0001_1;
   
private

   generic               
      -- Formal array types of a private type, a composite type with a 
      -- subcomponent of a private type.

      type Formal_Arr01 is array (Small_Int) of Private_Type;
      type Formal_Arr02 is array (Small_Int) of Rec_Of_Limited_Private;

      -- Formal access types of composite types with a subcomponent of 
      -- a private subtype.

      type Formal_Acc01 is access Rec_Of_Private_Subtype;
      type Formal_Acc02 is access Array_Of_LP_Subtype;

   package CDE0001_2 is

      procedure Assign_Arrays (P1 : out Formal_Arr01;
                               P2 : out Formal_Arr02);

      procedure Assign_Access (P1 : out Formal_Acc01;
                               P2 : out Formal_Acc02);

   end CDE0001_2;

   ----------------------------------------------------------
   type Private_Type    is range 1 .. 10;
   type Limited_Private is (Eh, Bee, Sea, Dee);
   type New_TagType     is new Tag_Type with 
     record
        C2 : Private_Type;
     end record;

end CDE0001_0;
