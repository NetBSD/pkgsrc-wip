-- F452A00.A
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
-- FOUNDATION DESCRIPTION:
--     This foundation provides basic operations to test whether equality of
--     a type is the same inside and outside of this foundation.
--
--     The language requires that the equality operations of
--     language-defined types act as if they are predefined, that is, the
--     operation remain the same inside of a generic (where some predefined
--     operation code reemerge) and that they participate in the predefined
--     equality of all composite types containing it as a part (including
--     arrays). This is only true for record types; for other kinds of types,
--     any user-defined "=" is ignored inside of a generic and in composition
--     of of equality.
--
--     Note that the three formal objects always be independent objects and
--     must have the relationship
--       Obj1 = Obj2 /= Obj3
--     If not, the test may fail incorrectly or miss errors.

-- CHANGE HISTORY:
--     25 JAN 2001   PHL   Initial version.
--     19 Dec 2018   RLB   Created foundation from part of submitted test.

generic
    Subtest : String;
    type T is private;

    -- Obj1 = Obj2 /= Obj3, and they are all created independently.
    Obj1 : in T;
    Obj2 : in out T;
    Obj3 : in out T;
package F452A00 is

    type A is array (Boolean range <>) of T;

    type R (D : Boolean) is
        record
            C1 : Character;
            case D is
                when False =>
                    C2 : A (False .. D);
                    C3 : Float;
                when True =>
                    C4 : Boolean;
                    C5 : T;
            end case;
        end record;

    procedure Check;

end F452A00;
