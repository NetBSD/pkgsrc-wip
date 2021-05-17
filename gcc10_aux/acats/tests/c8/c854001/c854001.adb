

     --==================================================================--

with C854001_0;
with C854001_1;  -- Subtype and associated operations.
use  C854001_1;

with Report;

procedure C854001 is
   Operand1  : Root_Subtype;
   Operand2  : Root_Subtype;
   Operand3  : Root_Subtype;
   Operand4  : Root_Subtype;
   Operand5  : Short_Int_Subtype := 55;
   Operand6  : Short_Int_Subtype := 46;
   Operand7  : Short_Int_Subtype;
   Operand8  : C854001_0.Tag_Type;         -- Both Operand8 & Operand9 have
   Operand9  : C854001_0.Tag_Type;         -- the same default values.

   -- Direct visibility to operator symbols
   use type C854001_0.Component;
   use type C854001_0.Short_Int;

begin
   Report.Test ("C854001", "Check that a renaming-as-body can be given " &
                           "in a package body to complete a subprogram " &
                           "declared in the package specification. "     &
                           "Check that calls to the subprogram invoke "  &
                           "the body of the renamed subprogram");

   --
   -- Only operations of the subtype are available.
   --

   Ren_Proc  (Operand1);
   if Operand1.Called /= C854001_0.Initial_Value then
      Report.Failed ("Error calling procedure Ren_Proc");
   end if;

   ---------------------------------------
   Same_Proc (Operand2);
   if Operand2.Called /= C854001_0.Op_Of_Type then
      Report.Failed ("Error calling procedure Same_Proc");
   end if;

   ---------------------------------------
   Operand3 := Ren_Func;
   if Operand3.Called /= C854001_0.Op_Of_Type then
      Report.Failed ("Error calling function Ren_Func");
   end if;

   ---------------------------------------
   Operand4 := Same_Func;
   if Operand4.Called /= C854001_0.Initial_Value then
      Report.Failed ("Error calling function Same_Func");
   end if;
   
   ---------------------------------------
   Operand7 := C854001_1."-" (Operand5, Operand6);
   if Operand7 /= 47 then
      Report.Failed ("Error calling function & ""-""");
   end if;

   ---------------------------------------
   Operand7 := Other_Name (Operand5, Operand6);
   if Operand7 /= 15 then
      Report.Failed ("Error calling function Other_Name");
   end if;

   ---------------------------------------
   -- Executes body of the overriding declaration in the private part
   -- of C854001_0.
   if User_Defined_Equal (Operand8, Operand9) then
      Report.Failed ("Error calling function User_Defined_Equal");
   end if;

   ---------------------------------------
   -- Executes predefined operation.
   if not C854001_0.Predefined_Equal (Operand8, Operand9) then
      Report.Failed ("Error calling function Predefined_Equal");
   end if;

   Report.Result;

end C854001;
