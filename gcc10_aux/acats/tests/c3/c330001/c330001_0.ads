-- C330001.A 
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
--      Check that a variable object of an indefinite type is properly 
--      initialized/constrained by an initial value assignment that is 
--      a) an aggregate, b) a function, or c) an object.  Check that objects 
--      of the above types do not need explicit constraints if they have 
--      initial values.  
--                    
-- TEST DESCRIPTION: 
--      An indefinite subtype is either: 
--         a) An unconstrained array subtype. 
--         b) A subtype with unknown discriminants.
--         c) A subtype with unconstrained discriminants without defaults. 
-- 
--      Declare several indefinite types in a parent package specification.  
--      In the private part, complete one type with a discriminant without 
--      default (indefinite) and the other with a default discriminant 
--      (definite).  Declare objects of both indefinite and definite subtypes 
--      in children (private and public) with initialization expressions.  The 
--      test verifies all values of the objects.  It also verifies that
--      Constraint_Error is raised if an attempt is made to change the 
--      discriminants of the objects of the indefinite subtypes.        
-- 
-- 
-- CHANGE HISTORY: 
--      15 Jan 95   SAIC    Initial version for ACVC 2.1
--      25 Jul 96   SAIC    Modified test description. Deleted use C330001_0.
--      20 Nov 98   RLB     Added Elaborate pragmas to avoid problems
--                          with an unconventional, but legal, elaboration
--                          order.
--!

package C330001_0 is  

   subtype Sub_Type is Integer range 1 .. 20;

   type Tag_W_Disc (D : Sub_Type) is tagged record
       C1 :  String (1 .. D);
   end record;

   -- Indefinite type declarations.

   type FullViewDefinite_Unknown_Disc (<>) is private;           

   type Indefinite_No_Disc is array (Positive range <>) of Integer;

   type Indefinite_Tag_W_Disc (D : Sub_Type) is tagged
     record
        C1 : Boolean := False;
     end record;

   type Indefinite_New_W_Disc (ND : Sub_Type) is new 
     Indefinite_Tag_W_Disc (ND) with record
        C2 : Integer := 9;
     end record;

   type Indefinite_W_Inherit_Disc_1 is new Tag_W_Disc with 
     record     
        S : Sub_Type := 18;
     end record;
                                                    
   type Indefinite_W_Inherit_Disc_2 is     
     new Tag_W_Disc with private;                                       
                                                                           
   function Indef_Func_1 return FullViewDefinite_Unknown_Disc;

   function Indef_Func_2 (P : Sub_Type) return Indefinite_W_Inherit_Disc_2;

private

   type FullViewDefinite_Unknown_Disc (D : Sub_Type := 2) is
      record     
        S : String (1 .. D) := "Hi";
      end record;

   type Indefinite_W_Inherit_Disc_2 is new Tag_W_Disc with 
      record     
        S : Sub_Type;
      end record;

end C330001_0;
