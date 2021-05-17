-- B393013.A
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
--      For nonformal interface types, check that:
--      Generic in parameters may not be of an abstract type.
--      A function with an access result type that designates an abstract
--      result type must be declared abstract.
--      The result type of a generic function may not be abstract.
--      The designated type of the access result type of a generic function
--      may not be abstract. The return subtype indication of an extended
--      return statement may not be abstract.
--
-- TEST DESCRIPTION:
--      This test declares abstract private types, abstract private
--      extensions, and abstract record types. It then uses them in various
--      contexts.
--
--      This test checks the rules of 3.9.3(8/3) as updated by AI05-0073-1 and
--      AI05-0203-1, that are not tested in B393009. The test is created in
--      part from tests B393009 and B393012.
--
-- CHANGE HISTORY:
--      22 Nov 19   RLB     Created from existing tests.
--
--!

package B393013_0 is

   type Non_Lim_Interface is interface;

   type Lim_Interface is limited interface;

   type Task_Interface is task interface;

   type Prot_Interface is protected interface;

   type Syn_Interface is synchronized interface;

   function Return_Lim_Interface return Lim_Interface is abstract;  -- OK.

   type Concrete is new Non_Lim_Interface with null record;

end B393013_0;
