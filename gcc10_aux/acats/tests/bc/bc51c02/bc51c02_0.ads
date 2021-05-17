-- BC51C02.A
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
--      private type may be either abstract or non-abstract, as may
--      record and private extensions of the formal type. Check that,
--      for a non-abstract type derived from an abstract formal private type,
--      all abstract primitive subprograms inherited from the actual type must
--      be overridden in the instance.
--
-- TEST DESCRIPTION:
--      The actual corresponding to an abstract formal type may be either
--      abstract or non-abstract. Record and private extensions of the formal
--      private type may be either abstract or non-abstract.
--
--      In an instance, all abstract primitive subprograms of the actual
--      type must be overridden for non-abstract extensions, as well as
--      any functions with a controlling result if the extensions are not
--      null extensions.
--
-- TEST FILES:
--      This test consists of the following files:
--
--         FC51C00.A
--      -> BC51C02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      04 Mar 96   SAIC    ACVC 2.0.1 fixes: Moved all subprograms in
--                          PriExt_Overrides_Explicit and PriExt_Overrides_All
--                          from private to visible part. Added Func to private
--                          part of PriExt_Overrides_Explicit. Added
--                          commentary.
--      11 Aug 96   SAIC    ACVC 2.1: Updated prologue. Corrected position of
--                          ERROR comments.
--      01 Jun 98   EDS     Remove Function Func from private part of package
--                          PriExt_Overrides_Explicit.
--      22 Mar 07   RLB     Corrected to avoid problems with 3.9.3(4/2);
--                          updated terminology.
--      21 Nov 19   RLB     Added error location indicators.
--!

with FC51C00;
package BC51C02_0 is

-- Check that both abstract and non-abstract actual types may be passed to
-- an abstract formal private type.
--
-- Check that record and private extensions of an abstract formal private
-- type may be abstract.

   generic
      type Formal_Private is abstract tagged private;
   package Formal_Private_Parm is
      type Rec_Ext  is abstract new Formal_Private with
        record
          B : Boolean;
        end record;                                              -- OK. {3:7;1}
      type Priv_Ext is abstract new Formal_Private with private; -- OK. {7;1}
   private
      type Priv_Ext is abstract new Formal_Private with
        record
          B : Boolean;
        end record;                                              -- OK. {3:7;1}
   end Formal_Private_Parm;


   package Concrete_Actual is new Formal_Private_Parm
     (FC51C00.Concrete_Root);                                    -- OK. {1:4;1}

   package Abstract_Actual is new Formal_Private_Parm
     (FC51C00.Abstract_Child);                                   -- OK. {1:4;1}


end BC51C02_0;
