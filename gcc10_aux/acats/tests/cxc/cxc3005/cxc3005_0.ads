-- CXC3005.A
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
--     Check that Program_Error is raised if an actual parameter of type
--     Ada.Interrupts.Interrupt_ID is passed in a call to any of the
--     following operations in package Ada.Interrupts, and the specified
--     interrupt is reserved: Is_Attached, Current_Handler, Attach_Handler,
--     Exchange_Handler, Detach_Handler.
--    
-- TEST DESCRIPTION:
--     A procedure scans the values of type Ada.Interrupts.Interrupt_ID for
--     a reserved interrupt (as indicated by the function
--     Ada.Interrupts.Is_Reserved). If no such interrupt is found, the test
--     is inapplicable.
--
--     If a reserved interrupt is found, the corresponding value of type
--     Ada.Interrupts.Interrupt_ID is passed as an actual parameter to
--     each of the following operations in package Ada.Interrupts:
--     Is_Attached, Current_Handler, Attach_Handler, Exchange_Handler,
--     Detach_Handler. The test verifies that Program_Error is raised
--     in each case.
--
--     To avoid potential optimizations which would eliminate the raising
--     of Program_Error, two versions of a procedure Avoid_Optimization
--     are declared: one for parameters of type Ada.Interrupts.Interrupt_ID
--     and one for those of type Ada.Interrupts.Parameterless_Handler.
--     The appropriate procedure is called after the points where the
--     exception should be raised.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for implementations validating the
--      Systems Programming Annex.
--
--      This test must be executed. It will report "not applicable" on
--      implementations for which no value of the type
--      Ada.Interrupts.Interrupt_ID designates a reserved interrupt.
--
--
-- CHANGE HISTORY:
--      18 Jan 96   SAIC    Initial prerelease version.
--      12 Apr 96   SAIC    Added pragma Elaborate to context clause preceding
--                          CXC3005_1. Added initialization of ID in body of
--                          CXC3005_1.Find_Reserved_Interrupt.
--
--!

package CXC3005_0 is

   protected Dynamic_Handler is
      procedure Handle_Interrupt;
      pragma Interrupt_Handler( Handle_Interrupt );
   private
      Was_Handled : Boolean := False;
   end Dynamic_Handler;

end CXC3005_0;
