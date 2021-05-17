
with C650A01_Map, C650A01_Alerts, F650A00.P, F650A00.S, Report, Ada.Tags;
procedure C650A01 is
begin
   Report.Test ("C650A01", "Check that Constraint_Error is raised if the " &
                           "result subtype of the function is an anonymous " &
                           "access type designating a specific tagged " &
                           "type and the result value is not null and " &
                           "designates some other specific type");

   C650A01_Map.Clear_Map;

   -- Put the objects into the Map:
   C650A01_Map.Set_Item (Key =>  4, Item => C650A01_Alerts.Special'Access);
   C650A01_Map.Set_Item (Key => 15, Item => C650A01_Alerts.Practice'Access);
   C650A01_Map.Set_Item (Key => 66, Item => C650A01_Alerts.Trial'Access);

   -- Check that we can retrieve the items with access-to-classwide:
   declare
      PA : access F650A00.Alert'Class;
      TA : access F650A00.Alert'Class;
      SA : access F650A00.Alert'Class;
      NA : access F650A00.Alert'Class;
      use type Ada.Tags.Tag;
   begin
      PA := C650A01_Map.Get_Item (Key => 15);
      TA := C650A01_Map.Get_Item (Key => 66);
      SA := C650A01_Map.Get_Item (Key =>  4);
      NA := C650A01_Map.Get_Item (Key => 33); -- No item here.
      if PA.all'tag /= F650A00.P.Practice_Alert'tag or else
         PA.Alert_Time /= 8.0 then
          Report.Failed ("PA object has wrong value");
      end if;
      if TA.all'tag /= F650A00.P.Practice_Alert'tag or else
         TA.Alert_Time /= 0.0 then
          Report.Failed ("TA object has wrong value");
      end if;
      if SA.all'tag /= F650A00.S.Special_Alert'tag or else
         SA.Alert_Time /= 54.0 then
          Report.Failed ("SA object has wrong value");
      end if;
      if NA /= null then
          Report.Failed ("NA object has wrong value");
      end if;
      -- These are accesses to the actual objects: verify that for TA:
      TA.Set_Alert_Time (Time => 3.5);
      if C650A01_Alerts.Trial.Alert_Time /= 3.5 then
          Report.Failed ("TA object did not change");
      end if;
   end;

   -- OK, try retriving practice items.
   declare
      PA : access F650A00.P.Practice_Alert;
      SA : access F650A00.P.Practice_Alert;
      NA : access F650A00.P.Practice_Alert;
   begin
      begin
         PA := C650A01_Map.Get_Practice_Item (Key => 15);
         if PA.Alert_Time /= 8.0 then
            Report.Failed ("PA practice object has wrong value");
         end if;
      exception
         when Constraint_Error =>
             Report.Failed ("Get_Practice_Item of PA object raised exception");
      end;
      begin
         SA := C650A01_Map.Get_Practice_Item (Key => 4);
         Report.Failed ("Get_Practice_Item of Special object did not raise an " &
                        "exception");
      exception
         when Constraint_Error =>
             null;
      end;
      begin
         NA := C650A01_Map.Get_Practice_Item (Key => 54);
         if NA /= null then
            Report.Failed ("NA practice object has wrong value");
         end if;
      exception
         when Constraint_Error =>
             Report.Failed ("Get_Practice_Item of unused item raised exception");
      end;
   end;

   Report.Result;

end C650A01;
