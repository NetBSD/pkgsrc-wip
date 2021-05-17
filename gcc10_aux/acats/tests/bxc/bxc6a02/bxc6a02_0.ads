-- BXC6A02.A
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
--     Check that if a volatile object is used as an actual for a generic
--     formal object of mode in out, the type of the generic formal object
--     must be volatile.
--
--     Check that if the prefix of 'Access denotes a volatile object (including
--     a component), the designated type of the resulting access type must be
--     volatile.
--
-- TEST DESCRIPTION:
--     A volatile type is one to which a pragma Volatile or Atomic applies.
--
--     A volatile object is any of the following:
--
--        (1) An object to which a pragma Volatile applies.
--        (2) A component of an array to which a pragma Volatile_Components
--            applies.
--        (3) An object of a volatile type (i.e., a type to which a pragma
--            Volatile applies).
--        (4) An object to which a pragma Atomic applies.
--        (5) A component of an array to which a pragma Atomic_Components
--            applies.
--        (6) An object of a atomic type (i.e., a type to which a pragma
--            Atomic applies).
--        (7) A subcomponent of a volatile object.
--
--     This test attempts to use various volatile objects as actuals for
--     generic formal objects of mode in out, and verifies that such usages
--     are illegal if the type of the formal object is not volatile.
--
--     Additionally, the test uses several volatile objects as prefixes of
--     'Access, and verifies that such usages are illegal if the designated
--     type of the expected type of 'Access is not volatile.
--
-- TEST FILES:
--      This test consists of the following files:
--
--         FXC6A00.A
--      -> BXC6A02.A
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for implementations validating the
--      Systems Programming Annex.
--
-- PASS/FAIL CRITERIA:
--      An implementation may reject one or more of the pragmas Atomic and
--      Atomic_Components in this test if it cannot support indivisible reads
--      and updates for the specified object or type. If a pragma is rejected,
--      certain ERROR cases (as noted in the body of the test) need not be
--      reported as errors.
--
--
-- CHANGE HISTORY:
--      26 Jan 96   SAIC    Initial version for ACVC 2.1.
--      21 Feb 96   SAIC    Added Pass/Fail criteria.
--      25 Aug 96   SAIC    Removed task case. Changed Pass/Fail criterion and
--                          comments following certain error cases. Reworded
--                          comments following pragmas. Corrected prologue.
--      19 Feb 97   PWB.CTA Deleted cases where actual could not match formal
--      01 Jun 98   EDS     NonVolatile_Tagged type is volatile, and therefore
--                          changed "-- OK" lines to "-- ERROR:" lines.
--      27 Aug 99   RLB     Repaired foundation so NonVolatile_Tagged is really
--                          not volatile, and therefore reverted above changes.
--
--!

with FXC6A00;
package BXC6A02_0 is

   generic
      Formal_Object: in out FXC6A00.Volatile_Tagged;
   package Volatile_Tagged_Formal is end;

   generic
      Formal_Object: in out FXC6A00.Roman;
   package Roman_Formal is end;

end BXC6A02_0;
