-- BC51C01.A
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
--      Check that the actual type passed to an abstract generic formal
--      derived type may be either abstract or non-abstract, as may
--      record and private extensions of the formal type. Check that,
--      for a non-abstract type derived from an abstract formal derived type,
--      all abstract primitive subprograms inherited from the actual type must
--      be overridden in the instance.
--
-- TEST DESCRIPTION:
--      The actual corresponding to an abstract formal type may be either
--      abstract or non-abstract.
--
--      Record and private extensions of the formal derived type may be
--      either abstract or non-abstract, but for non-abstract extensions the
--      abstract primitive subprograms inherited from the formal type (which,
--      in turn, have been inherited from the ancestor type) must be
--      overridden in the generic.
--
--      Additionally, within the instance, all abstract primitive subprograms
--      of the *actual type* must be overridden for non-abstract extensions,
--      even those which are not primitive subprograms of the ancestor type.
--
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC51C00.A
--      -> BC51C01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      03 Nov 95   SAIC    ACVC 2.0.1 fixes: Removed redundant instance
--                          cases, updated related commentary.
--      10 Apr 96   SAIC    ACVC 2.1 fixes: Moved subprograms Proc and New_Proc
--                          in PriExt_Overrides_All from private to visible
--                          part. Added Proc and New_Proc to private
--                          part of PriExt_Overrides_Inherited. Added
--                          commentary.
--      21 Nov 19   RLB     Added error location indicators.
--!

with FC51C00;
package BC51C01_0 is

-- Check that both abstract and non-abstract actual types may be passed to
-- an abstract formal derived type. Check for formal derived types with both
-- abstract and non-abstract ancestor types.
--
-- Check that record and private extensions of an abstract formal derived
-- type may be abstract.

--
-- Generic formal type has non-abstract ancestor type:
--

   generic
      type Concrete_Anc is abstract new FC51C00.Concrete_Root with private;
   package Concrete_Ancestor is
      type Rec_Ext  is abstract new Concrete_Anc with null record; -- OK. {7;1}
      type Priv_Ext is abstract new Concrete_Anc with private;     -- OK. {7;1}
   private
      type Priv_Ext is abstract new Concrete_Anc with null record; -- OK. {7;1}
   end Concrete_Ancestor;


   package Concrete_Actual_A is new Concrete_Ancestor
     (FC51C00.Concrete_Root);                                 -- OK.    {1:4;1}

   package Abstract_Actual_A is new Concrete_Ancestor
     (FC51C00.Abstract_Child);                                -- OK.    {1:4;1}


--
-- Generic formal type has abstract ancestor type:
--

   generic
      type Abstract_Anc is abstract new FC51C00.Abstract_Child with private;
   package Abstract_Ancestor is
      type Rec_Ext  is abstract new Abstract_Anc with null record; -- OK. {7;1}
      type Priv_Ext is abstract new Abstract_Anc with private;     -- OK. {7;1}
   private
      type Priv_Ext is abstract new Abstract_Anc with null record; -- OK. {7;1}
   end Abstract_Ancestor;


   package Abstract_Actual_B is new Abstract_Ancestor
     (FC51C00.Abstract_Child);                                -- OK.    {1:4;1}

   package Concrete_Actual_B is new Abstract_Ancestor
     (FC51C00.Concrete_GrandChild);                           -- OK.    {1:4;1}


end BC51C01_0;
