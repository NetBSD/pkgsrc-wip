-- CXC3007.A
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
--     Check that if the actual parameter corresponding to the formal
--     parameter New_Handler in a call to either of the procedures
--     Ada.Interrupts.Attach_Handler or Ada.Interrupts.Exchange_Handler
--     has one of the following values, the default treatment for the
--     specified interrupt is restored:
--    
--        - The value null.
--        - The value returned by the function Current_Handler when no
--          user-defined handler is attached to the specified interrupt.
--    
-- TEST DESCRIPTION:
--     For this test, the determination of whether the default treatment is
--     restored is based on the value returned by Ada.Interrupts.Is_Attached.
--     At points where it is expected that the default treatment has been
--     restored, Attach_Handler should return False.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for implementations validating the
--      Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      20 Jan 96   SAIC    Initial prerelease version.
--      27 Feb 97   PWB.CTA Changed Impdef.Interrupt_To_Generate to
--                          Impdef.Annex_C.Interrupt_To_Generate
--!

package CXC3007_0 is

   protected Dynamic is
      procedure Handler1;
      pragma Interrupt_Handler ( Handler1 );

      procedure Handler2;
      pragma Interrupt_Handler ( Handler2 );
   private
      Was_Handled : Boolean := False;
   end Dynamic;

end CXC3007_0;
