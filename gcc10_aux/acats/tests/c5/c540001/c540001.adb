
     --==================================================================--

with Report;
with C540001_1;
with C540001_2;
with C540001_3;
with C540001_4;
with C540001_5;

procedure C540001 is
   type Value is range 1 .. 5;

begin
   Report.Test ("C540001", "Check that an expression in a case statement " &
                "may be of a generic formal type.  Check that a function " &
                "call may be used as a case statement expression.  Check " &
                "that a call to a generic formal function may be used as " &
                "a case statement expression.  Check that a call to an "   &
                "inherited function may be used as a case statement "      &
                "expression");

   Generic_Formal_Object_Subtest:
   begin
      declare
         One  : Value := 1;
         package One_Pck is new C540001_2 (Value, One);
         use One_Pck;
         EObj : Enum;
      begin
         Assign_Enum (EObj);
         if EObj /= Alpha then
            Report.Failed ("Incorrect result for value of one in generic" &
                           "formal object subtest");
         end if;
      end;

      declare
         Five : Value := 5;
         package Five_Pck is new C540001_2 (Value, Five);
         use Five_Pck;
         EObj : Enum;
      begin
         Assign_Enum (EObj);
         if EObj /= Theta then
            Report.Failed ("Incorrect result for value of five in generic" &
                           "formal object subtest");
         end if;
      end;

   end Generic_Formal_Object_Subtest;

   Instantiated_Generic_Function_Subtest:
   declare
      type New_Enum_Type is new C540001_1.Enum_Type;

      function Get_Enum_Value (P : C540001_1.Small_Num) 
        return New_Enum_Type is
      begin
         return New_Enum_Type'Val (P);
      end Get_Enum_Value;

      function Val_Func is new C540001_3 
        (Formal_Enum_Type => New_Enum_Type, 
         Formal_Func      => Get_Enum_Value);

      procedure Assign_Num (P : in out C540001_1.Small_Num) is
      begin
         case Val_Func (P) is                         -- Case expression is
                                                      -- instantiated generic
             when New_Enum_Type (C540001_1.Eh) |      -- function.
                  New_Enum_Type (C540001_1.Sea)   => P := 4;
             when New_Enum_Type (C540001_1.Bee)   => P := 7;
             when others                          => P := 9;
         end case;

      end Assign_Num;

      SNObj  : C540001_1.Small_Num;

   begin
      SNObj := 0;
      Assign_Num (SNObj);       
      if SNObj /= 4 then
         Report.Failed ("Incorrect result for value of zero in call to " &
                        "generic function subtest");
      end if;

      SNObj := 3;
      Assign_Num (SNObj);       
      if SNObj /= 9 then
         Report.Failed ("Incorrect result for value of three in call to " &
                        "generic function subtest");
      end if;

   end Instantiated_Generic_Function_Subtest;

   -- When a function call, a renaming of a function, or a call to an 
   -- inherited function is used in the case expressions, the choices 
   -- of the case statement only need to cover the values in the result 
   -- of the function.

   Function_Call_Subtest:
   declare
      MObj : C540001_1.Mixed := 'B';
      BObj : Boolean         := True;
      use type C540001_1.Mixed;
   begin
      C540001_1.Assign_Mixed (BObj, MObj);
      if MObj /= C540001_1.None then
         Report.Failed ("Incorrect result for value of true in function" &
                        "call subtest");
         end if;

      BObj := False;
      C540001_1.Assign_Mixed (BObj, MObj);
      if MObj /= C540001_1.'A' then
         Report.Failed ("Incorrect result for value of false in function" &
                        "call subtest");
      end if;

   end Function_Call_Subtest;

   Function_Renaming_Subtest:
   declare
      use C540001_1;
      function Rename_Get_Small_Int (P : Boolean) 
        return Small_Int renames Get_Small_Int;
      MObj : Mixed   := None;
      BObj : Boolean := False;
   begin
      case Rename_Get_Small_Int (BObj) is
          when 1 => MObj := 'A';
          when 2 => MObj := 'B';
          -- No others needed.
      end case;

      if MObj /= 'B' then
         Report.Failed ("Incorrect result for value of false in function" &
                        "renaming subtest");
      end if;

   end Function_Renaming_Subtest;

   Call_To_Generic_Formal_Function_Subtest:
   declare
      type New_Small_Int is new C540001_1.Small_Int;

      function Get_Int_Value return New_Small_Int is
      begin
         return New_Small_Int'First;
      end Get_Int_Value;

      package Int_Pck is new C540001_4 
        (Formal_Int_Type => New_Small_Int, 
         Formal_Func     => Get_Int_Value);

      use type C540001_1.Mixed;
      MObj : C540001_1.Mixed := C540001_1.None; 

   begin
      Int_Pck.Gen_Assign_Mixed (MObj); 
      if MObj /= C540001_1.'A' then
         Report.Failed ("Incorrect result in call to generic formal " &
                        "function subtest");
      end if;

   end Call_To_Generic_Formal_Function_Subtest;

   Call_To_Inherited_Function_Subtest:
   declare
      NTObj1 : C540001_5.New_Tagged := (C1 => C540001_1.Eh,
                                        C2 => C540001_1.'A');
      NTObj2 : C540001_5.New_Tagged := (C540001_1.Dee, C540001_1.'C');
      use type C540001_1.Mixed;
      use type C540001_1.Enum_Type;
   begin
      C540001_5.Assign_Tagged (NTObj1, NTObj2);
      if NTObj2.C1 /= C540001_1.Bee or  
         NTObj2.C2 /= C540001_1.'B' then
         Report.Failed ("Incorrect result in inherited function subtest");
      end if;

   end Call_To_Inherited_Function_Subtest;

   Report.Result;

end C540001;
