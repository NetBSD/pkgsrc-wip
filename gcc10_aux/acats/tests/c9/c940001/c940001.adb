
--===============================================================--

with Report;
with ImpDef;
with C940001_0;

procedure C940001 is

  type TC_Int_Type is range 0..2;
              -- range is very narrow so that erroneous execution may
              -- raise Constraint_Error

  type TC_Artifact_Type is record
     TC_Int : TC_Int_Type := 1;
     Number_of_Accesses : integer := 0;
  end record;

  TC_Artifact : TC_Artifact_Type;

  Sequence_Mgr : C940001_0.Token_Mgr_Prot_Unit;
    
  procedure Bump (Item : in out TC_Int_Type) is
    begin
      Item := Item + 1;
    exception
      when Constraint_Error =>
        Report.Failed ("Incremented without corresponding decrement");
      when others =>
        Report.Failed ("Bump raised Unexpected Exception");
   end Bump;

  procedure Decrement (Item : in out TC_Int_Type) is
    begin
      Item := Item - 1;
    exception
      when Constraint_Error =>
        Report.Failed ("Decremented without corresponding increment");
      when others =>
        Report.Failed ("Decrement raised Unexpected Exception");
    end Decrement;
    
    --==============--

  task type Network_Node_Type;

  task body Network_Node_Type is

    Slot_for_Token : C940001_0.Token_Type := C940001_0.Init_Token;

    begin
 
      -- Ask for token - if request is not granted, task will be queued
      Sequence_Mgr.Take (Slot_for_Token);        

      -- Task now has token and may perform its work

      --==========================--
      -- in this case, the work is to ensure that the test results
      -- are the expected ones!
      --==========================--
      Bump (TC_Artifact.TC_Int);   -- increment when request is granted
      TC_Artifact.Number_Of_Accesses := 
        TC_Artifact.Number_Of_Accesses + 1;
      if not C940001_0.Token_Value ( Slot_for_Token) then
        Report.Failed ("Incorrect results from entry Take");
      end if;
 
      -- give a chance for other tasks to (incorrectly) run
      delay ImpDef.Minimum_Task_Switch;

      Decrement (TC_Artifact.TC_Int); -- prepare to return token

      -- Task has completed its work and will return token

      Sequence_Mgr.Give (Slot_for_Token);   -- return token to sequence manager

      if c940001_0.Token_Value (Slot_for_Token) then
        Report.Failed ("Incorrect results from entry Give");
      end if;

    exception
      when others => Report.Failed ("Unexpected exception raised in task");

    end Network_Node_Type; 

    --==============--

begin

  Report.Test ("C940001", "Check that a protected object can control " &
                          "tasks by coordinating access to shared data");

  declare
     Node_1, Node_2, Node_3 : Network_Node_Type;
                           -- declare three tasks which will compete for
                           -- a single token, managed by Sequence Manager

  begin                    -- tasks start
    null;
  end; -- wait for all tasks to terminate before reporting result

  if TC_Artifact.Number_of_Accesses /= 3 then
    Report.Failed ("Not all tasks got through");
  end if;

  Report.Result;

end C940001;
