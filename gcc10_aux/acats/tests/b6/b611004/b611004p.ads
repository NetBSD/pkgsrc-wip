-- B611004.A
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
--
--     Check that Pre'Class and Post'Class cannot be specified on a subprogram
--     body that is acting as a completion.
--
-- CHANGE HISTORY:
--     04 Feb 2016   RLB   Created test.
--     28 Mar 2016   RLB   Added error location codes.
--
--!
package B611004P is

    type Root is tagged private;

    function Is_OK (P : in Root) return Boolean;

    procedure OK (P : in out Root)
       with Pre'Class => Is_OK (P), Post'Class => Is_OK (P);   -- OK. {14;1}

    procedure Spec1 (P : in out Root);

    procedure Spec2 (P : in out Root);

    function Spec4 (P : Root) return Root;

    procedure Spec5 (P : in out Root);

    procedure Spec6 (P : in out Root);

    function Spec8 (P : Root) return Root;

    procedure Spec9 (P : in out Root);

    procedure SpecA (P : in out Root);

private

    type Root is tagged record
       N : Natural := 0;
    end record;

    function Is_OK (P : in Root) return Boolean is (P.N mod 2 = 0);

end B611004P;
