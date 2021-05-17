-- C3A1001.A
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
--      Check that the full type completing a type with no discriminant part
--      or an unknown discriminant part may have explicitly declared or
--      inherited discriminants.
--      Check for cases where the types are records and protected types.
--
-- TEST DESCRIPTION:
--      Declare two groups of incomplete types: one group with no discriminant 
--      part and one group with unknown discriminant part.  Both groups of 
--      incomplete types are completed with both explicit and inherited 
--      discriminants.  Discriminants for record and protected types are 
--      declared with default and non default values.
--      In the main program, verify that objects of both groups of incomplete 
--      types can be created by default values or by assignments.
--
--
-- CHANGE HISTORY:
--      11 Oct 95   SAIC    Initial prerelease version.
--      11 Nov 96   SAIC    Revised for version 2.1.
--
--!

package C3A1001_0 is

   type Incomplete1 (<>);                          -- unknown discriminant

   type Incomplete2;                               -- no discriminant

   type Incomplete3 (<>);                          -- unknown discriminant

   type Incomplete4;                               -- no discriminant

   type Incomplete5 (<>);                          -- unknown discriminant

   type Incomplete6;                               -- no discriminant

   type Incomplete8;                               -- no discriminant

   subtype Small_Int is Integer range 1 .. 10;

   type Enu_Type is (M, F);

   type Incomplete1 (Disc : Enu_Type) is           -- unknown discriminant/
     record                                        -- explicit discriminant 
        case Disc is
           when M => MInteger : Small_Int := 3;
           when F => FInteger : Small_Int := 8;
        end case;
     end record;

   type Incomplete2 (Disc : Small_Int := 8) is     -- no discriminant/  
     record                                        -- explicit discriminant 
        ID : String (1 .. Disc) := "Plymouth";
     end record;

   type Incomplete3 is new Incomplete2;            -- unknown discriminant/
                                                   -- inherited discriminant

   type Incomplete4 is new Incomplete2;            -- no discriminant/  
                                                   -- inherited discriminant   
                                                   
   protected type Incomplete5                      -- unknown discriminant/
     (Disc : Enu_Type) is                          -- explicit discriminant
        function Get_Priv_Val return Enu_Type;     
   private
      Enu_Obj : Enu_Type := Disc;
   end Incomplete5;    

   protected type Incomplete6                      -- no discriminant/  
     (Disc : Small_Int := 1) is                    -- explicit discriminant
        function Get_Priv_Val return Small_Int;    -- with default
   private
      Num : Small_Int := Disc;
   end Incomplete6;

   type Incomplete8 (Disc : Small_Int) is          -- no discriminant/  
     record                                        -- explicit discriminant
       Str : String (1 .. Disc);                   -- no default
     end record;

   type Incomplete9 is new Incomplete8;

   function Return_String (S : String) return String;

end C3A1001_0;
