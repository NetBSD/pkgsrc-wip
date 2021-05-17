

with Ada.Assertions; use Ada.Assertions;
with C324003_A;
with Report;

procedure C324003 is

   pragma Assertion_Policy (Check); -- Should turn on for all

   My_File : C324003_A.File_Type;

   Current_Mode : C324003_A.File_Mode;


   procedure Test_In_Param_Not_Satisfy_Predicate_Input is

      procedure Call_Get is

         Got_Character : Character;

      begin

         --Confirm mode isn't in
         Report.Comment
           ("Call_Get - Mode is " &
            C324003_A.File_Mode'Image (C324003_A.Mode (My_File)));

         -- Should fail as mode is Out_File
         C324003_A.Get (File => My_File, Item => Got_Character);

      end Call_Get;

   begin

      declare
      begin

         Call_Get;

         Report.Failed
           ("Calling Get should have raised Mode_Error");

      exception

         when C324003_A.Mode_Error =>

            null;

         when Ada.Assertions.Assertion_Error =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Input - failure to" &
               " satisfy predicate detected but not changed from" &
               " Assertion_Error to Mode_Error");

         when others =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Input - " &
               "Some other exception raised");

      end;

   end Test_In_Param_Not_Satisfy_Predicate_Input;


   procedure Test_In_Param_Not_Satisfy_Predicate_Open is

      Status_Error_Raised : Boolean := False;

      procedure Call_Mode is
      begin

         --Confirm file isn't open
         Report.Comment
           ("Test_In_Param_Not_Satisfy_Predicate_Open - Is_Open is " &
            Boolean'Image (C324003_A.Is_Open (My_File)));

         -- Should fail as not open
         Current_Mode := C324003_A.Mode (My_File);

      end Call_Mode;

   begin

      declare
      begin

         Call_Mode;

         Report.Failed
           ("Calling Mode should have raised Status_Error");

      exception

         when C324003_A.Status_Error =>

            null;

         when Ada.Assertions.Assertion_Error =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Open - failure to" &
               " satisfy predicate detected but not changed from" &
               " Assertion_Error to Status_Error");

         when others =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Open - " &
               "Some other exception raised");

      end;

   end Test_In_Param_Not_Satisfy_Predicate_Open;


   procedure Test_In_Param_Not_Satisfy_Predicate_Open_Two is

      procedure Call_Put is
      begin

         --Confirm file isn't open
         Report.Comment
           ("Test_In_Param_Not_Satisfy_Predicate_Open_Two - Is_Open is " &
            Boolean'Image (C324003_A.Is_Open (My_File)));

         -- Should fail as not open
         C324003_A.Put (File => My_File, Item => 'B');

      end Call_Put;

   begin

      declare
      begin

         Call_Put;

         Report.Failed
           ("Calling Put with unopen file should have raised Status_Error");

      exception

         when C324003_A.Status_Error =>

            null;

         when C324003_A.Mode_Error =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Open_Two - failure to" &
               " satisfy predicate detected but Mode_Error raised");

         when Ada.Assertions.Assertion_Error =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Open_Two - failure to" &
               " satisfy predicate detected but not changed from" &
               " Assertion_Error to Status_Error");

         when others =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Open_Two - " &
               "Some other exception raised");

      end;

   end Test_In_Param_Not_Satisfy_Predicate_Open_Two;


   procedure Test_In_Param_Not_Satisfy_Predicate_Output is

      procedure Call_Put is
      begin

         --Confirm mode isn't out or append
         Report.Comment
           ("Call_Put - Mode is " &
            C324003_A.File_Mode'Image (C324003_A.Mode (My_File)));

         -- Should fail as mode is In_File
         C324003_A.Put (File => My_File, Item => 'A');

      end Call_Put;

   begin

      declare
      begin

         Call_Put;

         Report.Failed
           ("Calling Put should have raised Mode_Error");

      exception

         when C324003_A.Mode_Error =>

            null;

         when Ada.Assertions.Assertion_Error =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Output - failure to" &
               " satisfy predicate detected but not changed from" &
               " Assertion_Error to Mode_Error");

         when others =>

            Report.Failed
              ("Test_In_Param_Not_Satisfy_Predicate_Output - " &
               "Some other exception raised");

      end;

   end Test_In_Param_Not_Satisfy_Predicate_Output;


   procedure Test_Membership_Test_Input is

      procedure Membership_Test_Input is
      begin

         -- The predicate of Input_File_Type should not be evaluated if the
         -- prior predicate of Open_File_Type is not satisfied, so (the file
         -- being closed) the membership test should return False, not raise an
         -- exception.

         if My_File in C324003_A.Input_File_Type then

            Test_In_Param_Not_Satisfy_Predicate_Input;

         end if;

      end Membership_Test_Input;

   begin

      Report.Comment ("Test_Membership_Test_Input");

      declare
      begin

         Membership_Test_Input;

      exception

         when C324003_A.Mode_Error =>

            Report.Failed
              ("Test_Membership_Test_Input - should not have evaluated the" &
               " predicate of Input_File_Type as the predicate of" &
               " Open_File_Type wasn't satisfied, not raised Mode_Error");

         when Ada.Assertions.Assertion_Error =>

            Report.Failed
              ("Test_Membership_Test_Input - should not have evaluated the" &
               " predicate of Input_File_Type as the predicate of" &
               " Open_File_Type wasn't satisfied (plus exception not changed" &
               " from Assertion_Error to Mode_Error)");

         when others =>

            Report.Failed
              ("Test_Membership_Test_Input - Some other exception raised");

      end;

   end Test_Membership_Test_Input;


   procedure Test_Membership_Test_Output is

      procedure Membership_Test_Output is
      begin

         -- The predicate of Output_File_Type should not be evaluated if the
         -- prior predicate of Open_File_Type is not satisfied, so (the file
         -- being closed) the membership test should return False, not raise an
         -- exception.

         if My_File in C324003_A.Output_File_Type then

            Test_In_Param_Not_Satisfy_Predicate_Output;

         end if;

      end Membership_Test_Output;

   begin

      Report.Comment ("Test_Membership_Test_Output");

      declare
      begin

         Membership_Test_Output;

      exception

         when C324003_A.Mode_Error =>

            Report.Failed
              ("Test_Membership_Test_Output - should not have evaluated the" &
               " predicate of Output_File_Type as the predicate of" &
               " Open_File_Type wasn't satisfied, not raised Mode_Error");

         when Ada.Assertions.Assertion_Error =>

            Report.Failed
              ("Test_Membership_Test_Output - should not have evaluated the" &
               " predicate of Output_File_Type as the predicate of" &
               " Open_File_Type wasn't satisfied (plus exception not changed" &
               " from Assertion_Error to Mode_Error)");

         when others =>

            Report.Failed
              ("Test_Membership_Test_Output - Some other exception raised");

      end;

   end Test_Membership_Test_Output;

begin

   Report.Test
     ("C324003",
      "Check that predicates are checked in the correct order, and that the" &
      "  specified exception raised in place of Assertion_Error");

   -- Sets Open to False and Mode to In_File
   C324003_A.Close (My_File);

   Test_In_Param_Not_Satisfy_Predicate_Open;

   Test_In_Param_Not_Satisfy_Predicate_Open_Two;

   Test_Membership_Test_Input;

   Test_Membership_Test_Output;

   C324003_A.Open (File => My_File, Mode => C324003_A.Out_File);

   Test_In_Param_Not_Satisfy_Predicate_Input;

   Report.Result;

end C324003;

