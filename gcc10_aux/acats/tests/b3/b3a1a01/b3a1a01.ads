-- B3A1A01.A
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
--
--     Check that the name of an untagged incomplete view cannot be used as
--     the subtype_mark of a parameter in a subprogram_body, entry_body,
--     or accept_statement. Check that the name of an incomplete view cannot
--     be used as the subtype_mark of the result of a function body.
--
--     Part B: Tagged and untagged incomplete views imported from a
--     limited view.
--
-- TEST DESCRIPTION:
--
--     We declare a number of subprograms, protected types, and task types
--     in a package specification with types imported from a limited view.
--     We then give the body of the package with the appropriate completions
--     without WITHing the full view.
--
--     Note that the specification of this package is made legal by Ada 2012
--     (AI05-0151-1).
--
--     Incomplete types are tested separately in test B3A1006, see that
--     test for further discussion.
--
-- CHANGE HISTORY:
--     29 May 2008  RLB  Created test.
--     01 Oct 2008  RLB  Corrected test errors.
--     13 Mar 2014  RLB  Redid test for Ada 2012, replaced objective;
--                       split test into separate tests for incomplete
--                       types and incomplete views from limited views.
--
limited with F3A1A00;
package B3A1A01 is

    procedure Proc1 (A : F3A1A00.An_Untagged_Type);            -- OK.

    procedure Proc2 (A : F3A1A00.A_Tagged_Type);               -- OK.

    procedure Proc3 (Cnt : in Natural;
                     Obj : out F3A1A00.Untagged_Private);      -- OK.

    procedure Proc4 (Cnt : in Natural;
                     Obj : out F3A1A00.Tagged_Private);        -- OK.

    procedure Proc5 (Wobble : in out
                                 F3A1A00.An_Access_to_Tagged); -- OK.

    procedure Proc6 (Wobble : access F3A1A00.A_Tagged_Type);   -- OK.

    function Func1 (Ouch : Boolean)
                   return F3A1A00.An_Untagged_Type;            -- OK.

    function Func2 (Rash : Character)
                   return F3A1A00.A_Tagged_Type;               -- OK.

    function Func3 (Flat : Natural)
                   return F3A1A00.An_Access_to_Untagged;       -- OK.

    function Func4 (Curve : Float)
                   return access F3A1A00.An_Untagged_Type;     -- OK.

    protected type PT1 is
       procedure P (B : in out F3A1A00.An_Untagged_Type);      -- OK.
       entry E (B : in out F3A1A00.An_Untagged_Type);          -- OK.
    private
       C : Character := 'R';
    end PT1;

    protected type PT2 is
       function F (B : F3A1A00.A_Tagged_Type) return Boolean;  -- OK.
       entry E (B : in out F3A1A00.A_Tagged_Type);             -- OK.
    private
       C : Character := 'R';
    end PT2;

    protected type PT3 is
       entry E1 (B : in F3A1A00.Untagged_Private);             -- OK.
       entry E2 (B : in F3A1A00.Tagged_Private);               -- OK.
       entry E3 (B : in F3A1A00.An_Access_to_Tagged);          -- OK.
       entry E4 (B : in F3A1A00.An_Access_to_Untagged);        -- OK.
    private
       C : Character := 'R';
    end PT3;

    task type Tsk1 is
       entry E1 (B : in out F3A1A00.An_Untagged_Type);         -- OK.
       entry E2 (B : in out F3A1A00.A_Tagged_Type);            -- OK.
       entry E3 (B : in  F3A1A00.Untagged_Private);            -- OK.
       entry E4 (B : out F3A1A00.Tagged_Private);              -- OK.
       entry E5 (B : in F3A1A00.An_Access_to_Tagged);          -- OK.
       entry E6 (B : in F3A1A00.An_Access_to_Untagged);        -- OK.
    end Tsk1;

end B3A1A01;
