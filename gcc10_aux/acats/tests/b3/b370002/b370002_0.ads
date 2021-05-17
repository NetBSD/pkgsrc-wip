-- B370002.A
--
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
--      Check that for derived types with known discriminant parts the
--      parent subtype must be constrained; if the parent type is not
--      tagged, each discriminant of the new type must be used in the
--      constraint defining the parent subtype; and, if a discriminant is
--      used in the constraint defining the parent subtype, the subtype of
--      that discriminant must be statically compatible with the subtype
--      of the corresponding parent discriminant.
--
-- TEST DESCRIPTION:
--      Declares several discriminated record types, attempts to derive
--      from them violating the rules for deriving from discriminated
--      types.  This test attempts to make all the violations that typify
--      user errors.
--
--
--
-- CHANGE HISTORY:
--      02 MAY 95   SAIC    Initial version
--      24 JUL 95   SAIC    Review Commentary Incorporated version
--      26 FEB 97   PWB.CTA Removed declarations with discriminant errors
--!

package B370002_0 is

  type Color is (Red, Orange, Yellow, Green, Blue, Indigo, Ultra);

  type Unconstrained_Array is array(Positive range <>) of Character;

  type Unconstrained_Record( Shade: Color := Color'First ) is
    record
      Invariant_Part: Integer;
      case Shade is
        when Red..Indigo => Variant_Part : Boolean := True;
        when Ultra     => null;
      end case;
    end record;

  subtype Large is Natural range 0..2**13;

  type Multiple_Unconstrained_Record( Shade: Color := Color'First;
                                      The_Size: Large := 0 ) is
    record
      Invariant_Part : Integer;
      Size_Variant   : Unconstrained_Array(1..The_Size);
      case Shade is
        when Red..Indigo => Variant_Part : Boolean := True;
        when Ultra     => null;
      end case;
    end record;

  -- there is no such thing as an unconstrained tagged record...

  type Constrained_Tagged_Record( Shade: Color ) is
    tagged record
      Invariant_Part: Integer;
      case Shade is
        when Red..Indigo => Variant_Part : Boolean := True;
        when Ultra     => null;
      end case;
    end record;

  task type Discriminated_Task( Identity: Color := Color'First );

  protected type
    Discriminated_Protected( Identity: Color := Color'Last ) is
      entry Something_For_Someone;  
      procedure Nothing_For_No_one;
    end Discriminated_Protected;

  function Color_Last return Color;

end B370002_0;
