-- C760007.A
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
--      Check that Adjust is called for the execution of a return
--      statement for a function returning a result of a (non-limited)
--      controlled type.
--
--      Check that Adjust is called when evaluating an aggregate
--      component association for a controlled component.
--
--      Check that Adjust is called for the assignment of the ancestor
--      expression of an extension aggregate when the type of the
--      aggregate is controlled.
--
-- TEST DESCRIPTION:
--      A type is derived from Ada.Finalization.Controlled; the dispatching
--      procedure Adjust is defined for the new type.  Structures and
--      subprograms to model the test objectives are used to check that
--      Adjust is called at the right time.  For the sake of simplicity,
--      globally accessible data is used to check that the calls are made.
--
--
-- CHANGE HISTORY:
--      06 DEC 94   SAIC    ACVC 2.0
--      14 OCT 95   SAIC    Update and repair for ACVC 2.0.1
--      05 APR 96   SAIC    Add RM reference
--      06 NOV 96   SAIC    Reduce adjust requirement
--      25 NOV 97   EDS     Allowed zero calls to adjust at line 144
--!

---------------------------------------------------------------- C760007_0

with Ada.Finalization;
package C760007_0 is

  type Controlled is new Ada.Finalization.Controlled with record
    TC_ID : Natural := Natural'Last;
  end record;
  procedure Adjust( Object: in out Controlled );

  type Structure is record
    Controlled_Component : Controlled;
  end record;

  type Child is new Controlled with record
    TC_XX : Natural := Natural'Last;
  end record;
  procedure Adjust( Object: in out Child );

  Adjust_Count       : Natural := 0;
  Child_Adjust_Count : Natural := 0;

end C760007_0;
