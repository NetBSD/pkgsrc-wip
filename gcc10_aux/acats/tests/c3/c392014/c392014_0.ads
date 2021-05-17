-- C392014.A
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
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--    Check that objects designated by X'Access (where X is of a class-wide
--    type) and new T'Class'(...) are dynamically tagged and can be used in
--    dispatching calls.  (Defect Report 8652/0010).
--
-- CHANGE HISTORY:
--    18 JAN 2001   PHL   Initial version
--    15 MAR 2001   RLB   Readied for release.
--    03 JUN 2004   RLB   Removed constraint for S0, as the subtype has
--                        unknown discriminants.

--!
package C392014_0 is

    type T (D : Integer) is abstract tagged private;

    procedure P (X : access T) is abstract;
    function Create (X : Integer) return T'Class;

    Result : Natural := 0;

private
    type T (D : Integer) is abstract tagged null record;
end C392014_0;
