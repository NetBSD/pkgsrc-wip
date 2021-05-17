

     --==================================================================--


with FC50A00;   -- Tagged (actual) type declarations.
with CC50A02_0; -- Generic stack abstraction.
with CC50A02_1; -- Generic stack testing procedure.

with Report;
procedure CC50A02 is

   --
   -- Pass a nondiscriminated tagged actual:
   --

   package   Count_Stacks  is new CC50A02_0 (FC50A00.Count_Type);
   procedure TC_Count_Test is new CC50A02_1 (FC50A00.Count_Type,
                                             Count_Stacks);
   Count_Stack : Count_Stacks.Stack;


   --
   -- Pass a discriminated tagged actual:
   --
 
   package   Person_Stacks  is new CC50A02_0 (FC50A00.Person_Type);
   procedure TC_Person_Test is new CC50A02_1 (FC50A00.Person_Type,
                                              Person_Stacks);
   Person_Stack : Person_Stacks.Stack;


   --
   -- Pass a class-wide actual:
   --
 
   package   People_Stacks  is new CC50A02_0 (FC50A00.Person_Type'Class);
   procedure TC_People_Test is new CC50A02_1 (FC50A00.Person_Type'Class,
                                              People_Stacks);
   People_Stack : People_Stacks.Stack;

begin
   Report.Test ("CC50A02", "Check that tagged actuals may be passed " &
                "to a formal (nontagged) private type");

   Report.Comment ("Testing definite tagged type..");
   TC_Count_Test  (Count_Stack,  FC50A00.TC_Count_Item);

   Report.Comment ("Testing indefinite tagged type..");
   TC_Person_Test (Person_Stack, FC50A00.TC_Person_Item);

   Report.Comment ("Testing class-wide type..");
   TC_People_Test (People_Stack, FC50A00.TC_VIPerson_Item);

   Report.Result;
end CC50A02;
