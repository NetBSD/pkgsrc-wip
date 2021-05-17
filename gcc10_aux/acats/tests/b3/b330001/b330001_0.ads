-- B330001.A
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
--     Check that if a subtype indication of a variable object defines an
--     indefinite subtype, then there is an initialization. Check that if
--     the array type definition of a variable object defines an unconstrained
--     array subtype, then there is an initialization. Check that indefinite
--     subtypes may not be used as the subtype indication of a component
--     definition (in either an array or a record definition).
--
-- TEST DESCRIPTION:
--     Declare indefinite subtypes in a package specification.  An indefinite
--     subtype is either:
--         a) An unconstrained array subtype.
--         b) A subtype with unknown discriminants (this includes class-wide
--            types).
--         c) A subtype with unconstrained discriminants without defaults.
--
--     In the children (private and public) and the main program, verify that
--     errors are issued for object declarations without constraints or
--     explicit initializations.  Also verify that errors are issued for
--     type declarations which have indefinite subtype components.
--
--
-- CHANGE HISTORY:
--      19 Sep 95   SAIC    Initial prerelease version.
--      15 Apr 96   SAIC    Revised test for 2.1
--      20 Aug 01   RLB     Corrected error command for last subtest.
--
--!

package B330001_0 is

   subtype Sub_Type is Natural range 1 .. 4;

   type Uncons_Arr_Type is array                       -- Unconstrained array
     (Sub_Type range <>, Sub_Type range <>) of Integer;-- type.

   type Uncons_Rec_Type (Side : Sub_Type) is record    -- Unconstrained record
      Com : Uncons_Arr_Type (1 .. Side, 1 .. Side);    -- without defaulted
   end record;                                         -- discriminants.

   type Uncons_Tag_Type (Dimension : Sub_Type) is      -- Unconstrained tagged
     tagged record                                     -- type.
        Left  : Uncons_Rec_Type (Dimension);
        Right : Uncons_Rec_Type (Dimension);
     end record;

   type Cons_Tag_Type is tagged                         -- Constrained tagged
     record                                             -- type (used to get
        C : Boolean;                                    -- class-wide type).
     end record;

   type NUncons_Tag_Type is new Uncons_Tag_Type with
    record
       C : Boolean;
    end record;

   protected type Protected_Type (Disc : Integer) is
     procedure Do_Nothing;
   private
     Int : Integer := Disc;
   end Protected_Type;

   task type Task_Type (Disc : Integer) is
     entry Do_Nothing;
   private
     entry Hidden(1..Disc);
   end Task_Type;

   type FullViewIsIndefinite (<>) is new Cons_Tag_Type   -- Type with unknown
      with private;                                      -- discriminants.

   function Indef_Func (P : Sub_Type) return FullViewIsIndefinite;

   type FullViewIsDefinite (<>) is private;              -- Type with unknown
                                                         -- discriminants.

   function Def_Func   (P : Sub_Type) return FullViewIsDefinite;

private

   type FullViewIsIndefinite (Disc : Sub_Type) is new Cons_Tag_Type with
     record
        S : Sub_Type := Disc;
     end record;

   type FullViewIsDefinite   (Disc : Sub_Type := 2) is
     record
      S : Sub_Type := Disc;
   end record;

end B330001_0;
