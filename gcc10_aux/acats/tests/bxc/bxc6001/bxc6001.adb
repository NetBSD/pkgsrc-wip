-- BXC6001.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
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
--      Check that the name referenced in pragmas Atomic and Volatile may
--      only be an object, a non-inherited component or a full type.
--      Check that the name referenced in Atomic_Components or
--      Volatile_Components must be an array type or an object of an
--      anonymous array type.
--
-- TEST DESCRIPTION:
--      This test defines protected objects with various interfaces and
--      uses them to determine the correct recognition of pragmas Atomic,
--      Volatile, Atomic_Components and Volatile_Components.
--
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Systems Programming Annex.
--
-- ACCEPTANCE CRITERIA:
--      An implementation which cannot support the indivisible reads and
--      updates required by the Atomic pragma may report the
--      otherwise legal pragmas as illegal. If all such pragmas are
--      rejected, then the test should be graded as Not Applicable.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      15 Dec 94   SAIC    Reduced size expectations for Atomic objects
--      10 Nov 95   SAIC    Reordered components for ACVC 2.0.1
--      11 Oct 96   SAIC    Improved wording of Acceptance Criteria.
--      26 Jun 98   EDS     Clarified Acceptance Criteria and marked
--                          applications of pragma Atomic to composite
--                          types as possible errors
--!

------------------------------------------------------------------ BXC6001

procedure BXC6001 is
  Kitchen_Table : array(1..6) of Natural;
  pragma Volatile_Components( Kitchen_Table );                    -- OK

  Dining_Table  : array(1..6) of Float;
  pragma Atomic_Components( Dining_Table );                       -- OK

begin  -- Main test procedure.
  null;
end BXC6001;
