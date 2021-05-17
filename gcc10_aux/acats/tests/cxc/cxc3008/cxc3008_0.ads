-- CXC3008.A
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
--     Check that the procedures Ada.Interrupts.Attach_Handler and
--     Ada.Interrupts.Exchange_Handler attach a specified handler to
--     a specified interrupt, overriding any existing treatment. Check
--     that, for Exchange_Handler, the value returned in Old_Handler
--     designates the previous treatment for the interrupt.
--
--     Check that the procedure Ada.Interrupts.Current_Handler returns
--     a value that represents the attached handler of the specified
--     interrupt.
--
--     Check that the procedure Ada.Interrupts.Detach_Handler restores
--     the default treatment for the specified interrupt.
--
--     Check that an attached handler is called once for each delivered
--     interrupt occurrence.
--    
-- TEST DESCRIPTION:
--     For this test, the determination of whether the default treatment is
--     restored is based on the value returned by Ada.Interrupts.Is_Attached.
--     At points where it is expected that the default treatment has been
--     restored, Attach_Handler should return False.
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
--      05 Feb 96   SAIC    Initial version for ACVC 2.1.
--
--!

with ImpDef.Annex_C;
package CXC3008_0 is

   protected type Handler_Type is
      procedure Handler;
      pragma Attach_Handler ( Handler, ImpDef.Annex_C.Interrupt_To_Generate );

      function Handle_Count return Natural;
   private
      Count : Natural := 0;
   end Handler_Type;


   protected Dynamic1 is
      procedure Handler;
      pragma Interrupt_Handler ( Handler );

      function Handle_Count return Natural;
   private
      Count : Natural := 0;
   end Dynamic1;


   protected Dynamic2 is
      procedure Handler;
      pragma Interrupt_Handler ( Handler );

      function Handle_Count return Natural;
   private
      Count : Natural := 0;
   end Dynamic2;

end CXC3008_0;
