-- C391003.A
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
--      Check that a type can be extended at a different level than the
--      parent type. Check that subprograms overridden for such an extension
--      can be dispatched to, and that the overridden routine can access
--      local variables of the subprogram.
--
-- TEST DESCRIPTION:
--      This test checks that Ada 95 rule of the third sentence of 3.9.1(3)
--      is not enforced for more recent Ada implementations, as it was
--      repealed by AI95-00344-01. It also checks some consequences of that
--      change.
--
--      We declare a root tagged private type Acccount to represent a bank
--      account, and some associated primitive operations, in a visible
--      library package. (This type is based on the one in test C392008.) We
--      also define a Transfer operation that takes two accounts and an amount
--      in that package. That operation is implemented using dispatching calls
--      on the primitive operations of type Account.
--
--      We declare a package containing a normal extension of the type,
--      Interest_Checking. This overrides some of the operations of Account.
--
--      We then define a package containing a wire-transfer subprogram, which
--      extends Account to create a temporary account to hold funds before
--      they are transmitted. We then transfer funds from the base account
--      to the temporary account using Transfer.
--
--      Finally, we have a main program where we create various accounts and
--      try various wire-transfers.
--
-- The following hierarchy of tagged types and primitive operations is
-- utilized in this test:
--
--   package Bank
--      type Account (root)-----------------------------------------------\
--            |                                                           |
--            | Operations                                                |
--            |     proc Deposit                                          |
--            |     proc Withdrawal                                       |
--            |     func Balance                                          |
--            |     proc Service_Charge                                   |
--            |     proc Add_Interest                                     |
--            |     proc Open                                             |
--            |                                                           |
--   package Interest_Checking                                            |
--      type Account (extended from Bank.Account)                         |
--            |                                                           |
--            \-Operations                                                |
--                  proc Deposit         (inherited)                      |
--                  func Balance         (inherited)                      |
--                  proc Service_Charge  (inherited)                      |
--                  proc Add_Interest    (overridden)                     |
--                  proc Open            (overridden)                     |
--                  proc Withdrawal      (overridden)                     |
--                                                                        |
--   procedure Wire_Transfer----------------------------------------------/
--      type Transfer_Account (extended from Bank.Account)
--            |
--            \-Operations
--                  proc Deposit         (overridden)
--                  proc Withdrawal      (inherited)
--                  func Balance         (inherited)
--                  proc Service_Charge  (inherited)
--                  proc Add_Interest    (inherited)
--                  proc Open            (inherited)
--
-- CHANGE HISTORY:
--    08 Jan 2015  RLB  Created test.
--    13 Mar 2015  RLB  Eliminated overlong line.
--
--!

----------------------------------------------------------------- C391003_0

package C391003_0 is           -- package Bank

  type Dollar_Amount is range -300_00..300_00;

   type Account is tagged private;

   -- Primitive operations.

   procedure Deposit        (A : in out Account;
                             X : in     Dollar_Amount);
   procedure Withdrawal     (A : in out Account;
                             X : in     Dollar_Amount);
   function  Balance        (A : in     Account) return Dollar_Amount;
   procedure Service_Charge (A : in out Account);
   procedure Add_Interest   (A : in out Account);
   procedure Open           (A : in out Account);

   procedure Transfer (Source, Target : in out Account'Class;
                       Amount : Dollar_Amount);

private
   type Account is tagged
      record
        Current_Balance: Dollar_Amount;
      end record;

end C391003_0;
