-- CXC3002.A
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
--     Check that Program_Error is raised if the interrupt corresponding
--     to that specified by the expression in pragma Attach_Handler is
--     reserved.
--    
-- TEST DESCRIPTION:
--     A protected type is declared with a discriminant of type
--     Ada.Interrupts.Interrupt_ID. A pragma Attach_Handler designates a
--     procedure within the protected type to be attached to the interrupt
--     specified by the discriminant.
--
--     A procedure scans the values of type Ada.Interrupts.Interrupt_ID for
--     a reserved interrupt (as indicated by the function
--     Ada.Interrupts.Is_Reserved). If no such interrupt is found, the test
--     is inapplicable.
--
--     If a reserved interrupt is found, however, the corresponding value of
--     type Ada.Interrupts.Interrupt_ID is used as a discriminant in the
--     creation of an object of the protected type. The test verifies that
--     the object declaration raises Program_Error.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for implementations validating the
--      the Systems Programming Annex.
--
--      This test is not applicable for implementations for which no value of
--      the type Ada.Interrupts.Interrupt_ID designates a reserved interrupt.
--
--
-- CHANGE HISTORY:
--      27 Oct 95   SAIC    Initial prerelease version.
--      12 Apr 96   SAIC    Added pragma Elaborate to context clause preceding
--                          CXC3002_1. Added initialization of Int_ID in body
--                          of CXC3002_1.Find_Reserved_Interrupt.
--
--!

with Ada.Interrupts;
package CXC3002_0 is

   protected type Handler_Type (ID: Ada.Interrupts.Interrupt_ID) is
      procedure Handle_Interrupt;
      pragma Attach_Handler( Handle_Interrupt, ID );
   private
      Was_Handled : Boolean := False;
   end Handler_Type;

end CXC3002_0;
