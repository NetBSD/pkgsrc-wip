-- C452003.A
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
--     For a membership where the membership choice is a subtype (determining
--     the tested type) which is a (named) general access-to-object type
--     designating a tagged type, check that the membership returns False
--     unless all of the below are true:
--     (1) the type of the tested expression is convertible to the tested type;
--     (2) the accessibility level of the tested expression is no deeper than
--         that of the tested type;
--     (3) if the tested expression is not null, the tag of the designated
--         object is covered by the designated type of the tested type;
--     (4) if the tested subtype excludes null, the tested expression is not
--         null.
--
-- TEST DESCRIPTION:
--     A programmer is creating a hierarchy of objects where some of the
--     dispatching and class-wide operations need to store the controlling
--     parameter into a global data structure. The global data structure is
--     built using a named general access to root classwide type declared
--     at library level. Since we are postulating that dispatching is required
--     by some of the operations, anonymous access parameters are needed to
--     provide that. The abstraction constructor wants to communicate that
--     the actual parameters have to have library-level accessibility - they
--     can do that with a membership in a precondition. Similarly, the client
--     programmer wants to avoid violating the precondition (regardless of how
--     it is given), and they can use a membership to do that.
--
--     We only declare a skeleton of this structure, declaring Root_Type and
--     Child_Type derived from it, two primitive operations Save and Is_Present
--     and one class-wide operation for each type, and a simple global data
--     structure.
--
--     ----
--
--     This test is checking the rules of 4.5.2(30.2/4) and 4.5.2(30.3/4),
--     both added by Ada 2012. The tested expression of these memberships can
--     be an object of an anonymous access type following 8.6(25.1/3), which
--     allows anonymous access types to match named general access types when
--     that's reasonable. Also note that the Legality Rule 8.6(27.1/4)
--     explicitly excludes the tested expression of a membership from its check
--     -- essentially, there is no implicit conversion in a membership, the
--     tested expression retains its original (possibly different) type and
--     the membership test returns True or False instead.
--
--     This test is implicitly also providing a test of 8.6(25.1/3) resolution,
--     as it uses all of the abilities provided there. It also uses a variety
--     of other new Ada 2012 features (if expressions, preconditions, and
--     use all type).

-- CHANGE HISTORY:
--    28 Sep 2018   RLB   Created test.
--    13 May 2020   RLB   Corrected Force_Save, the inner if branches
--                        were backwards.
--    14 May 2020   RLB   Corrected Force_Op, which didn't test the objective.
--    22 May 2020   RLB   Typos in previous version.
--
--!

package C452003_Root is

   pragma Assertion_Policy (Check);

   type Root_Type is tagged record
       Id : Natural := 0;
   end record;

   type Any_Root_Ptr is access all Root_Type'Class;

   subtype Non_Null_Any_Root_Ptr is not null Any_Root_Ptr;

   procedure Save (Obj : access Root_Type)
      with Pre => Obj in Any_Root_Ptr; -- (Objective 2)

   function Is_Present (Obj : access Root_Type) return Boolean;

   type TC_Result is (Is_Null, Done, Wrong_Kind);

   procedure Force_Op (Obj : access constant Root_Type'Class;
                       Result : out TC_Result);

end C452003_Root;
