

     --===================================================================--


with CC54004_0;
with CC54004_1;
with CC54004_3;

with Report;
procedure CC54004 is
   TC_Low_Ptr, TC_Med_Ptr : CC54004_0.Alert_Ptr;
   TC_Low_Actual          : CC54004_1.Low_Alert;
   TC_Med_Actual          : CC54004_1.Medium_Alert;

   use type CC54004_0.TC_Code_Type;
begin
   Report.Test ("CC54004", "Check that the designated type of a generic " &
                "formal pool-specific access type may be class-wide");


   -- Create stack of elements:

   CC54004_3.TC_Create_Alert_Stack;


   -- Commence dispatching operations on stack elements:

   CC54004_3.Alert_Stacks.Process_Stack (CC54004_3.Alert_List);


   -- Pop "handled" alerts off stack:

   CC54004_3.Alert_Stacks.Pop (CC54004_3.Alert_List, TC_Med_Ptr);
   CC54004_3.Alert_Stacks.Pop (CC54004_3.Alert_List, TC_Low_Ptr);


   -- Verify results:

   if TC_Low_Ptr.all not in CC54004_1.Low_Alert    or else
      TC_Med_Ptr.all not in CC54004_1.Medium_Alert
   then
      Report.Failed ("Class-wide objects do not have expected tags");

   -- The explicit dereference of the "Pop"ed pointers results in views of
   -- the designated objects, the nominal subtypes of which are class-wide.
   -- In order to be able to reference the component TC_Code, these views
   -- must be converted to a specific type possessing that component.

   elsif CC54004_1.Low_Alert(TC_Low_Ptr.all).TC_Code    /= CC54004_0.Low    or
         CC54004_1.Medium_Alert(TC_Med_Ptr.all).TC_Code /= CC54004_0.Medium
   then
      Report.Failed ("Calls did not dispatch to expected operations");
   end if;

   Report.Result;
end CC54004;
