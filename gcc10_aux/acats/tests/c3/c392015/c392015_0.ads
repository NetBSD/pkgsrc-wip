-- C392015
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
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--    Check that default expressions of inherited dispatching routines
--    dispatch properly. (From AI95-00239.)
--
-- CHANGE HISTORY:
--    20 Jul 2000   RLB   Created test for AI-239.
--    25 Apr 2007   RLB   Updated test for ACATS 3.0.
--    21 Sep 2007   RLB   Fixed the test results to allow parameters to
--                        be evaluated in an arbitrary order.
--
--!

package C392015_0 is

    type T0 is tagged null record;

    function Fa return T0;

    function Fc return T0'Class;

    procedure Pa (P : in T0 := Fa);

    procedure Pb (P : in T0 := Fa);

    procedure Pc (Param1, Param2 : in T0 := Fa);

    function Fd (P : in T0 := Fa) return T0'Class;

end C392015_0;
