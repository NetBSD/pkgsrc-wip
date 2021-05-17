-- CXC7002.A
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
--      Check that when an instance of package Task_Attributes is
--      elaborated, an object of the actual type corresponding to
--      the formal type Attribute is implicitly created for each
--      task that exists and is not yet terminated.
--      Check that Value returns the value set by Set_Value.
--      Check that Tasking_Error is raised if a Task_Attributes 
--      operation is attempted on a terminated task.
--      Check that Program_Error is raised if a Task_Attributes
--      operation is attempted on a null Task_Id.
--
-- TEST DESCRIPTION:
--      The Task_Attributes package is instantiated twice in this
--      program, once at the library level and once inside the
--      main procedure.  
--      Library level tasks and tasks local to the main procedure
--      are created.  
--      The default values are checked.
--      Values for the attributes are set and then querried.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      22 JAN 96   SAIC    Initial version for 2.1
--      25 MAR 96   SAIC    Incorporated reviewer comment
--      20 JAN 99   RLB     Revised test to make attributes smaller.
--
--!


with Ada.Task_Identification;
package CXC7002_0 is
   type Small_Integer is range -7 .. 7;
   type Int_Array is array (1..3) of Small_Integer;
   pragma Pack (Int_Array);

   Countdown : Int_Array := (3,2,1);

   task type Lib_Tasks is
      entry Get_Id (Id : out Ada.Task_Identification.Task_Id);
      entry Ok_To_Terminate;
   end Lib_Tasks;

   T1 : Lib_Tasks;
   T2 : Lib_Tasks;
end CXC7002_0;
