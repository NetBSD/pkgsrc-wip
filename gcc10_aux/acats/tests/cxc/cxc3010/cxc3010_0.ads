-- CXC3010.A
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
--
-- OBJECTIVE:
--     Check that if, by using the Attach_Handler (or Detach_Handler, or
--     Exchange_Handler) procedures, an attempt is made to detach a handler
--     that was attached statically (using the aspect Attach_Handler), the
--     handler is not detached and Program_Error is raised.
--
-- TEST DESCRIPTION:
--     Declare a protected object whose type uses an Attach_Handler aspect
--     (getting the interrupt number from a discriminant) and a main procedure
--     that attempts to detach or replace the interrupt handler that was
--     attached by the aspect specification.
--
--     The test models an (incorrectly written) application that changes
--     the interrupt handler in response to a mode change.
--
-- SPECIAL REQUIREMENTS:
--      This test requires that interrupts be enabled, and that an
--      interrupt (identified by ImpDef.Annex_C.Interrupt_To_Generate)
--      be generated multiple times, at points designated by calls to
--      ImpDef.Annex_C.Generate_Interrupt.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for implementations validating the
--      the Systems Programming Annex.
--
-- CHANGE HISTORY:
--      15 Jan 12   TV     Initial version.
--      21 Jan 12   TV     Revision after advice from editor.
--      11 Apr 14   RLB    Split code shared between two tests into a
--                         foundation.
--      14 Apr 14   RLB    Added missing required delay after interrupt.
--
--!
with Ada.Interrupts;
package CXC3010_0 is
   protected type Device_Interface_T
     (Int_Id : Ada.Interrupts.Interrupt_Id) is
      procedure Handler
          with Attach_Handler => Int_Id;
      procedure Check (Success : out Boolean);
   private
      Handled : Boolean := False; -- set to True by Handler; reset by Check
   end Device_Interface_T;
end  CXC3010_0;
