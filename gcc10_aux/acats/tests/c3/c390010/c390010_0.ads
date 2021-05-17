-- C390010.A
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
--     Check that if S is a subtype of a tagged type T, and if S is
--     constrained, then the allowable values of S'Class are only those
--     that, when converted to T, belong to S.
--
-- TEST DESCRIPTION:
--      This test defines a small tagged hierarchy of discriminated tagged
--      records, and constrained subtypes of those tagged record types.
--      It then uses access to the classwide of the constrained subtype
--      to check the objective.
--
--
-- CHANGE HISTORY:
--      09 APR 96   SAIC   Initial version
--      03 NOV 96   SAIC   Revised for 2.1 release
--      31 DEC 97   EDS    Restored use of intermediate access variable
--                         to eliminate raising of Program_Error
--      13 SEP 99   RLB    Repaired previous change to avoid premature
--                         subtype check.
--      28 JUN 02   RLB    Added pragma Elaborate_All (Report);.
--!

----------------------------------------------------------------- C390010_0

with Report; pragma Elaborate_All (Report);
package C390010_0 is

  -- the defined subprograms will allow checking the placement of
  -- constraint_checks

  -- define a discriminated tagged type, and a constrained subtype of
  -- that type:

  type Discr_Tag_Record( Disc: Boolean ) is tagged record
    FieldA : Character := 'A';
    case Disc is
      when True  => FieldB : Character := 'B';
      when False => FieldC : Character := 'C';
    end case;
  end record;

  procedure Dispatching_Op( DTO : in out Discr_Tag_Record );

  Authentic : Boolean := Report.Ident_Bool( True );

  subtype True_Record is Discr_Tag_Record( Authentic );


  -- derive a type, "passing through" one discriminant, adding one
  -- discriminant, and a constrained subtype of THAT type:

  type Derived_Record( Disc1, Disc2: Boolean ) is
    new Discr_Tag_Record( Disc1 ) with record
      FieldD : Character := 'D';
      case Disc2 is
        when True  => FieldE : Character := 'E';
        when False => FieldF : Character := 'F';
      end case;
    end record;

  procedure Dispatching_Op( DR : in out Derived_Record );

  subtype True_True_Derived is Derived_Record( Authentic, Authentic );


  -- now, define an access to classwide type, using the classwide from the
  -- constrained subtype of the root (or parent) type:

  type Subtype_Parent_Class_Access is access all True_Record'Class;
  type Parent_Class_Access is access all Discr_Tag_Record'Class;

  procedure PCW_Op( SPCA : in Subtype_Parent_Class_Access );

end C390010_0;
