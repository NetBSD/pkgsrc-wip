-- C452006.A
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
--     access type yields True if the predefined equals for the type
--     yields True, and False otherwise.
--
--     Check that an individual membership test that is an expression of a
--     type that is limited at the point of the membership yields True if the
--     primitive equals for the type yields True, and False otherwise, even
--     if the full type is an access type.
--
-- TEST DESCRIPTION:
--     We imagine an application with a private type that represents a handle
--     to a managed object. It has equality operations which compare the
--     underlying data (if any). We define both limited and nonlimited
--     versions of this type. To simplify the test, we declare the actual
--     data to be a single integer value (the data would be more complex in
--     a real application).
--
--     We then try various membership operations on objects of the private
--     type to check which equality operator is used to implement the
--     individual membership tests.
--
--     RM 4.5.2(28.1/4) is the primary paragraph tested herein. Note that
--     AI12-0328-1 confirms and clarifies that if the type is limited at
--     the point of the membership test, then primitive equality is used
--     even if the full type would use predefined equality.
--
--     Note: We don't try to describe a use case for the use of the
--     memberships, since these are an alternative to using "=", and we
--     wouldn't try to justify the use of "=" as it is so common that we expect
--     that every possible case will appear eventually.
--
-- CHANGE HISTORY:
--    28 Mar 2019   RLB   Created test.
--    27 Jun 2019   RLB   Revised test to avoid cases declared illegal
--                        by AI12-0328-1.
--
--!

with Report;
package C452006_A is

   type Lim_Handle is limited private;

   Null_Lim_Handle : constant Lim_Handle;

   function "=" (Left, Right : Lim_Handle) return Boolean;
      -- Compares the underlying data.

   function Create (Val : in Natural) return Lim_Handle;


   type Nonlim_Handle is private;

   Null_Nonlim_Handle : constant Nonlim_Handle;

   function "=" (Left, Right : Nonlim_Handle) return Boolean;
      -- Compares the underlying data.

   function Create (Val : in Natural) return Nonlim_Handle;

   -- Note: It would not be safe to recover memory from this implementation.

private

   type Data_Type is record
      Value : Natural;
   end record;

   type Raw_Access is access Data_Type;

   type Lim_Handle is new Raw_Access;

   Null_Lim_Handle : constant Lim_Handle := null;

   type Nonlim_Handle is access all Data_Type;

   Null_Nonlim_Handle : constant Nonlim_Handle := null;

end C452006_A;
