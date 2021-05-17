-- B415001.A
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
--     Check that the name given for an Implicit_Dereference aspect must be
--     that of an access discriminant for the associated type.
--
--     Check that a descendant of a reference type cannot specify a
--     nonconfirming value for aspect Implicit_Dereference.
--
--     Check that Implicit_Dereference cannot be specified for the full view
--     of a private type or private extension if the partial view has
--     known discriminants.
--
--     Check that Implicit_Dereference cannot be inherited for the full view
--     of a private type or private extension if the partial view has
--     known discriminants and does not inherit or specify the same value
--     of the same aspect.
--
-- TEST DESCRIPTION:
--     Declare types and objects as needed to check the various objectives.
--
--     In order to clarify the intended errors, each error label refers to the
--     appropriate objective, with the four objectives numbered from 1 to 4
--     based on the order given above.
--
--     The latter two objectives come from Corrigendum 2015, AI12-0138-1,
--     specifically from 13.1.1(18.4/4).
--
-- HISTORY:
--     07 May 2015   RLB   Created test.
--     14 May 2015   RLB   Added derivation of objectives to test description.
package B415001_A is

    type Root is tagged private;

    type Priv_Ref (D : access Integer) is tagged private
       with Implicit_Dereference => D;                           -- OK.

    type Der (D : access Integer) is new Root with private
       with Implicit_Dereference => D;                           -- OK.

    type Dbl_Ref (D1 : access Integer;
                  D2 : access String) is null record
       with Implicit_Dereference => D1;                          -- OK.

    type Dbl_Der (D1 : access Integer;
                  D2 : access String) is new Root with private
       with Implicit_Dereference => D1;                          -- OK.

private

    type Root is tagged null record;

    type Priv_Ref (D : access Integer) is tagged record
       C : Natural;
    end record;

    type Der (D : access Integer) is new Root with null record;

    type Dbl_Der (D1 : access Integer;
                  D2 : access String) is new Root with null record;

end B415001_A;
