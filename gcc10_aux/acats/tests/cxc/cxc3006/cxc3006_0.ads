-- CXC3006.A
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
--     Check that Program_Error is raised if, by using the Ada.Interrupts
--     procedure Attach_Handler, Detach_Handler, or Exchange_Handler, an
--     attempt is made to detach an interrupt handler that was attached
--     using the pragma Attach_Handler. Check that, in each case, the
--     handler attached by the pragma is not detached.
--    
-- TEST DESCRIPTION:
--     An anonymous protected object A is declared, and one of its procedures
--     is attached to the interrupt designated by the constant
--     ImpDef.Annex_C.Interrupt_To_Generate, using a pragma Attach_Handler.
--
--     A second anonymous protected object B is declared, and one of its
--     procedures is designated as an interrupt handler using a pragma
--     Interrupt_Handler.
--
--     The procedure Ada.Interrupts.Attach_Handler is used to attempt to
--     attach the procedure of B to (and hence, to detach the procedure of
--     A from) ImpDef.Annex_C.Interrupt_To_Generate. The test verifies that
--     Program_Error is raised, and that a subsequent interrupt is handled
--     by the procedure of A.
--
--     This process is repeated for procedures Ada.Interrupts.Detach_Handler
--     and Ada.Interrupts.Exchange_Handler.
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
--      18 Jan 96   SAIC    Initial prerelease version.
--      23 Feb 96   SAIC    Updated ImpDef references to ImpDef.Annex_C.
--      12 Apr 96   SAIC    Fixed typo in Report.Test string.
--
--!

package CXC3006_0 is

   protected Dynamic is
      procedure Handler;
      pragma Interrupt_Handler ( Handler );

      procedure Reset;
      function  Handled return Boolean;
   private
      Was_Handled: Boolean := False;
   end Dynamic;

end CXC3006_0;
