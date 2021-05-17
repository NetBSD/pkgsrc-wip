-- CXH30031.AM
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
-- OBJECTIVE
--     Check pragma Reviewable.
--     Check that pragma Reviewable is accepted as a configuration pragma.
--
-- TEST DESCRIPTION
--     This test checks that pragma Reviewable is processed as a
--     configuration pragma.  See CXH3001 for testing pragma Reviewable as
--     other than a configuration pragma.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         CXH30030.A
--      => CXH30031.AM
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Safety and Security Annex.
--
-- SPECIAL REQUIREMENTS
--      The implementation must process a configuration pragma which is not
--      part of any Compilation Unit; the method employed is implementation
--      defined.
--
--
-- CHANGE HISTORY:
--      26 OCT 95   SAIC   Initial version for 2.1
--      07 JUN 96   SAIC   Revised by reviewer request
--      03 NOV 96   SAIC   Documentation revision
--
--      03 NOV 96   Keith  Documentation revision
--      27 AUG 99   RLB    Removed result dependence on uninitialized object.
--      30 AUG 99   RLB    Repaired the above.
--
--!

  pragma Reviewable;

------------------------------------------------------------------- CXH3003

with Report;
with CXH3003_0.CXH3003_1;
procedure CXH30031 is
begin

  Report.Test("CXH3003", "Check pragma Reviewable as a configuration pragma");

  Block: declare
    A_Truth : Boolean;
    Message : String := Report.Ident_Str( "Bad value encountered" );
  begin
    begin
      A_Truth := Report.Ident_Bool( True ) or A_Truth;  -- not initialized
      if not A_Truth then
        Report.Comment ("True or Uninit = False");
        A_Truth := Report.Ident_Bool (True);
      else
        A_Truth := Report.Ident_Bool (True);
          -- We do this separately on each branch in order to insure that a
          -- clever optimizer can find out little about this value. Ident_Bool
          -- is supposed to be opaque to any optimizer.
      end if;
    exception
      when Constraint_Error | Program_Error =>
           -- Possible results of accessing an uninitialized object.
        A_Truth := Report.Ident_Bool (True);
    end;

    CXH3003_0.CXH3003_1.PT.Set( A_Truth );

    CXH3003_0.Global_Variable := A_Truth;

    CXH3003_0.CXH3003_1.TT.Release;  -- rendezvous with TT

    while CXH3003_0.CXH3003_1.TT'Callable loop  -- wait for TT to complete
      delay 1.0;
    end loop;

    if   not CXH3003_0.CXH3003_1.PT.Enquire
      or not CXH3003_0.Global_Variable then
      Report.Failed(Message);
    end if;

  end Block;

  Report.Result;

end CXH30031;
