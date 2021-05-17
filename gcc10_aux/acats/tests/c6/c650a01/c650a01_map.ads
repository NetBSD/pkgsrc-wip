-- C650A01.A
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
--     Check that Constraint_Error is raised if the result subtype of the
--     function is an anonymous access type designating a specific tagged
--     type and the result value is not null and designates some other
--     specific type.
--
-- TEST DESCRIPTION:
--     The foundation F650A00 declares a set of related limited tagged types.
--     The package C650A01 declares a map of these objects, including several
--     incorrect and correct accessor functions.
--
--     The rule tested is added by AI05-0073-1. It is necessary
--     so that dispatching on functions with access controlling results
--     work properly; those rules assume that the tag of the returned
--     object is that of the specific type. Recall that general access types
--     only require that the designated type is convertible to (not the same
--     as) the target designated type.
--
-- CHANGE HISTORY:
--     29 Mar 2008 RLB Created test.
--     17 Jul 2008 RLB Corrected illegal type conversion.
--
with F650A00.P;
package C650A01_Map is
    -- Package defining a map of alerts.
    -- Note: This package can only store library-level alert objects.

    subtype Key_Type is Natural range 1 .. 100;
        -- This probably would be some other type in a real map.

    procedure Clear_Map;

    procedure Set_Item (Key : in Key_Type; Item : access F650A00.Alert'Class);

    function Get_Item (Key : in Key_Type) return access F650A00.Alert'Class;
        -- Returns null if no object has been set for Key.

    function Get_Practice_Item (Key : in Key_Type)
        return access F650A00.P.Practice_Alert;
        -- Returns null if no object has been set for Key.
        -- This is a bad idea; no objects derived from Practice_Alert can be
        -- returned. We use it to test the objective in question.

end C650A01_Map;
