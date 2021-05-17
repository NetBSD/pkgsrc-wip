
with Report;
with Ada.Task_Identification;
with Ada.Task_Termination;
with Ada.Exceptions;
with CXC7006_1;
with CXC7006_2;
procedure CXC7006 is
   package ATI renames Ada.Task_Identification;
   package ATT renames Ada.Task_Termination;
   package AE renames Ada.Exceptions;

   Exception_1 : exception;
   Exception_2 : exception;

   Which_Exception : Integer;

   procedure Do_Raise (Code : String) is
   begin
      if Which_Exception = 1 then
         raise Exception_1 with "Do_Raise called: " & Code;
      else
         raise Exception_2 with "Do_Raise called: " & Code;
      end if;
   end Do_Raise;

begin
   Report.Test ("CXC7006", "Test Ada.Task_Termination");

   Test_1:
      -- Test fallback handler.
   declare
      Raise_Code : constant String := "first";
   begin
      declare
         task type TT is
            entry Which_Test (Cause : ATT.Cause_Of_Termination);
            entry Stall;
         end TT;

         TT_Array : array (1 .. 3) of TT;
         ID_Array : CXC7006_1.Task_ID_Array (TT_Array'range);
         Expected_Cause : CXC7006_1.Cause_Array (TT_Array'range);

         task body TT is
            The_Cause : ATT.Cause_Of_Termination;
         begin
            accept Which_Test (Cause : ATT.Cause_Of_Termination) do
               The_Cause := Cause;
            end Which_Test;
            case The_Cause is
               when ATT.Normal =>
                  delay 1.0;
                  abort TT_Array (2);
               when ATT.Abnormal =>
                  accept Stall;
               when ATT.Unhandled_Exception =>
                  Do_Raise (Raise_Code);
            end case;
         end TT;
      begin
         CXC7006_1.Start_Test ("Test_1");
         CXC7006_1.Set_Expected_Message ("Do_Raise called: " & Raise_Code);
         Which_Exception := 1;
         CXC7006_1.Set_Expected_Exception (Exception_1'Identity);
         ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (0));

         for I in ID_Array'range loop
            ID_Array(I) := TT_Array(I)'Identity;
         end loop;
         CXC7006_1.Set_Task_IDs (ID_Array);

         Expected_Cause := (ATT.Normal, ATT.Abnormal, ATT.Unhandled_Exception);
         CXC7006_1.Set_Expected_Causes (Expected_Cause);

         for I in TT_Array'range loop
            TT_Array (I).Which_Test (Expected_Cause (I));
         end loop;
         -- now wait for all tasks to terminate
      end;

      CXC7006_1.Test_All_Handlers_Called;

   end Test_1;

   Test_2:
      -- Test fallback handler set up by a task that is not the direct
      -- master of the tasks that are terminating.
   declare
      Raise_Code : constant String := "second";
   begin
      declare
         ID_Array : CXC7006_1.Task_ID_Array (1 .. 5);
         Expected_Cause : CXC7006_1.Cause_Array (1 .. 5);

         task Grandparent is
            entry Wait_Until_Ready;
            entry Start_Up;
         end Grandparent;

         task body Grandparent is

            task Parent is
               entry Wait_Until_Ready;
               entry Start_Up;
            end Parent;

            task body Parent is

               task type TT is
                  entry Which_Test (Cause : ATT.Cause_Of_Termination);
                  entry Stall;
               end TT;

               TT_Array : array (3 .. 5) of TT;

               task body TT is
                  The_Cause : ATT.Cause_Of_Termination;
               begin
                  accept Which_Test (Cause : ATT.Cause_Of_Termination) do
                     The_Cause := Cause;
                  end Which_Test;
                  case The_Cause is
                     when ATT.Normal =>
                        delay 1.0;
                        abort TT_Array (4);
                     when ATT.Abnormal =>
                        accept Stall;
                     when ATT.Unhandled_Exception =>
                        Do_Raise (Raise_Code);
                  end case;
               end TT;

            begin
               for I in TT_Array'range loop
                  ID_Array(I) := TT_Array(I)'Identity;
               end loop;
               accept Wait_Until_Ready;
               accept Start_Up;
               for I in TT_Array'range loop
                  TT_Array (I).Which_Test (Expected_Cause (I));
               end loop;
               -- now wait for all tasks to terminate
            end Parent;

         begin
            ID_Array(2) := Parent'Identity;
            Parent.Wait_Until_Ready;
            accept Wait_Until_Ready;
            accept Start_Up;
            Parent.Start_Up;
            -- now wait for all tasks to terminate
         end Grandparent;

      begin
         CXC7006_1.Start_Test ("Test_2");
         CXC7006_1.Set_Expected_Message ("Do_Raise called: " & Raise_Code);
         Which_Exception := 2;
         CXC7006_1.Set_Expected_Exception (Exception_2'Identity);
         ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (0));

         ID_Array(1) := Grandparent'Identity;
         Grandparent.Wait_Until_Ready;
         CXC7006_1.Set_Task_IDs (ID_Array);

         Expected_Cause := (ATT.Normal, ATT.Normal,
                            ATT.Normal, ATT.Abnormal,
                            ATT.Unhandled_Exception);
         CXC7006_1.Set_Expected_Causes (Expected_Cause);

         Grandparent.Start_Up;
         -- now wait for all tasks to terminate
      end;

      CXC7006_1.Test_All_Handlers_Called;

   end Test_2;

   Test_3:
      -- Test fallback handler when fallback handlers are set up by
      -- multiple "ancestors" of a task; make sure the correct handler is
      -- called.
   declare
      Raise_Code : constant String := "third";
   begin
      declare
         ID_Array : CXC7006_1.Task_ID_Array (1 .. 5);
         Expected_Cause : CXC7006_1.Cause_Array (1 .. 5);
         Expected_Handler : CXC7006_1.Handler_ID_Array (1 .. 5);

         task Grandparent is
            entry Wait_Until_Ready;
            entry Start_Up;
         end Grandparent;

         task body Grandparent is

            task Parent is
               entry Wait_Until_Ready;
               entry Start_Up;
            end Parent;

            task body Parent is

               task type TT is
                  entry Which_Test (Cause : ATT.Cause_Of_Termination);
                  entry Stall;
               end TT;

               TT_Array : array (3 .. 5) of TT;

               task body TT is
                  The_Cause : ATT.Cause_Of_Termination;
               begin
                  accept Which_Test (Cause : ATT.Cause_Of_Termination) do
                     The_Cause := Cause;
                  end Which_Test;
                  case The_Cause is
                     when ATT.Normal =>
                        delay 1.0;
                        abort TT_Array (4);
                     when ATT.Abnormal =>
                        accept Stall;
                     when ATT.Unhandled_Exception =>
                        Do_Raise (Raise_Code);
                  end case;
               end TT;

            begin
               ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (0));
               for I in TT_Array'range loop
                  ID_Array(I) := TT_Array(I)'Identity;
               end loop;
               accept Wait_Until_Ready;
               accept Start_Up;
               for I in TT_Array'range loop
                  TT_Array (I).Which_Test (Expected_Cause (I));
               end loop;
               -- now wait for all tasks to terminate
            end Parent;

         begin
            ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (1));
            ID_Array(2) := Parent'Identity;
            Parent.Wait_Until_Ready;
            accept Wait_Until_Ready;
            accept Start_Up;
            Parent.Start_Up;
            -- now wait for all tasks to terminate
         end Grandparent;

      begin
         CXC7006_1.Start_Test ("Test_3");
         CXC7006_1.Set_Expected_Message ("Do_Raise called: " & Raise_Code);
         Which_Exception := 2;
         CXC7006_1.Set_Expected_Exception (Exception_2'Identity);
         ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (2));

         ID_Array(1) := Grandparent'Identity;
         Grandparent.Wait_Until_Ready;
         CXC7006_1.Set_Task_IDs (ID_Array);

         Expected_Cause := (ATT.Normal, ATT.Normal,
                            ATT.Normal, ATT.Abnormal,
                            ATT.Unhandled_Exception);
         CXC7006_1.Set_Expected_Causes (Expected_Cause);

         Expected_Handler := (1 => 2, 2 => 1, others => 0);
         CXC7006_1.Set_Expected_Handlers (Expected_Handler);

         Grandparent.Start_Up;
         -- now wait for all tasks to terminate
      end;

      CXC7006_1.Test_All_Handlers_Called;

   end Test_3;

   Test_4:
      -- Test Set_Specific_Handler.
   declare
      Raise_Code : constant String := "fourth";
   begin
      declare

         ID_Array : CXC7006_1.Task_ID_Array (1 .. 14);
         Expected_Cause : CXC7006_1.Cause_Array (1 .. 14);
         Expected_Handler : CXC7006_1.Handler_ID_Array (1 .. 14);

         Delay_Amounts : constant array (1 .. 8) of Duration :=
            (1.5, 2.7, 2.1, 3.1, 1.3, 2.2, 1.8, 2.9);

         protected Delay_Amount is
            procedure Next_Delay (D : out Duration);
         private
            Index : Integer := Delay_Amounts'First;
         end Delay_Amount;

         protected body Delay_Amount is

            procedure Next_Delay (D : out Duration) is
            begin
               D := Delay_Amounts (Index);
               Index := Index + 1;
               if Index > Delay_Amounts'Last then
                  Index := Delay_Amounts'First;
               end if;
            end Next_Delay;

         end Delay_Amount;

         task type TT1 is
            entry Set_Up_IDs (Start_TT2, Start_TT3 : Integer);
            entry Start_Up;
         end TT1;

         task body TT1 is

            task type TT2 is
               entry Set_Up_IDs (Start_TT3 : Integer);
               entry Start_Up;
            end TT2;

            task body TT2 is

               task type TT3 is
                  entry Which_Test (Cause : ATT.Cause_Of_Termination);
               end TT3;

               task body TT3 is
                  The_Cause : ATT.Cause_Of_Termination;
                  D         : Duration;
               begin
                  accept Which_Test (Cause : ATT.Cause_Of_Termination) do
                     The_Cause := Cause;
                  end Which_Test;
                  Delay_Amount.Next_Delay (D);
                  delay D;
                  case The_Cause is
                     when ATT.Normal =>
                        null;
                     when ATT.Abnormal =>
                        raise Program_Error;  -- won't happen in this test
                     when ATT.Unhandled_Exception =>
                        Do_Raise (Raise_Code);
                  end case;
               end TT3;

               TT3_1 : TT3;
               TT3_2 : TT3;
            begin
               accept Set_Up_IDs (Start_TT3 : Integer) do
                  ID_Array(Start_TT3)     := TT3_1'Identity;
                  ID_Array(Start_TT3 + 1) := TT3_2'Identity;
               end Set_Up_IDs;
               TT3_1.Which_Test (ATT.Normal);
               TT3_2.Which_Test (ATT.Unhandled_Exception);
               accept Start_Up;
            end TT2;

            TT2_1 : TT2;
            TT2_2 : TT2;
         begin
            accept Set_Up_IDs (Start_TT2, Start_TT3 : Integer) do
               ID_Array(Start_TT2)     := TT2_1'Identity;
               ID_Array(Start_TT2 + 1) := TT2_2'Identity;
               TT2_1.Set_Up_IDs (Start_TT3);
               TT2_2.Set_Up_IDs (Start_TT3 + 2);
            end Set_Up_IDs;
            accept Start_Up;
            TT2_1.Start_Up;
            TT2_2.Start_Up;
         end TT1;

         TT1_1 : TT1;
         TT1_2 : TT1;
      begin
         CXC7006_1.Start_Test ("Test_4");
         CXC7006_1.Set_Expected_Message ("Do_Raise called: " & Raise_Code);
         Which_Exception := 1;
         CXC7006_1.Set_Expected_Exception (Exception_1'Identity);
         ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (0));

         ID_Array(1) := TT1_1'Identity;
         ID_Array(2) := TT1_2'Identity;
         TT1_1.Set_Up_IDs (3, 7);
         TT1_2.Set_Up_IDs (5, 11);
         CXC7006_1.Set_Task_IDs (ID_Array);

         ATT.Set_Specific_Handler (ID_Array(1), CXC7006_1.The_Handler (1));
         ATT.Set_Specific_Handler (ID_Array(3), CXC7006_1.The_Handler (2));
         ATT.Set_Specific_Handler (ID_Array(5), CXC7006_1.The_Handler (3));
         ATT.Set_Specific_Handler (ID_Array(7), CXC7006_1.The_Handler (2));
         ATT.Set_Specific_Handler (ID_Array(9), CXC7006_1.The_Handler (1));
         ATT.Set_Specific_Handler (ID_Array(11), CXC7006_1.The_Handler (3));
         ATT.Set_Specific_Handler (ID_Array(13), CXC7006_1.The_Handler (2));
         Expected_Handler := (1 => 1, 3 => 2, 5 => 3, 7 => 2,
                              9 => 1, 11 => 3, 13 => 2, others => 0);
         CXC7006_1.Set_Expected_Handlers (Expected_Handler);

         Expected_Cause := (8 | 10 | 12 | 14 => ATT.Unhandled_Exception,
                            others           => ATT.Normal);
         CXC7006_1.Set_Expected_Causes (Expected_Cause);

         TT1_1.Start_Up;
         TT1_2.Start_Up;
         -- wait for all tasks to complete
      end;

      CXC7006_1.Test_All_Handlers_Called;

   end Test_4;

   Test_5:
      -- Make sure behavior is correct when tasks that terminate also have
      -- controlled local variables.  Make sure that (1) local variables are
      -- finalized before the termination handler is called; (2) if
      -- the task terminates normally but finalization raises an exception,
      -- the termination handler is still called with
      -- Cause=Unhandled_Exception; (3) if the task terminates because of an
      -- unhandled exception, and the finalization then raises the exception,
      -- the termination handler is called with an Exception_Occurrence that
      -- identifies Program_Error (AI05-0202).
   declare
      Raise_Code : constant String := "fifth";
   begin
      declare

         type Test_Type is (Body_Exception, Fin_Exception, Both);

         task type TT is
            entry Which_Test (Obj_ID : Integer;  T : Test_Type);
         end TT;

         TT_Array : array (1 .. 3) of TT;
         ID_Array : CXC7006_1.Task_ID_Array (TT_Array'range);
         Expected_Cause : CXC7006_1.Cause_Array (TT_Array'range);
         Expected_Exceptions : CXC7006_1.Exception_Array (TT_Array'range);

         task body TT is
            The_Type : Test_Type;
            Obj      : CXC7006_2.Fin_Type;
         begin
            accept Which_Test (Obj_ID : Integer;  T : Test_Type) do
               Obj.Fin_ID := Obj_ID;
               The_Type := T;
            end Which_Test;
            if The_Type = Fin_Exception or else The_Type = Both then
               Obj.Raise_Exc := True;
            end if;
            if The_Type = Body_Exception or else The_Type = Both then
               Do_Raise (Raise_Code);
            end if;
         end TT;

      begin
         CXC7006_1.Start_Test ("Test_5");
         CXC7006_1.Set_Expected_Message ("Do_Raise called: " & Raise_Code);
         Which_Exception := 2;

         ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (0));

         for I in ID_Array'range loop
            ID_Array(I) := TT_Array(I)'Identity;
         end loop;
         CXC7006_1.Set_Task_IDs (ID_Array);

         Expected_Cause := (others => ATT.Unhandled_Exception);
         CXC7006_1.Set_Expected_Causes (Expected_Cause);
         Expected_Exceptions := (Exception_2'Identity,
                                 Program_Error'Identity,
                                 Program_Error'Identity);
         CXC7006_1.Set_Expected_Exceptions (Expected_Exceptions);

         for I in ID_Array'range loop
            CXC7006_1.Set_Handler_Test (I, CXC7006_2.Test_Finalized'access, I);
               -- Effect is that when termination handler is called, it will
               -- call a procedure that makes sure that the local controlled
               -- object has been finalized before the handler was called.
         end loop;

         TT_Array (1).Which_Test (1, Body_Exception);
         TT_Array (2).Which_Test (2, Fin_Exception);
         TT_Array (3).Which_Test (3, Both);
         -- now wait for all tasks to terminate
      end;

      CXC7006_1.Test_All_Handlers_Called;

   end Test_5;

   Test_6:
      -- Make sure behavior is correct when a task propagates an exception
      -- during elaboration.
   declare
      Raise_Code : constant String := "sixth";
   begin
      CXC7006_1.Start_Test ("Test_6");
      CXC7006_1.Set_Expected_Message ("Do_Raise called: " & Raise_Code);
      Which_Exception := 1;
      CXC7006_1.Set_Expected_Exception (Exception_1'Identity);
      ATT.Set_Dependents_Fallback_Handler (CXC7006_1.The_Handler (0));

      declare

         function Set_Up_Task_ID (ID : ATI.Task_ID) return Integer is
         begin
            CXC7006_1.Set_Task_IDs ((1 => ID));
            CXC7006_1.Set_Expected_Causes ((1 => ATT.Unhandled_Exception));
            return 1;
         end Set_Up_Task_ID;

         function Will_Raise_Exception return Integer is
         begin
            Do_Raise (Raise_Code);
            return 2;
         end Will_Raise_Exception;

         function Should_Not_Get_Here return Integer is
         begin
            Report.Failed ("Elaboration continued after exception");
            return 3;
         end Should_Not_Get_Here;

         task TT;

         task body TT is
            V1 : Integer := Set_Up_Task_ID (TT'Identity);
            V2 : Integer := Will_Raise_Exception;
            V3 : Integer := Should_Not_Get_Here;
         begin
            null;
         end TT;

      begin
         null;
      exception
         when Tasking_Error =>
            null;
      end;

      CXC7006_1.Test_All_Handlers_Called;

   end Test_6;

   Report.Result;
end CXC7006;
