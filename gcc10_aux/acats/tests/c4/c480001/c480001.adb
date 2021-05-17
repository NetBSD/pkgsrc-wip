
with C480001_0;
with Report;
procedure C480001 is

   type Main_Level is new C480001_0.Root with null record;
   M_Obj : Main_Level;

   R_Obj : C480001_0.Root;

   function Test_Function (Subtest : in Natural;
                           Param   : in C480001_0.Root'Class)
      return C480001_0.Any_Root_Access is

      Id_Cnt : Natural := 1;
      type Nest is new C480001_0.Root with record
         Id : Natural := 1;
      end record;

      overriding
      function Val (Obj : in Nest) return Natural;

      overriding
      procedure Bump (Obj : in out Nest) is
      begin
         Set_Val (Obj, Val(Obj) + Subtest/2);
      end Bump;

      Saved_Id  : Natural := 0;
      Saved_Val : Natural := 0;

      overriding
      function Val (Obj : in Nest) return Natural is
         -- A memo function version of Spin.
      begin
         if Obj.Id = Saved_Id then
            return Saved_Val;
         else
            Saved_Val := C480001_0.Val (C480001_0.Root (Obj));
            Saved_Id  := Obj.Id;
            return Saved_Val;
         end if;
      end Val;

      Nest_Obj : Nest := (C480001_0.Root_Obj with Id => Id_Cnt + 1);

      P : C480001_0.Any_Root_Access;

      type Local_Any_Root_Access is access C480001_0.Root'Class;
      L : Local_Any_Root_Access;

      function Nest_Test (N       : in Natural;
                          Param   : in C480001_0.Root'Class)
         return C480001_0.Any_Root_Access is
         type Dbl is new C480001_0.Root with null record;
         D_Obj : Dbl;
      begin
         case N is
            when 1 =>
               -- Recursively pass the parameter to the original
               -- test routine. Whether this raises an exception
               -- depends on the parameter.
               return Test_Function (Subtest => 1, Param => Param);
            when 2 =>
               P := new C480001_0.Root'Class'(Param);
               -- Whether this raises an exception depends on the
               -- parameter.
               return P;
            when 3 =>
               -- Recursively pass the parameter to the original
               -- test routine. Whether this raises an exception
               -- depends on the parameter.
               return Test_Function (Subtest => 2, Param => Param);

            when 4 =>
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(R_Obj));   -- OK.
               return P;
            when 5 =>
               -- Recursively pass R_Obj to the original test routine.
               return Test_Function (Subtest => 1,
                   Param => C480001_0.Root'Class(R_Obj)); -- OK.
            when 6 =>
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(D_Obj));   -- Program_Error.
               return P;
            when 7 =>
               -- Recursively pass D_Obj to the original test routine.
               return Test_Function (
                         Subtest => 1,
                         Param => C480001_0.Root'Class(D_Obj));
                                    -- raises Program_Error.
            when 8 =>
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(M_Obj));   -- Program_Error.
               return P;
            when 9 =>
               -- Recursively pass M_Obj to the original test routine.
               return Test_Function (
                         Subtest => 1,
                         Param => C480001_0.Root'Class(M_Obj));
                                    -- raises Program_Error.
            when 10 =>
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(Nest_Obj));-- Program_Error.
               return P;
            when 11 =>
               -- Recursively pass D_Obj to the original test routine.
               return Test_Function (
                         Subtest => 1,
                         Param => C480001_0.Root'Class(Nest_Obj));
                                    -- raises Program_Error.

            when 12 =>
               L := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(D_Obj));   -- Program_Error.
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(R_Obj));   -- Always OK.
               return P;

            when 13 =>
               L := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(M_Obj));   -- OK.
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(R_Obj));   -- Always OK.
               return P;

            when 14 =>
               L := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(Nest_Obj));-- OK.
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(R_Obj));   -- Always OK.
               return P;

            when 15 =>
               L := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(R_Obj));   -- OK.
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(R_Obj));   -- Always OK.
               return P;

            when others => raise Program_Error;
         end case;
      end Nest_Test;

   begin
      declare
         type Inner is new C480001_0.Root with null record;
         I_Obj : Inner;
      begin
         case Subtest is
            when 1 => -- Use the parameter:
               P := new C480001_0.Root'Class'(Param);
                  -- Depends on the tag of the parameter.
               return P;
            when 2 =>
               L := new C480001_0.Root'Class'(Param);
                   -- Depends on the tag of the parameter.
               P := new C480001_0.Root'Class'(
                          C480001_0.Root'Class(R_Obj));   -- Always OK.
               return P;

            when 3 .. 5 =>
               return Nest_Test (Subtest - 2,
                         C480001_0.Root'Class(R_Obj)); -- OK.

            when 6 .. 8 =>
               return Nest_Test (Subtest - 5, C480001_0.Root'Class(M_Obj));
                   -- Program_Error for subtests 6 & 7, OK for subtest 8.

            when 9 .. 11 =>
               return Nest_Test (Subtest - 8, C480001_0.Root'Class(Nest_Obj));
                   -- Program_Error for subtests 9 & 10, OK for subtest 11.

            when 12 .. 23 =>
               return Nest_Test (Subtest - 8, C480001_0.Root'Class(R_Obj));

            when others => raise Program_Error;
         end case;
      end;
   end Test_Function;

   Base : constant Natural := 20;

   procedure Check_Result (Fails    : in Boolean;
                           Subtest  : in Natural) is
   begin
      declare
         Obj : C480001_0.Any_Root_Access := Test_Function(Subtest, R_Obj);
      begin
         if Fails then
            Report.Failed ("Test function did not raise Program_Error " &
                "as expected (" & Natural'Image(Subtest) & ')');
         end if;
         C480001_0.Set_Val (Obj.all, Base);
         C480001_0.Bump (Obj.all);
         if C480001_0.Val (Obj.all) /= Base + 1 then
            Report.Failed ("Unexpected value (" &
                Natural'Image(Subtest) & ')');
         end if;
      end;
   exception
      when Program_Error =>
         if Fails then
            null;
            --Report.Comment ("Test function raised Program_Error " &
            --    "as expected (" & Natural'Image(Subtest) & ')');
         else
            Report.Failed ("Test function unexpectedly raised " &
                "Program_Error (" & Natural'Image(Subtest) & ')');
         end if;
   end Check_Result;

begin
   Report.Test ("C480001", "If the designated type of an initialized " &
                           "allocator is class-wide, check that " &
                           "Program_Error is raised if the master of the " &
                           "type of the tag of the value of the qualified " &
                           "expression of the allocator does not include " &
                           "the elaboration of the type of the allocator. " &
                           "Case 1: Nested subprograms");

   Check_Result (Fails => False, Subtest => 1);

   Check_Result (Fails => False, Subtest => 2);

   Check_Result (Fails => False, Subtest => 3);

   Check_Result (Fails => False, Subtest => 4);

   Check_Result (Fails => False, Subtest => 5);

   Check_Result (Fails => True, Subtest => 6);

   Check_Result (Fails => True, Subtest => 7);

   Check_Result (Fails => False, Subtest => 8);

   Check_Result (Fails => True, Subtest => 9);

   Check_Result (Fails => True, Subtest => 10);

   Check_Result (Fails => False, Subtest => 11);

   Check_Result (Fails => False, Subtest => 12);

   Check_Result (Fails => False, Subtest => 13);

   Check_Result (Fails => True, Subtest => 14);

   Check_Result (Fails => True, Subtest => 15);

   Check_Result (Fails => True, Subtest => 16);

   Check_Result (Fails => True, Subtest => 17);

   Check_Result (Fails => True, Subtest => 18);

   Check_Result (Fails => True, Subtest => 19);

   Check_Result (Fails => True, Subtest => 20);

   Check_Result (Fails => False, Subtest => 21);

   Check_Result (Fails => False, Subtest => 22);

   Check_Result (Fails => False, Subtest => 23);

   Report.Result;
end C480001;
