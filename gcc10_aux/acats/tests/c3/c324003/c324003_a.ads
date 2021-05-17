-- C324003.A
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
-- OBJECTIVE:
--      Check that predicates are checked in the correct order, and that the
--      specified exception raised in place of Assertion_Error.
--
-- TEST DESCRIPTION:
--      This test is based on the examples in AI12s 22, 54 & 71.
--
-- CHANGE HISTORY:
--       5 Mar 15   JAC     Initial pre-release version.
--      17 Mar 15   RLB     Changes for release, removed use of Text_IO.
--      11 Aug 15   RLB     Added the missing function Name, used in the
--                          Predicate_Failure message.
--
--!

package C324003_A is

   -- A version of the example found at the end of RM 3.2.4.

   pragma Assertion_Policy (Check); -- Should turn on for all

   type File_Mode is (In_File, Out_File, Append_File);

   type File_Type is private;

   subtype Open_File_Type is File_Type
      with Dynamic_Predicate => (Is_Open (Open_File_Type)),
           Predicate_Failure => raise Status_Error;

   subtype Input_File_Type is Open_File_Type
      with Dynamic_Predicate => Mode (Input_File_Type) = In_File,
           Predicate_Failure => raise Mode_Error with "Can't read file: " &
           Name (Input_File_Type);

   subtype Output_File_Type is Open_File_Type
      with Dynamic_Predicate => Mode (Output_File_Type) /= In_File,
           Predicate_Failure => raise Mode_Error with "Can't write file: " &
           Name (Output_File_Type);

   Status_Error : exception;
   Mode_Error   : exception;

   function Is_Open (Open_File : File_Type) return Boolean;

   function Mode (File : in Open_File_Type) return File_Mode;

   function Name (File : in Open_File_Type) return String;

   procedure Open (File : in out File_Type;
                   Mode : in     File_Mode);

   procedure Close (File : in out File_Type);

   procedure Get (File : in Input_File_Type; Item : out Character);

   procedure Put (File : in Output_File_Type; Item : in Character);

private

   type File_Type is record
      Open : Boolean := False;
      Mode : File_Mode;
   end record;

end C324003_A;
