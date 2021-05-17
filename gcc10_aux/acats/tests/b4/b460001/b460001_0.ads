-- B460001.A
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
--      Check that if the target type of a type conversion is a general access
--      type, the accessibility level of the operand type must not be
--      statically deeper than that of the target type.
--
--      Check for cases where the operand is:
--         (a) a stand-alone access object.
--         (b) a formal parameter.
--         (c) an access discriminant.
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the operand type must
--      be at the same or a less deep "nesting level" than the target type --
--      the operand type must "live" as long as the target type. Nesting levels
--      are the run-time nestings of masters: block statements; subprogram,
--      task, and entry bodies; and accept statements. Packages are invisible
--      to accessibility rules.
--
--      The accessibility level of the anonymous access type of an access
--      discriminant is that of the containing object.
--
--      This test declares general and pool-specific access types in various
--      packages and nested subprogram bodies, and verifies that a type
--      conversion to a general access type is illegal when the type of the
--      operand of a type conversion has a deeper accessibility level than
--      that of the target type, and legal otherwise. Pool-specific types are
--      used as operand types, since the operand type of a conversion to a
--      general access type may be pool-specific. Other operand types used are
--      general access-to-tagged types (including access-to-class-wide types).
--      Accessibility is checked in two contexts: the target is an actual
--      parameter; the target is a stand-alone access object.
--
--      The nesting structure is as follows:
--
--          - Library-level package
--         |                                (Level = 0)
--          - end package
--
--          - Main subprogram
--         |                                (Level = 1)
--         |     - Nested procedure
--         |    |                           (Level = 2)
--         |    |     - Nested procedure
--         |    |    |                      (Level = 3)
--         |    |    |  begin
--         |    |    |     *** Testing here
--         |    |     - end procedure
--         |    |  begin
--         |    |     *** Testing here
--         |     - end procedure
--         |  begin          
--         |     *** Testing here
--          - end Main subprogram
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      21 Nov 95   SAIC    ACVC 2.0.1 fixes: Corrected commentary.
--
--!

package B460001_0 is

   --
   -- Integer type, associated objects and access types:
   -- 

   type Obj_Type is new Integer range 0..1000;

   type GAccObj_L0 is access all Obj_Type;                      -- Level = 0.
   type PAccObj_L0 is access     Obj_Type;                      -- Level = 0.

   Obj   : aliased Obj_Type := 355;
   GSA_0 : GAccObj_L0;
   PSA_0 : PAccObj_L0;

   --
   -- Type with access discriminant:
   -- 

   type Acc_Disc (D : access Obj_Type := Obj'Access) is limited record
      Limited_Field : String(1..80);
   end record;

   AD_0 : Acc_Disc;

   --
   -- Tagged types, associated objects and access types:
   -- 

   type Tag_Type is tagged record 
      Field_1 : Obj_Type := 123;
      Field_2 : String(1..21) := "This is a tagged type";
   end record;

   type Der_Type is new Tag_Type with record 
      Field_3 : Natural := 598;
   end record;

   type GAccCls_L0 is access all Tag_Type'Class;                -- Level = 0.

   GSAC_0 : GAccCls_L0;


end B460001_0;
