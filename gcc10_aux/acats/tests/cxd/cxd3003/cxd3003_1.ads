-- CXD3003.A
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
--      Check that when Locking_Policy is Ceiling_Locking and no pragma
--      Priority or Interrupt_Priority is specified in a protected 
--      definition but a pragma Interrupt_Handler is specified, the 
--      ceiling priority is in the range of System.Interrupt_Priority.
--
-- TEST DESCRIPTION: 
--      Define a Protected Object which has no Priority Pragma but does
--      have an Interrupt_Handler pragma.
--      Create two tasks both of which call the P.O.  
--      Give the first a priority of Priority'Last just
--      to check reasonable access; the call should be successful.  
--      Give the second task a priority of Interrupt_Priority'First.
--      This task should also be successful in accessing the P.O.
--
-- SPECIAL REQUIREMENTS
--      The implementation must process a configuration pragma which is not
--      part of any Compilation Unit; the method employed is implementation
--      defined.
--
--
-- CHANGE HISTORY:
--      14 Aug 95   SAIC    ACVC 2.1
--
--!

-----------------------  Configuration Pragmas --------------------

pragma Locking_Policy (Ceiling_Locking);

-------------------  End of Configuration Pragmas --------------------

   
with System;
with Report;

package CXD3003_1 is

   

   type Task_Number is range 1..2;    -- the test tasks

   -- This is an array of flags showing which tasks have successfully 
   -- called the protected procedure
   --
   Check_Called : array (Task_Number) of Boolean := (others => false);


   protected Protected_Object is
   
      -- This protected object has no Pragma Priority
      -- thus its priority ceiling should be System.Priority'Last

      procedure For_Ceiling_Check (Numb : Task_Number);  
      function Verify_Calls return Boolean;

      procedure The_Int_Handler;
      pragma Interrupt_Handler (The_Int_Handler);
   end Protected_Object;

end CXD3003_1;
