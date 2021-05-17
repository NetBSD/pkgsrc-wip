-- C3A1002.A
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
--      Check for cases where the types are tagged records and task types.
--
-- TEST DESCRIPTION:
--      Declare two groups of incomplete types: one group with no discriminant 
--      part and one group with unknown discriminant part.  Both groups of 
--      incomplete types are completed with both explicit and inherited 
--      discriminants.  Discriminants for task types are declared with both 
--      default and non default values.  Discriminants for tagged types are 
--      only declared without default values.  
--      In the main program, verify that objects of both groups of incomplete 
--      types can be created by default values or by assignments.
--
--
-- CHANGE HISTORY:
--      23 Oct 95   SAIC    Initial prerelease version.
--      19 Oct 96   SAIC    ACVC 2.1: modified test description.  Initialized
--                          Int_Val.
--
--!

package C3A1002_0 is

   subtype Small_Int is Integer range 1 .. 15;

   type Enu_Type is (M, F);

   type Tag_Type is tagged         
     record                                          
        I : Small_Int := 1;
     end record;

   type NTag_Type (D : Small_Int) is new Tag_Type with
     record                                          
        S : String (1 .. D) := "Aloha";  
     end record;

   type Incomplete1;                               -- no discriminant

   type Incomplete2 (<>);                          -- unknown discriminant

   type Incomplete3;                               -- no discriminant

   type Incomplete4 (<>);                          -- unknown discriminant

   type Incomplete5;                               -- no discriminant

   type Incomplete6 (<>);                          -- unknown discriminant

   type Incomplete1 (D1 : Enu_Type) is tagged      -- no discriminant/  
     record                                        -- explicit discriminant
        case D1 is
           when M => MInteger : Small_Int := 9;
           when F => FInteger : Small_Int := 8;
        end case;
     end record;

   type Incomplete2 (D2 : Small_Int) is new       -- unknown discriminant/
     Incomplete1 (D1 => F) with record            -- explicit discriminant
        ID : String (1 .. D2) := "ACVC95";
     end record;

   type Incomplete3 is new                         -- no discriminant/
     NTag_Type with record                         -- inherited discriminant
        E : Enu_Type := M;
     end record;

   type Incomplete4 is new                         -- unknown discriminant/
     NTag_Type (D => 3) with record                -- inherited discriminant
        E : Enu_Type := F;
     end record;

   task type Incomplete5 (D5 : Enu_Type) is      -- no discriminant/
      entry Read_Disc (P : out Enu_Type);        -- explicit discriminant
   end Incomplete5;

   task type Incomplete6 
     (D6 : Small_Int := 4) is                    -- unknown discriminant/
      entry Read_Int (P : out Small_Int);        -- explicit discriminant
   end Incomplete6;

end C3A1002_0;
