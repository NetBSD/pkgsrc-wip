-- CC30003.A
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
--     Check that, for a type extension derived from a formal tagged private
--     type, a whole new set of primitive subprograms is declared for use
--     outside of the instance. Check that primitive subprograms of the
--     type extension can override those inherited from the actual type
--     in the instance.

-- TEST DESCRIPTION:
--     The test objective echoes the wording of 12.3(16).
--
--     We create a mix-in generic that can extend any tagged type with
--     counting operations. We then use this generic to extend various
--     tagged types (including some that have these operations), and
--     finally, make a number of statically-bound and dispatching calls
--     to the operations.
--
--     This test differs from existing (as of August 2008) ACATS tests
--     in three ways:
--     (1) Most of the existing tests either inherit primitive operations
--     from the actual (and sometimes the formal) type OR have explicit
--     primitive operations. This test both inherits and have explicit
--     primitive operations, which is far more likely for a real mix-in
--     generic.
--     (2) This mix-in uses a generic formal tagged private type
--     rather than the more limiting generic formal tagged derived type.
--     Both occur in practice, so both should be tested.
--     (3) There are few (if any) dispatching calls in the existing tests.
--     We test them both inside and outside the generic unit.
--
--     The tagged type hierarchy is loosely based on the one from the
--     Ada 2005 Rationale. (See
--     http://www.adaic.com/standards/05rat/html/Rat-2-3.html).
--     Object <- Right_Triangle <- Counted_Triangle_Inst.Counted_Type
--       ^- Rectangle <- Counted_Rectangle_Inst.Counted_Type <- Counted_Square
--
-- CHANGE HISTORY:
--     28 Aug 2008 RLB Created test for RRS.
--     29 Aug 2008 RLB Converted test to ACATS test.
--     13 Mar 2015 RLB Eliminated overlong lines and tab characters.
--
generic
   type Base_Type is tagged private;
package CC30003_0 is

   type Counted_Type is new Base_Type with record
      Count : Natural := 0;
   end record;
   -- In the instance, inherits primitive subprograms of the actual.

   procedure Clear (Obj : in out Counted_Type);
      -- Clear the count of Obj.

   procedure Bump (Obj : in out Counted_Type);
      -- Increment the count of Obj.

   function Count (Obj : Counted_Type) return Natural;
      -- Return the count of Obj.

   procedure Double_Bump (Obj : in out Counted_Type'Class);
      -- Increment the count of Obj twice.

end CC30003_0;
