-- CXC7006.A
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
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--      Check the functionality of Ada.Task_Termination.
--
-- TEST DESCRIPTION:
--      This test creates tasks and sets up termination handlers for those
--      tasks with Set_Dependents_Fallback_Handler or Set_Specific_Handler.
--      The test makes sure that a handler is called for every task that
--      terminates, that the correct handler is called when more than one
--      handler could apply, and that the parameters to the handler are
--      correct.  The test also tries cases when an exception is propagated
--      out of a user-defined finalization routine when the task is being
--      finalized, and when an unhandled exception is propagated during
--      task elaboration.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Systems Programming Annex.
--
-- CHANGE HISTORY:
--      23 Nov 2009   AJB   Initial version.
--      01 Jan 2010   AJB   Fixed some illegal uses of "=" on
--                          Exception_Occurrence.
--      11 Jul 2012   AJB   Changes to Test_5 for AI05-0202.
--      18 Jul 2012   RLB   Renamed; minor changes to formatting of test.
--      20 Jul 2012   AJB   Fixed problem in which Exception_Message was
--                          tested for correctness after Program_Error was
--                          raised.
--      20 Jan 2014   RLB   Added missing Applicability Criteria.

with Ada.Task_Identification;
with Ada.Task_Termination;
with Ada.Exceptions;
package CXC7006_1 is

   package ATI renames Ada.Task_Identification;
   package ATT renames Ada.Task_Termination;
   package AE renames Ada.Exceptions;

   type String_Acc is access all String;

   type Task_ID_Array is array (Natural range <>) of ATI.Task_ID;
   type Cause_Array is array (Natural range <>) of ATT.Cause_Of_Termination;
   type Exception_Array is array (Natural range <>) of
           AE.Exception_ID;

   subtype Handler_ID is Integer range 0 .. 3;
   type Handler_ID_Array is array (Natural range <>) of Handler_ID;

   procedure Start_Test (Name : String);
   procedure Set_Task_IDs (IDs : Task_ID_Array);
   procedure Set_Expected_Causes (Causes : Cause_Array);
   procedure Set_Expected_Handlers (IDs : Handler_ID_Array);
   procedure Set_Expected_Message (Message : String);
   procedure Set_Expected_Exception (ID : AE.Exception_ID);
   procedure Set_Expected_Exceptions (IDs : Exception_Array);

   type Handler_Test_Procedure is access procedure
           (Param   : in Integer;
            OK      : out Boolean;
            Err_Msg : out String_Acc);
   procedure Set_Handler_Test (Index     : in Integer;
                               Test_Proc : in Handler_Test_Procedure;
                               Param     : in Integer);

   function The_Handler (Which : Handler_ID) return ATT.Termination_Handler;

   procedure Test_All_Handlers_Called;

end CXC7006_1;
