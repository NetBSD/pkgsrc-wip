-- C432004.A
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
--      Check that the type of an extension aggregate may be derived from the
--      type of the ancestor part through multiple record extensions. Check
--      for ancestor parts that are subtype marks. Check that the type of the
--      ancestor part may be abstract.
--
-- TEST DESCRIPTION:
--      This test defines the following type hierarchies:
--
--                (A)                           (F)
--              Abstract                      Abstract
--           Tagged record                 Tagged private
--            /         \                   /          \
--           /          (C)               (G)           \
--         (B)        Abstract         Abstract         (H)
--       Record       private          record         Private
--      extension     extension        extension     extension
--          |             |                |             |
--         (D)           (E)              (I)           (J)
--       Record        Record           Record        Record
--      extension     extension        extension     extension
--
--      Extension aggregates for B, D, E, I, and J are constructed using each
--      of its ancestor types as the ancestor part (except for E and J, for
--      which only the immediate ancestor is used, since using A and F,
--      respectively, as the ancestor part would be illegal).
--
--      X1 : B := (A with ...);
--      X2 : D := (A with ...);         X5 : I := (F with ...);
--      X3 : D := (B with ...);         X6 : I := (G with ...);
--      X4 : E := (C with ...);         X7 : J := (H with ...);
--
--      For each assignment of an aggregate, the value of the target object is
--      checked to ensure that the proper values for each component were
--      assigned.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package C432004_0 is

   type Drawers is record
      Building : natural;
   end record;

   type Location is access Drawers;

   type Eras is (Precambrian, Paleozoic, Mesozoic, Cenozoic);

   type SampleType_A is abstract tagged record
      Era : Eras := Cenozoic;
      Loc : Location;
   end record;

   type SampleType_F is abstract tagged private;

   -- The following function is needed to verify the values of the
   -- private components.
   function TC_Correct_Result (Rec : SampleType_F'Class;
                               E   : Eras) return Boolean;

private
   type SampleType_F is abstract tagged record
      Era : Eras := Mesozoic;
   end record;

end C432004_0;
