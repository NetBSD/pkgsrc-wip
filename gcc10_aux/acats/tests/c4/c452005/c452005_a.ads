-- C452005.A
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
--
-- OBJECTIVE:
--     Check that an individual membership test that is an expression of an
--     limited array type yields True if the primitive equals for the type
--     yields True, and False otherwise.
--
--     Check that an individual membership test that is an expression of an
--     nonlimited array type yields True if the predefined equals for the type
--     yields True, and False otherwise.
--
-- TEST DESCRIPTION:
--     We imagine an application that represents lists of record data with a
--     a fixed array with a terminator record. We create limited and nonlimited
--     versions of such a list, each having a primitive equality operation that
--     respects the terminator. To simplify the test, we declare the actual
--     data to be a single integer value (the data would be more complex in a
--     real application).
--
--     We then try various membership operations on the lists to check which
--     equality operator is used to implement the individual membership tests.
--
--     RM 4.5.2(28.1/4) is the primary paragraph tested herein.
--
--     Note: We don't try to describe a use case for the use of the
--     memberships, since these are an alternative to using "=", and we
--     wouldn't try to justify the use of "=" as it is so common that we expect
--     that every possible case will appear eventually.
--
-- CHANGE HISTORY:
--    28 Mar 2019   RLB   Created test.
--
--!

with Report;
package C452005_A is

   type Kind_Type is (Data_End, Data);

   type Lim_Data_Type is limited record
      Kind : Kind_Type := Data_End;
      Value: Natural := Report.Ident_Int(0);
   end record;

   type Nonlim_Data_Type is record
      Kind : Kind_Type := Data_End;
      Value: Natural := 0;
   end record;

end C452005_A;
