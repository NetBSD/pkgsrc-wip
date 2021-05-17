-- B430001.A
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
--      Check that an aggregate may not be of a class-wide type.
--
--      Check that "null record" may appear as a record component association
--      list in record aggregates and extension aggregates. Check that if no
--      components are needed in a record component association list,
--      "null record" must appear, and that if components are needed, "null
--      record" must not appear.
--
-- TEST DESCRIPTION:
--      Attempt to use aggregates of a tagged type in contexts where the
--      expected type is class-wide. All such cases should be rejected.
--
--      Check that "null record" is legal as a component association list
--      in record aggregates and extension aggregates. Check that it must
--      appear if a component association list is required and there
--      are no needed components.
--
--
-- CHANGE HISTORY:
--      19 Jul 95   SAIC    Initial prerelease version.
--      10 May 96   SAIC    Modified Y6 case and deleted Y8 case.
--      26 Feb 97   PWB.CTA Deleted checks not meeting the objective
--!

package B430001_0 is

   type Tag_Null is tagged null record;

   type Tag_Type is tagged record
      Int1 : Integer := 0;
      Int2 : Integer := 10;
   end record;

   procedure Op (P : Tag_Type);

   type NewTag_W_Null is new Tag_Type with null record;

   type NewTag_Type is new Tag_Type with record
      Int3 : Integer := 20;
   end record;

   type NNewTag_W_Null is new NewTag_W_Null with record
      Str : String (1 .. 2) := "Hi";
   end record;

   function CW_Func return Tag_Type'Class;

end B430001_0;
