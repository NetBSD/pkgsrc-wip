-- C760A02.A
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
--*
--
-- OBJECTIVE:
--     Check that no separate anonymous object is used for a function call
--     initializing an object of an immutably limited type.
--
-- TEST DESCRIPTION:
--     We initialize various limited objects with aggregates that contain
--     a special checking component. This component records the operations
--     performed on it, in particular whether any assignment occurs.
--     This allows us to check for the visible semantic effects of
--     an anonymous object: the extra assignment operations that are required.
--
--     The calls to Use_It are intended to emulate usage of the object and
--     are designed to ensure that the objects cannot be optimized away.
--
--     We put the functions into a separate package to emulate typical usage.
--
--     The test also checks that limited aggregates in return statements are
--     built-in-place. If test C760A01 fails, this test will also fail as
--     it uses similar aggregates.
--
-- CHANGE HISTORY:
--      15 Mar 18   RLB   Created test from C760A01.
--
--!

with F760A00.Child;
package C760A02A is

   function Func_Lim_Rec (Int : in Integer) return F760A00.Lim_Rec;

   function Func_Lim_Comp (Int : in Integer) return F760A00.Lim_Comp;

   function Func_Lim_Array (Int : in Integer) return F760A00.Lim_Array;

   function Func_Lim_Ext (Int : in Integer) return F760A00.Child.Lim_Ext;

end C760A02A;
