-- C760010.A
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
--      Check that explicit calls to Initialize, Adjust and Finalize
--      procedures that raise exceptions propagate the exception raised,
--      not Program_Error.  Check this for both a user defined exception
--      and a language defined exception.  Check that implicit calls to
--      initialize procedures that raise an exception propagate the
--      exception raised, not Program_Error;
--
--      Check that the utilization of a controlled type as the actual for
--      a generic formal tagged private parameter supports the correct
--      behavior in the instantiated software.
--
-- TEST DESCRIPTION:
--      Declares a generic package instantiated to check that controlled
--      types are not impacted by the "generic boundary."
--      This instance is then used to perform the tests of various calls to
--      the procedures.  After each operation in the main program that should
--      cause implicit calls where an exception is raised, the program handles
--      Program_Error.  After each explicit call, the program handles the
--      Expected_Error.  Handlers for the opposite exception are provided to
--      catch the obvious failure modes.  The predefined exception
--      Tasking_Error is used to be certain that some other reason has not
--      raised a predefined exception.
--
--     
-- DATA STRUCTURES
--
--      C760010_1.Simple_Control is derived from
--        Ada.Finalization.Controlled
--
--      C760010_2.Embedded_Derived is derived from C760010_1.Simple_Control
--        by way of generic instantiation
--
--
-- CHANGE HISTORY:
--      01 MAY 95   SAIC    Initial version
--      23 APR 96   SAIC    Fix visibility problem for 2.1
--      14 NOV 96   SAIC    Revisit for 2.1 release
--      26 JUN 98   EDS     Added pragma Elaborate_Body to
--                          package C760010_0.Check_Formal_Tagged
--                          to avoid possible instantiation error
--!

---------------------------------------------------------------- C760010_0

package C760010_0 is

  User_Defined_Exception : exception;

  type Actions is ( No_Action,
                    Init_Raise_User_Defined, Init_Raise_Standard,
                    Adj_Raise_User_Defined,  Adj_Raise_Standard,
                    Fin_Raise_User_Defined,  Fin_Raise_Standard );

  Action : Actions := No_Action;

  function Unique return Natural;

end C760010_0;
