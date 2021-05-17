-- F341A00.A
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
-- FOUNDATION DESCRIPTION:
--      This foundation provides a simple class hierarchy (a root type and two
--      levels of derivation from it) to use in testing the basic OO features
--      related to tagged types.
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package F341A00_0 is   -- package Bank

  type Dollar_Amount  is new Float;  
 
   type Account is tagged
      record
        Current_Balance: Dollar_Amount;
      end record;

   -- Primitive operations.

   procedure Deposit        (A : in out Account; 
                             X : in     Dollar_Amount);
   procedure Withdrawal     (A : in out Account; 
                             X : in     Dollar_Amount);
   function  Balance        (A : in     Account) return Dollar_Amount;
   procedure Service_Charge (A : in out Account);
   procedure Add_Interest   (A : in out Account);
   procedure Open           (A : in out Account);

end F341A00_0;
