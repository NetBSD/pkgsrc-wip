

     --==================================================================--


with CC50001_0;  -- Tagged (actual) type declarations.
with CC50001_1;  -- Generic stack abstraction.

use  CC50001_0;  -- Overloaded "=" directly visible.

with Report;
procedure CC50001 is

   package Count_Stacks  is new CC50001_1 (CC50001_0.Count_Type);
   package Person_Stacks is new CC50001_1 (CC50001_0.Person_Type);

   User_Defined_Op_Called : Boolean;

begin
   Report.Test ("CC50001", "Check that, in an instance, each implicit "     &
                "declaration of a primitive subprogram of a formal tagged " &
                "private type declares a view of the corresponding "        &
                "predefined operator of the actual type (even if the "      &
                "operator has been overridden or hidden for the actual type)");

--
-- Test which "=" is called inside generic:
--

   User_Defined_Op_Called := False;

   Count_Stacks.Push (CC50001_0.TC_Count_Item,
                      User_Defined_Op_Called);


   if not User_Defined_Op_Called then
      Report.Failed ("User-defined ""="" not called inside generic for Count");
   end if;


   User_Defined_Op_Called := False;

   Person_Stacks.Push (CC50001_0.TC_Person_Item,
                       User_Defined_Op_Called);

   if not User_Defined_Op_Called then
      Report.Failed ("User-defined ""="" not called inside generic " &
                     "for Person");
   end if;


--
-- Test which "=" is called outside generic:
--

   User_Defined_Op_Called := False;

   User_Defined_Op_Called :=
     not (CC50001_0.TC_Count_Item = CC50001_0.TC_Count_Item);

   if not User_Defined_Op_Called then
      Report.Failed ("User-defined ""="" not called outside generic "&
                     "for Count");
   end if;


   User_Defined_Op_Called := False;

   User_Defined_Op_Called :=
     not (CC50001_0.TC_Person_Item = CC50001_0.TC_Person_Item);

   if not User_Defined_Op_Called then
      Report.Failed ("User-defined ""="" not called outside generic "&
                     "for Person");
   end if;


   Report.Result;
end CC50001;
