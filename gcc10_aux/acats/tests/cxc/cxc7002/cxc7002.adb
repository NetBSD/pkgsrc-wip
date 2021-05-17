
------------------------------------------------------------------

with ImpDef;
with Report;
with Ada.Task_Identification;
with Ada.Task_Attributes;
with CXC7002_0;  use type CXC7002_0.Int_Array;
with CXC7002_1;
procedure CXC7002 is
   Verbose : constant Boolean := False;

   package TID renames Ada.Task_Identification;
   generic package TA  renames Ada.Task_Attributes;
   package ATA renames CXC7002_1;
   package ITA is new TA (Integer, 321);
begin
   Report.Test ("CXC7002",
                "Check the package Task_Attributes");

   -- make sure a copy was made of the initial value for ATA.
   -- The following value should not get used as the initial
   -- value for the local task Check_It.
   CXC7002_0.Countdown := (7,6,5);

   declare
      task Check_It is
         entry Get_Id (Id : out TID.Task_Id);
         entry Ok_To_Terminate;
      end Check_It;

      task body Check_It is
         -- retrieves attribute value for the current task.
	 -- make sure that it is the default value.
         Val : Integer := ITA.Value;
         Handle : ATA.Attribute_Handle;
      begin
         if Val /= 321 then
            Report.Failed ("Check_It - initial value was" &
                           Integer'Image (Val) &
                           " expected 321");
         elsif Verbose then
            Report.Comment ("Check_It - initial value ok");

         end if;
         ITA.Set_Value (135);

	 -- get a handle to the ATA attribute for the current task.
	 -- make sure the attribute has the default value.
         Handle := ATA.Reference;
         if Handle.all /= (3,2,1) then
            Report.Failed ("Check_It - initial ATA value" &
                CXC7002_0.Small_Integer'Image (Handle(1)) &
                CXC7002_0.Small_Integer'Image (Handle(2)) &
                CXC7002_0.Small_Integer'Image (Handle(3)) &
                " expected 3 2 1");               
         end if;
         Handle.all := (2,4,6);

         accept Get_Id (Id : out TID.Task_Id) do
            Id := TID.Current_Task;
         end Get_Id;
         accept Ok_To_Terminate;
      end Check_It;
      
      Check_It_TID : TID.Task_ID;
      T1_TID : TID.Task_ID;
      T2_TID : TID.Task_ID;
      Null_TID : TID.Task_ID;
      XI : Integer;
      XA : CXC7002_0.Int_Array;
      Handle_T1_ATA : ATA.Attribute_Handle;
      Handle_T2_ATA : ATA.Attribute_Handle;
   begin
      Check_It.Get_Id (Check_It_TID);
      CXC7002_0.T1.Get_Id (T1_TID);
      CXC7002_0.T2.Get_Id (T2_TID);

      -- don't make it obvious that Null_TID is null
      if Report.Ident_Bool (False) then
         -- never executed
         Null_TID := Check_It_TID;
      else
         Null_TID := TID.Null_Task_ID;
      end if;

      -- check the values that were set inside Check_It
      XA := ATA.Value (Check_It_TID);
      XI := ITA.Value (Check_It_TID);

      if XA = (2,4,6) then
         if Verbose then
            Report.Comment ("Check_It 246 ok");
         end if;
      else
         Report.Failed ("Expected Check_It values 2,4,6;  found" &
              CXC7002_0.Small_Integer'Image (XA(1)) &
              CXC7002_0.Small_Integer'Image (XA(2)) &
              CXC7002_0.Small_Integer'Image (XA(3)) );
      end if;
  
      if XI /= 135 then
         Report.Failed ("Expected Check_It value 135; found" &
              Integer'Image (XI));
      elsif Verbose then
         Report.Comment ("Check_It 135 ok");
      end if;


      -- check the initial values for the tasks that were created
      -- before the attributes were created

      XA := ATA.Value (T1_TID);
      if XA /= (3, 2, 1) then
         Report.Failed ("Expected T1 initial values 3,2,1; found" &     
              CXC7002_0.Small_Integer'Image (XA(1)) &
              CXC7002_0.Small_Integer'Image (XA(2)) &
              CXC7002_0.Small_Integer'Image (XA(3)) );
      elsif Verbose then
         Report.Comment ("T1 321 ok");
      end if;

      XI := ITA.Value (T2_TID);
      if XI /= 321 then
         Report.Failed ("Expected T2 initial value 321  found" &
              Integer'Image (XI));
      elsif Verbose then
         Report.Comment ("T2 321 ok");
      end if;

      -- restore the initial value to Check_It and then check
      -- that the value is correct
      ATA.Reinitialize (Check_It_TID);

      XA := ATA.Value (Check_It_TID);
      if XA /= (3, 2, 1) then
         Report.Failed ("Expected Check_It reinitialized; found" &     
              CXC7002_0.Small_Integer'Image (XA(1)) &
              CXC7002_0.Small_Integer'Image (XA(2)) &
              CXC7002_0.Small_Integer'Image (XA(3)) );
      elsif Verbose then
         Report.Comment ("reinitialize ok");
      end if;

      -- check setting attributes for environment task
      ITA.Set_Value (271);
      if ITA.Value /= 271 then
         Report.Failed ("environment task attributes");
      end if;

      -- check the operations on the library level tasks.
      -- Interleave the operations to make sure they are working
      -- on the proper attribute value.
      Handle_T1_ATA := ATA.Reference (T1_TID);
      Handle_T2_ATA := ATA.Reference (T2_TID);
      Handle_T1_ATA.all := (1,1,1);
      Handle_T2_ATA.all := (2,2,2);
      if ATA.Value (T1_TID) /= (1,1,1) then
	 Report.Failed ("library task t1 array attributes wrong");
      end if;
      if ATA.Value (T2_TID) /= (2,2,2) then
	 Report.Failed ("library task t2 array attributes wrong");
      end if;

      -- Reinitialize T1 but not T2 and check the values
      ATA.Reinitialize (T1_TID);
      if ATA.Value (T1_TID) /= (3,2,1) then
	 Report.Failed ("library task t1 array attributes wrong after reinit");
      end if;
      if ATA.Value (T2_TID) /= (2,2,2) then
         Report.Failed ("library task t2 array attributes wrong after reinit");
      end if;


      -- let the tasks terminate
      Check_It.Ok_To_Terminate;
      CXC7002_0.T1.Ok_To_Terminate;
      CXC7002_0.T2.Ok_To_Terminate;
      while not Check_It'Terminated loop
         delay ImpDef.Switch_To_New_Task;
      end loop;

      -- check the error conditions
      begin
         ITA.Set_Value (786, Check_It_TID);
         Report.Failed ("Tasking_Error expected");
      exception
         when Tasking_Error =>
             if Verbose then
                 Report.Comment ("Tasking_Error properly raised");
             end if;
         when others =>
             Report.Failed ("wrong exception raised. " &
                            "Tasking_Error expected");
      end;

      begin
         ITA.Set_Value (941, Null_TID);
         Report.Failed ("Program_Error expected");
      exception
         when Program_Error =>
             if Verbose then
                 Report.Comment ("Program_Error properly raised");
             end if;
         when others =>
             Report.Failed ("wrong exception raised. " &
                            "Program_Error expected");
 
      end;
   exception
      when others => Report.Failed ("unexpected exception");
   end;

   Report.Result;
end CXC7002;
