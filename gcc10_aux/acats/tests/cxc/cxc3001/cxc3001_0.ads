-- CXC3001.A
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
--     Check that Is_Attached returns False for all non-reserved interrupts
--     to which no user-defined handler has been attached.
--
--     Check that a user-defined handler can be attached to every interrupt
--     for which Is_Reserved returns False. Check that Is_Attached returns
--     True for all non-reserved interrupts to which a user-defined handler
--     has been attached. Check that if Detach_Handler is subsequently called
--     for such an interrupt, Is_Attached returns False.
--
--     Check that, for procedures Attach_Handler and Exchange_Handler, if
--     the parameter New_Handler designates a protected procedure to which
--     the pragma Interrupt_Handler does not apply, Program_Error is raised
--     and the existing interrupt treatment is not modified.
--
-- TEST DESCRIPTION:
--     At program start-up, the test checks that Is_Attached returns False
--     for each value of the subtype Ada.Interrupt.Interrupt_ID for which
--     Is_Reserved returns False. Then Attach_Handler is called to attach
--     a handler to each non-reserved interrupt. The test checks that
--     Is_Attached is True for each non-reserved interrupt.
--
--     Next, Detach_Handler is called for each non-reserved interrupt, and
--     the test checks that Is_Attached is False for each of them.
--
--     Finally, Attach_Handler is used to attach a handler to the interrupt
--     ImpDef.Annex_C.Interrupt_To_Generate. The interrupt is generated to
--     verify that the handler is attached. Attach_Handler is then called
--     to attempt to attach a protected procedure, to which a pragma
--     Interrupt_Handler does not apply, to the same interrupt. The test
--     verifies that Program_Error is raised, then generates the interrupt
--     to verify that the existing treatment is still in effect. This
--     process is repeated with the procedure Exchange_Handler.
--
-- SPECIAL REQUIREMENTS:
--      This test requires that interrupts be enabled, and that an
--      interrupt (identified by ImpDef.Annex_C.Interrupt_To_Generate)
--      be generated multiple times, at points designated by calls to
--      ImpDef.Annex_C.Generate_Interrupt.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for implementations validating the
--      Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      20 Dec 94   SAIC    Delete array indexed by Interrupt_ID
--      14 Oct 95   SAIC    Fixed bugs for ACVC 2.0.1
--      23 Feb 96   SAIC    Updated ImpDef references to ImpDef.Annex_C.
--      29 Feb 96   SAIC    ACVC 2.0.1 fixes: Removed equality check of two
--                          access-to-subprogram values. Adjusted commentary.
--      09 May 96   SAIC    ACVC 2.1: Substantially modified objective and
--                          test. Removed documentation-only cases and cases
--                          redundant with other tests. Enhanced testing of
--                          Is_Attached. Added case to check that P_E raised
--                          if Attach_Handler or Exchange_Handler used to
--                          attach and invalid handler.
--
--!

with Ada.Interrupts;
package CXC3001_0 is

   protected Good is
      procedure Handler;
      pragma Interrupt_Handler( Handler );

      function  Count return Natural;
      procedure Reset;
   private
      Counter : Natural := 0;
   end Good;


   protected Bad is
      procedure Handler;     -- No pragma Interrupt_Handler!

      function Count return Natural;
   private
      Counter : Natural := 0;
   end Bad;

end CXC3001_0;
