
--------------------------------------------------------------------------

with Report;
with CXC7001_0;
with Ada.Task_Identification;
procedure CXC7001 is
  use type Ada.Task_Identification.Task_ID;

  -- the type Indicators is used to enumerate, and then track the various
  -- locations for task objects and their unique identities.

  type Indicators is (Simple_Object, Array_Element_1, Array_Element_2,
                      Embedded_Object_1, Embedded_Object_2,
                      Designated_Object_1, Designated_Object_2,
                      Main_Task, No_Task);

  type ID_List is array(Indicators) of Ada.Task_Identification.Task_ID;

  The_Ids : ID_List;

  -- the task objects:

  The_Simple_Object: CXC7001_0.Task_Type;

  type Task_Array is array(1..2) of CXC7001_0.Task_Type;
  The_Task_Array : Task_Array;

  type Containing_Record is record
    The_Embedded_Object: CXC7001_0.Task_Type;
  end record;
  The_Record_1, The_Record_2 : Containing_Record;

  The_Designator_1 : CXC7001_0.Task_Ref;
  The_Designator_2 : CXC7001_0.Task_Ref := new CXC7001_0.Task_Type;

  -- test support software:

  procedure TC_Match_States(A_Task: in CXC7001_0.Task_Type;
                            Item  : in Indicators) is
    -- check that the calls to the package interface return the same values
    -- as the corresponding attributes
    Which : Ada.Task_Identification.Task_ID;
  begin
    Which := The_IDs( Item );


    -- Terminated and Callable can change values on a multiprocessor
    -- implementation. However, they can change values only once and
    -- only in a particular direction; therefore, we test the values
    -- and direction of change.

    declare
       T1 : constant Boolean := Ada.Task_Identification.Is_Terminated(Which);
       T2 : constant Boolean := A_Task'Terminated;
       T3 : constant Boolean := Ada.Task_Identification.Is_Terminated(Which);
    begin
       -- Terminated can only change from False to True, if it changes at all.
       if not ((T1 <= T2) and (T2 <= T3)) then
          Report.Failed("Terminated value doesn't match for " &
                    Ada.Task_Identification.Image( Which ));
       end if;
    end;

    declare
       C1 : constant Boolean := Ada.Task_Identification.Is_Callable(Which);
       C2 : constant Boolean := A_Task'Callable;
       C3 : constant Boolean := Ada.Task_Identification.Is_Callable(Which);
    begin
       -- Callable can only change from True to False, if it changes at all.
       if not ((C1 >= C2) and (C2 >= C3)) then
          Report.Failed("Callable value doesn't match for " &
                    Ada.Task_Identification.Image( Which ));
       end if;
    end;

    if (A_Task'Identity /= Which)
       or (The_Ids(Item) /= Which) then
      Report.Failed("Identity values don't match for " &
                    Ada.Task_Identification.Image( Which ));
    end if;

  end TC_Match_States;

  procedure Check_Exception_Abort_Task is
  begin
    Ada.Task_Identification.Abort_Task( The_Ids(No_Task) );
    Report.Failed("Abort_Task(Null_ID) did not raise exception");
  exception
    when Program_Error => null; -- expected case
    when others => Report.Failed("wrong exception: Abort_Task(Null_ID)");
  end Check_Exception_Abort_Task;

  procedure Check_Exception_Is_Terminated is
  begin
    if Ada.Task_Identification.Is_Terminated( The_Ids(No_Task) ) then
      null;
    end if;
    Report.Failed("Is_Terminated(Null_ID) did not raise exception");
  exception
    when Program_Error => null; -- expected case
    when others =>Report.Failed("wrong exception: Is_Terminated(Null_ID)");
  end Check_Exception_Is_Terminated;

  procedure Check_Exception_Is_Callable is
  begin
    if Ada.Task_Identification.Is_Callable( The_Ids(No_Task) ) then
      null;
    end if;
    Report.Failed("Is_Callable(Null_ID) did not raise exception");
  exception
    when Program_Error => null; -- expected case
    when others => Report.Failed("wrong exception: Is_Callable(Null_ID)");
  end Check_Exception_Is_Callable;

begin  -- Main test procedure.

   Report.Test ("CXC7001", "Check package Ada.Task_Identification" );

   -- check for default values
   for TI in Indicators loop
     if The_Ids(TI) /= Ada.Task_Identification.Null_Task_Id then
       Report.Failed("Task_ID Array elements not correctly initialized");
     end if;
   end loop;

   -- check for Image of Null_Task_ID to be empty string
   if Ada.Task_Identification.Image( The_Ids(No_Task) ) /= "" then
     Report.Failed("Image for Null_Task_Id not null");
   end if;

   -- check more Null_Task_Id semantics
   Check_Exception_Abort_Task;
   Check_Exception_Is_Terminated;
   Check_Exception_Is_Callable;

------------------ gentle programmers, start your tasks...

   -- The_Simple_Object activated at end of scope elaboration
   -- The_Task_Array(1..2) activated at end of scope elaboration
   -- The_Record_1, The_Record_2 activated at end of scope elaboration
   -- The_Designator_2 activated at default value assignment

   The_Designator_1  := new CXC7001_0.Task_Type;

   -- set the ID values
   The_Ids(Main_Task) := Ada.Task_Identification.Current_Task;

   The_Simple_Object.My_ID(The_Ids(Simple_Object));

   The_Task_Array(1).My_ID(The_Ids(Array_Element_1));
   The_Task_Array(2).My_ID(The_Ids(Array_Element_2));

   The_Record_1.The_Embedded_Object.My_ID(The_Ids(Embedded_Object_1));
   The_Record_2.The_Embedded_Object.My_ID(The_Ids(Embedded_Object_2));

   The_Designator_1.My_ID(The_Ids(Designated_Object_1));
   The_Designator_2.My_ID(The_Ids(Designated_Object_2));

   for TI in Indicators'First .. Main_Task loop
     if The_Ids(TI) = Ada.Task_Identification.Null_Task_Id then
       Report.Failed(Indicators'Image(TI) & " equals Null_Task_Id");
     end if;
     for TX in Indicators'Succ(TI) .. Main_Task loop
       if The_Ids(TI) = The_Ids(TX) then
         Report.Failed("same ID for "
                       & Indicators'Image(TI) & " and "
                       & Indicators'Image(TX) );
       end if;
     end loop;

     if Ada.Task_Identification.Image( The_Ids(TI) ) = "" then
       Report.Failed(Indicators'Image(TI) & " has no image");
     end if;

   end loop;

------------------ check states
   TC_Match_States(The_Simple_Object, Simple_Object);
   TC_Match_States(The_Task_Array(1), Array_Element_1);
   TC_Match_States(The_Task_Array(2), Array_Element_2);
   TC_Match_States(The_Record_1.The_Embedded_Object, Embedded_Object_1);
   TC_Match_States(The_Record_2.The_Embedded_Object, Embedded_Object_2);
   TC_Match_States(The_Designator_1.all, Designated_Object_1);
   TC_Match_States(The_Designator_2.all, Designated_Object_2);

------------------ transition several tasks to "completed"
   The_Simple_Object.Shutdown;

   -- The_Task_Array(1).Stay_Up;
   The_Task_Array(2).Shutdown;

   -- The_Record_1.The_Embedded_Object.Stay_Up;
   The_Record_2.The_Embedded_Object.Shutdown;

   The_Designator_1.Shutdown;
   -- The_Designator_2.Stay_Up;

------------------ check states
   TC_Match_States(The_Simple_Object, Simple_Object);
   TC_Match_States(The_Task_Array(1), Array_Element_1);
   TC_Match_States(The_Task_Array(2), Array_Element_2);
   TC_Match_States(The_Record_1.The_Embedded_Object, Embedded_Object_1);
   TC_Match_States(The_Record_2.The_Embedded_Object, Embedded_Object_2);
   TC_Match_States(The_Designator_1.all, Designated_Object_1);
   TC_Match_States(The_Designator_2.all, Designated_Object_2);

------------------ transition several tasks to "abnormal"

   begin
     -- should have "no effect"
     Ada.Task_Identification.Abort_Task( The_Ids(Simple_Object) );
   exception
     when others => Report.Failed("A.TI.AT( SO ) - didn't have no effect");
   end;

   -- should have "an effect"
   Ada.Task_Identification.Abort_Task( The_Ids(Array_Element_1) );

   -- The_Record_1.The_Embedded_Object.Stay_Up;

   abort The_Designator_2.all;

------------------ check states
   TC_Match_States(The_Simple_Object, Simple_Object);
   TC_Match_States(The_Task_Array(1), Array_Element_1);
   TC_Match_States(The_Task_Array(2), Array_Element_2);
   TC_Match_States(The_Record_1.The_Embedded_Object, Embedded_Object_1);
   TC_Match_States(The_Record_2.The_Embedded_Object, Embedded_Object_2);
   TC_Match_States(The_Designator_1.all, Designated_Object_1);
   TC_Match_States(The_Designator_2.all, Designated_Object_2);

   Report.Result;

end CXC7001;
