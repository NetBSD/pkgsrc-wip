-- B611016.A
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
--    Check that Pre'Class and Post'Class cannot be specified for an entry of
--    a tagged task or protected type.
--
--    Check that Pre'Class and Post'Class cannot be specified for a protected
--    subprogram of a tagged protected type.
--
--    Check that Pre'Class and Post'Class cannot be specified for a subprogram
--    that is not a primitive subprogram of some tagged type. (Tagged task type
--    and tagged protected type cases.)
--
--    Check that Pre'Class and Post'Class cannot be specified for task
--    types, protected types, single tasks, and single protected objects.
--
-- TEST DESCRIPTION:
--    We declare a synchronized interface, and then declare various
--    task and protected types that implement it (thus giving us tagged
--    task and protected types).
--
--    The first two objectives were discussed in AI12-0182-1, and the
--    language was confirmed.
--
-- CHANGE HISTORY:
--     16 Nov 2016   RLB   Created test.
--     18 Nov 2016   Rlb   Removed some cases redundant with those in B611003.
--
--!
package B611016A is

   type Syn is synchronized interface;

   function Is_Green (A_Syn : Syn) return Boolean is abstract;

   function Is_Round (A_Syn : Syn) return Boolean is abstract;

   function Is_Hard (A_Syn : Syn; N : in Natural) return Boolean is abstract
      with Pre'Class => Is_Round (A_Syn);

   procedure Do_It (A_Syn : in out Syn; N : in Natural) is abstract
      with
         Pre'Class => Is_Green (A_Syn),
         Post'Class => Is_Round (A_Syn);


   type Syn2 is synchronized interface;

   procedure Do_It (A_Syn : in out Syn2; N : in out Natural) is abstract
      with
         Pre'Class => N > 0,
         Post'Class => N in 1 .. 99;


end B611016A;
