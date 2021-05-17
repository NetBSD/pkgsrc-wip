

     --==================================================================--


with FC50A00;   -- Tagged (actual) type declarations.
with CC50A01_0; -- Generic stack abstraction.
with CC50A01_1; -- Generic stack testing procedure.
with CC50A01_2;
with CC50A01_3;

with Report;
procedure CC50A01 is

   package Count_Stacks  renames CC50A01_2;
   package Person_Stacks renames CC50A01_3;


   procedure TC_Count_Test is new CC50A01_1 (FC50A00.Count_Type,
                                             FC50A00.TC_Default_Count,
                                             Count_Stacks);
   Count_Stack : Count_Stacks.Stack;

 
   procedure TC_Person_Test is new CC50A01_1 (FC50A00.Person_Type,
                                              FC50A00.TC_Default_Person,
                                              Person_Stacks);
   Person_Stack : Person_Stacks.Stack;

begin
   Report.Test ("CC50A01", "Check that a formal parameter of a " &
                "library-level generic unit may be a formal tagged " &
                "private type");

   Report.Comment ("Testing definite tagged type..");
   TC_Count_Test  (Count_Stack,  FC50A00.TC_Count_Item);

   Report.Comment ("Testing indefinite tagged type..");
   TC_Person_Test (Person_Stack, FC50A00.TC_Person_Item);

   Report.Result;
end CC50A01;
