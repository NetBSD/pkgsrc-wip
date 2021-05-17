-- CXC7003.A
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
--      Check that the Task_Attributes operations Set_Value and
--      Reinitialize performs finalization on the old value
--      of the attribute of the specified task.
--
-- TEST DESCRIPTION:
--      A type is created from Controlled with a Finalize procedure
--      that records the Id of the object being finalized.
--      This type is used to create a task attribute.
--      A task is created so that attributes can be set for both
--      that task and the environment task.
--      Both the environment task and the created task are given 
--      unique attribute values.
--      Set_Value and Reinitialize are called and the value of the
--      last finalized Id is checked to make sure the proper attribute
--      values were finalized.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      25 JAN 96   SAIC    Initial version
--       7 MAY 96   SAIC    Incorporated Reviewer comments.
--      20 JAN 99   RLB     Restructured to support implementations which
--                          take advantage of the permissions of C.7.2(29).
--
--!


with Ada.Finalization;
package CXC7003_0 is
   type Notes_Finalization is new Ada.Finalization.Controlled with
      record
         Id : Integer := 0;
      end record;

   procedure Finalize (Object : in out Notes_Finalization);

   Last_Finalized : Integer := -1;  -- holds Id of last item finalized;

   ------ a few objects with known ids  -------
   Object_1 : Notes_Finalization;
   Object_2 : Notes_Finalization;
   Object_3 : Notes_Finalization;
   Object_4 : Notes_Finalization;
end CXC7003_0;
