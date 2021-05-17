-- C330002.A 
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
--      Check that if a subtype indication of a variable object defines an  
--      indefinite subtype, then there is an initialization expression. 
--      Check that the object remains so constrained throughout its lifetime. 
--      Check for cases of tagged record, arrays and generic formal type. 
--                    
-- TEST DESCRIPTION: 
--      An indefinite subtype is either: 
--         a) An unconstrained array subtype. 
--         b) A subtype with unknown discriminants (this includes class-wide 
--            types). 
--         c) A subtype with unconstrained discriminants without defaults. 
-- 
--      Declare tagged types with unconstrained discriminants without 
--      defaults.  Declare an unconstrained array.  Declare a generic formal
--      type with an unknown discriminant and a formal object of this type.  
--      In the generic package, declare an object of the formal type using 
--      the formal object as its initial value.  In the main program, 
--      declare objects of tagged types.  Instantiate the generic package.  
--      The test checks that Constraint_Error is raised if an attempt is 
--      made to change bounds as well as discriminants of the objects of the 
--      indefinite subtypes.  
-- 
-- 
-- CHANGE HISTORY: 
--      01 Nov 95   SAIC    Initial prerelease version. 
--      27 Jul 96   SAIC    Modified test description & Report.Test.  Added
--                          code to prevent dead variable optimization.
-- 
--!

package C330002_0 is  

   subtype Small_Num is Integer range 1 .. 20;

   -- Types with unconstrained discriminants without defaults.      

   type Tag_Type (Disc : Small_Num) is tagged         
     record                                          
       S : String (1 .. Disc);                       
     end record;

   function  Tag_Value return Tag_Type;

   procedure Assign_Tag (A : out Tag_Type);

   procedure Avoid_Optimization_and_Fail (P : Tag_Type; Msg : String);

   ---------------------------------------------------------------------
   -- An unconstrained array type.

   type Array_Type is array (Positive range <>) of Integer;

   function  Array_Value return Array_Type;

   procedure Assign_Array (A : out Array_Type);

   ---------------------------------------------------------------------
   generic
      -- Type with an unknown discriminant.
      type Formal_Type (<>) is private;
      FT_Obj  : Formal_Type;
   package Gen is
      Gen_Obj : Formal_Type := FT_Obj;
   end Gen;

end C330002_0;
