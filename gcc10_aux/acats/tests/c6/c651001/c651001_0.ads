-- C651001.A
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
--*
-- OBJECTIVES:
--
--     Check that a nonreturning procedure can propagate an exception to
--     "return" to the caller. Check that a nonreturning procedure raises
--     Program_Error if it attempts to return normally. Case 1: pragma
--     No_Return.
--
-- TEST DESCRIPTION:
--     We imagine a complex error handler, where different exceptions are
--     raised depending upon the error code generated after a system call.
--
--     We try several different forms of this error handler, and test that
--     they all operate as expected (including a buggy version).
--
-- CHANGE HISTORY:
--     31 Mar 17   RLB     Created test.
--
--!
package C651001_0 is -- OS_Interface

   subtype Error_Code is Natural range 0 .. 10;
   SUCCESS : constant Error_Code := 0;

   procedure Do_Something (Oper : in Natural; Result : out Error_Code);
      -- Our "system call"; for our purposes, it just returns
      -- a different error code for each Oper(ation) value.

   Invalid_Error   : exception;
   Not_Found_Error : exception;
   OS_Error        : exception;

   procedure Raise_Error (Error : in Error_Code);
   pragma No_Return (Raise_Error);

   generic
      with function Message (Error : in Error_Code) return String;
   procedure Generic_Raise_Error (Error : in Error_Code);
   pragma No_Return (Generic_Raise_Error);

end C651001_0;
