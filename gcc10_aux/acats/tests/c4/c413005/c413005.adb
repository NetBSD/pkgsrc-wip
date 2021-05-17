
with C413005P;
with Report;
procedure C413005 is

   Count : Natural := 1;

   generic
      with function Get return Integer;
      with procedure Set (Value : in Integer);
   procedure Check (Message : in String);

   procedure Check (Message : in String) is
   begin
      Set (Count);
      if Get /= Count then
         Report.Failed (Message & " - value wrong:" & Integer'Image(Get) &
            " should be" & Integer'Image(Count));
      end if;
      Count := Count + 2;
   end Check;

   Result1 : aliased C413005P.TP;
   Result2 : aliased C413005P.TP;
   Result_Count : Natural := 1;
   function Func return access C413005P.TP is
      -- This function changes the object it returns every other call;
      -- if extra calls are made to this function, the wrong object
      -- will be returned.
   begin
      Result_Count := Result_Count + 1;
      case Result_Count mod 4 is
         when 0 | 1 => return Result1'access;
         when 2 | 3 => return Result2'access;
         when others => raise Program_Error;
      end case;
   end Func;

begin
   Report.Test ("C413005", "Check that a prefixed view is the name of a " &
                           "subprogram (with the first parameter omitted " &
                           "from the profile) that can be renamed and " &
                           "passed as a generic formal parameter.");

   declare
      Obj1 : C413005P.TP;
      Obj2 : C413005P.TP;
   begin
      if Obj1.Get /= 999 then
         Report.Failed ("Simple func call - value wrong");
      end if;
      Obj1.Clear;
      Obj2.Class_Wide_Clear;
      if Obj1.Data /= 0 then
         Report.Failed ("Simple proc call - value wrong");
      end if;
      if Obj2.Data /= 0 then
         Report.Failed ("Simple class-wide proc call - value wrong");
      end if;
      Func.Clear;   -- Result2
      if Func.Get /= 0 then  -- Result2
         Report.Failed ("Func prefix calls - result wrong");
      end if;
      declare
         function My_Get return Integer renames Obj1.Get;
         function My_Prod (Value : Integer) return Integer renames Obj1.Prod;
         procedure My_Set (Value : in Integer) renames Obj1.Set;
         function Other_Get return Integer renames Obj2.Class_Wide_Get;
         procedure Other_Set (Value : in Integer) renames Obj2.Class_Wide_Set;
         function Func_Get return Integer renames Func.Get;
         procedure Func_Set (Value : in Integer) renames Func.Set;
      begin
         if My_Get /= 0 then
            Report.Failed ("Renames get - value wrong");
         end if;
         if Other_Get /= 0 then
            Report.Failed ("Renames class-wide get - value wrong");
         end if;
         if Func_Get /= 999 then -- Result1, initial value. (No call to
                                 -- Func here.)
            Report.Failed ("Renames func get - value wrong");
         end if;
         My_Set (14);
         Other_Set (92);
         Func_Set (31);
         if My_Get /= 14 then
            Report.Failed ("Renames set - value wrong");
         end if;
         if Other_Get /= 92 then
            Report.Failed ("Renames class-wide get - value wrong");
         end if;
         if Func_Get /= 31 then
            Report.Failed ("Renames func get - value wrong");
         end if;
         if My_Prod (3) /= 42 then
            Report.Failed ("Renames prod - value wrong");
         end if;
      end;
      declare
          procedure Check1 is new Check (Obj1.Class_Wide_Get,
                                         Obj1.Class_Wide_Set);
          procedure Check2 is new Check (Obj2.Get, Obj2.Set);
          procedure Check3 is new Check (Func.Class_Wide_Get,
                                         Func.Class_Wide_Set);
      begin
          Check1 ("Generic Obj1, try 1");
          Check2 ("Generic Obj2, try 1");
          Check3 ("Generic Func, try 1");
          Check2 ("Generic Obj2, try 2");
          Check3 ("Generic Func, try 2");
          Check1 ("Generic Obj1, try 2");
          Check2 ("Generic Obj2, try 3");
      end;
   end;
   Report.Result;
end C413005;
