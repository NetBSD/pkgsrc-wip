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

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body CXH3003_0.CXH3003_1 is

  protected body PT is

    entry Set(Switch: Boolean) when True is
    begin
      Toggle := Switch;
    end Set;

    function Enquire return Boolean is
    begin
      return Toggle;
    end Enquire;

  end PT;

  task body TT is
  begin
    loop
      accept Release;
      exit when Global_Variable;
    end loop;
  end TT;

 -- TT activation

end CXH3003_0.CXH3003_1;
