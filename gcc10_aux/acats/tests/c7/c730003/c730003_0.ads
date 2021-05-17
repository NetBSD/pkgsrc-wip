-- C730003.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687 and
--     F08630-91-C-0015, the U.S. Government obtained unlimited rights in the
--     software and documentation contained herein.  Unlimited rights are
--     defined in DFAR 252.227-7013(a)(19).  By making this public release,
--     the Government intends to confer upon all recipients unlimited rights
--     equal to those held by the Government.  These rights include rights to
--     use, duplicate, release or disclose the released technical data and
--     computer software in whole or in part, in any manner and for any purpose
--     whatsoever, and to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--      Check that the characteristics of a type derived from a private
--      extension (outside the scope of the full view) are those defined by
--      the partial view of the private extension.
--      In particular, check that a component of the derived type may be
--      explicitly declared with the same name as a component declared for
--      the full view of the private extension.
--      Check that a component defined in the private extension of a type
--      may be updated through a view conversion of a type derived from
--      the type.
--
-- TEST DESCRIPTION:
--      Consider:
--
--      package Parent is
--         type T is tagged record
--            ...
--         end record;
--
--         type DT is new T with private;
--         procedure Op1 (P: in out DT);
--
--      private
--         type DT is new T with record
--            Y: ...;                                             -- (A)
--         end record;
--      end Parent;
--
--      package body Parent is
--         function Op1 (P: in DT) return ... is
--         begin
--            return P.Y;
--         end Op1;
--      end Parent;
--
--      package Unrelated is
--         type Intermediate is new DT with record
--            Y: ...;  -- Note: same name as component of         -- (B)
--                     --       parent's full view.
--         end record;
--      end Unrelated;
--
--      package Parent.Child is
--         type DDT is new Intermediate with null record;
--         -- Implicit declared Op1 (P.DDT);                      -- (C)
--
--         procedure Op2 (P: in out DDT);
--      end Parent.Child;
--
--      package body Parent.Child is
--         procedure Op2 (P: in out DDT) is
--            Obj : DT renames DT(P);
--         begin
--            ...
--            P.Y := ...;      -- Updates DDT's Y.                -- (D)
--            DT(P).Y := ...;  -- Updates DT's Y.                 -- (E)
--            Obj.Y := ...;    -- Updates DT's Y.                 -- (F)
--         end Op2;
--      end Parent.Child;
--
--      Types DT and DDT both declare a component Y at (A) and (B),
--      respectively. The component Y of the full view of DT is not visible
--      at the place where DDT is declared. Therefore, it is invisible for
--      all views of DDT (although it still exists for objects of DDT), and
--      it is legal to declare another component for DDT with the same name.
--
--      DDT inherits the primitive subprogram Op1 from DT at (C). Op1 returns
--      the component Y; for calls with an operand of type DDT, Op1 returns
--      the Y inherited from DT, not the new Y explicitly declared for DDT,
--      even though the inherited Y is not visible for any view of DDT.
--
--      Within the body of Op2, the assignment statement at (D) updates the
--      Y explicitly declared for DDT. At (E) and (F), however, a view
--      conversion denotes a new view of P as an object of type DT, which
--      enables access to the Y from the full view of DT. Thus, the
--      assignment statements at (E) and (F) update the (invisible) Y from DT.
--
--      Note that the above analysis would be wrong if the new component Y
--      were declared directly in Child.  In that case, the two same-named
--      components would be illegal -- see AI-150.
--
--
-- CHANGE HISTORY:
--      06 Dec 1994   SAIC    ACVC 2.0
--      29 JUN 1999   RAD     Declare same-named component in an
--                            unrelated package -- see AI-150.
--
--!

package C730003_0 is

   type Suit_Kind is (Clubs, Diamonds, Hearts, Spades);
   type Face_Kind is (Up, Down);

   type Playing_Card is tagged record
      Face: Face_Kind;
      Suit: Suit_Kind;
   end record;

   procedure Turn_Over_Card (Card : in out Playing_Card);

   type Disp_Card is new Playing_Card with private;

   subtype ASCII_Representation is Natural range 1..14;

   function Get_Private_View (A_Card : Disp_Card) return ASCII_Representation;

private

   type Disp_Card is new Playing_Card with record
      View: ASCII_Representation;                                       -- (A)
   end record;

end C730003_0;
