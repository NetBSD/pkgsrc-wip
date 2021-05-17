-- BC60004.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--      Check that every call on an formal abstract subprogram is a dispatching
--      call.
--
-- TEST DESCRIPTION:
--      This means that a call on a formal abstract subprogram has to be
--      dynamically tagged. Unlike a normal abstract subprogram, it's
--      possible for an object of the controlling type of a formal
--      abstract subprogram to exist, so this rule can reject sensible-looking
--      calls.
--
--      We test statically tagged calls, dynamically tagged calls,
--      tag-indeterminate calls where the tag is determined elsewhere, and
--      tag-indeterminate calls where the tag defaults to the controlling type.
--
-- CHANGE HISTORY:
--      27 May 2015   RLB   Created test.

package BC60004_A is

    type Root is tagged private;

    procedure Sink1 (P : in Root);

    procedure Sink2 (Left, Right : in Root);

private
    type Root is tagged null record;
end BC60004_A;
