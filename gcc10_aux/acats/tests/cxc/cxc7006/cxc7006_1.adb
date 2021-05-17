
with Report;
package body CXC7006_1 is

   type Bool_Array is array (Natural range <>) of Boolean;
   type Test_Proc_Array is array (Natural range <>) of Handler_Test_Procedure;
   type Int_Array is array (Natural range <>) of Integer;

   type Task_ID_Array_Acc is access all Task_ID_Array;
   type Cause_Array_Acc is access all Cause_Array;
   type Handler_ID_Array_Acc is access all Handler_ID_Array;
   type Bool_Array_Acc is access all Bool_Array;
   type Test_Proc_Array_Acc is access all Test_Proc_Array;
   type Int_Array_Acc is access all Int_Array;
   type Exception_Array_Acc is access all Exception_Array;

   Test_Name : String_Acc;
   ID_Array : Task_ID_Array_Acc;
   Expected_Cause : Cause_Array_Acc;
   Expected_Handler : Handler_ID_Array_Acc;
   Handler_Called : Bool_Array_Acc;
   Which_Handler : Handler_ID_Array_Acc;
   Expected_Message : String_Acc;
   Expected_Exception : AE.Exception_ID;
   Expected_Exceptions : Exception_Array_Acc;
      -- if null, then exceptions are checked against Expected_Exception
   Test_Procs : Test_Proc_Array_Acc;
   Test_Proc_Params : Int_Array_Acc;

   procedure Start_Test (Name : String) is
   begin
      Report.Comment ("Starting test: " & Name);
      Test_Name := new String' (Name);
      ID_Array := null;
      Expected_Cause := null;
      Handler_Called := null;
      Expected_Handler := null;
      Expected_Message := null;
      Test_Procs := null;
      Test_Proc_Params := null;
   end Start_Test;

   procedure Set_Task_IDs (IDs : Task_ID_Array) is
   begin
      ID_Array := new Task_ID_Array' (IDs);
      Handler_Called := new Bool_Array (IDs'range);
      Handler_Called.all := (others => False);
      Which_Handler := new Handler_ID_Array (IDs'range);
      Which_Handler.all := (others => 0);
      Expected_Handler := new Handler_ID_Array (IDs'range);
      Expected_Handler.all := (others => 0);
      Test_Procs := new Test_Proc_Array (IDs'range);
      Test_Procs.all := (others => null);
      Test_Proc_Params := new Int_Array (IDs'range);
   end Set_Task_IDs;

   procedure Set_Expected_Causes (Causes : Cause_Array) is
   begin
      Expected_Cause := new Cause_Array' (Causes);
   end Set_Expected_Causes;

   procedure Set_Expected_Handlers (IDs : Handler_ID_Array) is
   begin
      Expected_Handler.all := IDs;
   end Set_Expected_Handlers;

   procedure Set_Expected_Message (Message : String) is
   begin
      Expected_Message := new String' (Message);
   end Set_Expected_Message;

   procedure Set_Expected_Exception (ID : AE.Exception_ID) is
   begin
      Expected_Exception := ID;
      Expected_Exceptions := null;
   end Set_Expected_Exception;

   procedure Set_Expected_Exceptions (IDs : Exception_Array) is
   begin
      Expected_Exceptions := new Exception_Array' (IDs);
   end Set_Expected_Exceptions;

   procedure Set_Handler_Test (Index     : in Integer;
                               Test_Proc : in Handler_Test_Procedure;
                               Param     : in Integer) is
   begin
      if Index in Test_Procs'range then
         Test_Procs (Index) := Test_Proc;
         Test_Proc_Params (Index) := Param;
      end if;
   end Set_Handler_Test;

   protected PT is
      procedure Handler_0
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence);
      procedure Handler_1
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence);
      procedure Handler_2
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence);
      procedure Handler_3
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence);
   end PT;

   function The_Handler (Which : Handler_ID) return ATT.Termination_Handler is
   begin
      case Which is
         when 0 => return PT.Handler_0'access;
         when 1 => return PT.Handler_1'access;
         when 2 => return PT.Handler_2'access;
         when 3 => return PT.Handler_3'access;
      end case;
   end The_Handler;

   protected body PT is

      procedure Handler (ID    : in Handler_ID;
                         Cause : in Ada.Task_Termination.Cause_Of_Termination;
                         T     : in Ada.Task_Identification.Task_ID;
                         X     : in Ada.Exceptions.Exception_Occurrence) is
         use type ATT.Cause_Of_Termination;
         use type ATI.Task_ID;
         use type AE.Exception_Occurrence;
         use type AE.Exception_ID;
         OK : Boolean;
         Err_Msg : String_Acc;
      begin
         for I in ID_Array'range loop
            if T = ID_Array (I) then
               if Handler_Called (I) then
                  Report.Failed
                     (Test_Name.all & ": Handler called twice for same task");
               end if;
               Handler_Called (I) := True;
               Which_Handler (I) := ID;
               if Cause /= Expected_Cause (I) then
                  Report.Failed
                     (Test_Name.all & ": Handler called with wrong Cause");
               end if;
               if Cause = ATT.Unhandled_Exception then
                  if AE.Exception_Identity(X) = AE.Null_ID then
                     Report.Failed (Test_Name.all &
                        ": Unhandled_Exception handler called with " &
                          "null occurrence");
                  elsif (Expected_Exceptions = null and then
                         AE.Exception_Identity (X) /= Expected_Exception)
                             or else
                        (Expected_Exceptions /= null and then
                         AE.Exception_Identity (X) /= Expected_Exceptions (I))
                             then
                     Report.Failed (Test_Name.all &
                        ": Unhandled_Exception occurrence has wrong exception");
                  elsif AE.Exception_Identity (X) /= Program_Error'Identity
                           and then
                        AE.Exception_Message (X) /= Expected_Message.all then
                     Report.Failed (Test_Name.all &
                        ": Unhandled_Exception occurrence has wrong message");
                  end if;
               else
                  if AE.Exception_Identity(X) /= AE.Null_ID then
                     Report.Failed (Test_Name.all &
                         ": Normal or Abnormal handler called with " &
                           "non-null occurrence");
                  end if;
               end if;
               if Test_Procs (I) /= null then
                  Test_Procs (I).all (Test_Proc_Params (I), OK, Err_Msg);
                  if not OK then
                     Report.Failed (Test_Name.all & ": " & Err_Msg.all);
                  end if;
               end if;
            end if;
         end loop;
      end Handler;

      procedure Handler_0
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence) is
      begin
         Handler (0, Cause, T, X);
      end Handler_0;

      procedure Handler_1
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence) is
      begin
         Handler (1, Cause, T, X);
      end Handler_1;

      procedure Handler_2
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence) is
      begin
         Handler (2, Cause, T, X);
      end Handler_2;

      procedure Handler_3
          (Cause : in Ada.Task_Termination.Cause_Of_Termination;
           T     : in Ada.Task_Identification.Task_ID;
           X     : in Ada.Exceptions.Exception_Occurrence) is
      begin
         Handler (3, Cause, T, X);
      end Handler_3;

   end PT;

   procedure Test_All_Handlers_Called is
      Not_Called : Boolean := False;
   begin
      for I in Handler_Called'range loop
         if not Handler_Called (I) then
            if not Not_Called then
               Report.Failed (Test_Name.all &
                  ": Termination handler not called for all tasks");
               Not_Called := True;
            end if;
         elsif Which_Handler (I) /= Expected_Handler (I) then
            Report.Failed (Test_Name.all &
               ": Wrong handler called: expected " &
               Integer'Image (Expected_Handler (I)) & ", got " &
               Integer'Image (Which_Handler (I)));
         end if;
      end loop;
   end Test_All_Handlers_Called;

end CXC7006_1;
