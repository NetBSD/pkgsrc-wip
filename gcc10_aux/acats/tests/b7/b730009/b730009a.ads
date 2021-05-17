-- B730009.A
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
--*
-- OBJECTIVE:
--      Check that a tagged partial view can be synchronized if and only if
--      the completion is a synchronized type.
--
-- TEST DESCRIPTION:
--      We declare a variety of synchronized interfaces, and private extensions
--      from those interfaces, then make sure that completions are
--      either task types or protected types. Note that we try to avoid cases
--      where the declaration would be illegal for other reasons.
--
--      It is legal to declare a non-synchronized private extension of a
--      synchronized interface, but no completion can be legal (synchronized
--      interfaces can only be used in task, protected, interface, and private
--      extension declarations). In this case, we allow the error to reported
--      on either the private extension or on the completion.
--
--      This test is checking 7.3(7.2/2).
--
-- PASS/FAIL CRITERIA:
--     The test contains several lines marked POSSIBLE ERROR: [Setnn].
--     For each value of n, the implementation must detect one or more of
--     these possible errors. For instance, an error must be detected on
--     at least one of the lines labeled POSSIBLE ERROR: [Set1] for an
--     implementation to pass.
--
-- CHANGE HISTORY:
--      30 Dec 13   RLB     Created from similar test B730008.
--      23 Jan 15   RLB     Completion of Priv12 violated 7.3(10.1/3),
--                          added limited to repair that.
--
package B730009A is
   type L_Iface is limited interface;

   type Type_Implementing_L_IFace is limited new L_IFace with null record;

   type S_Iface is synchronized interface;

   type T_Iface is task interface;

   type P_Iface is protected interface;
end B730009A;
