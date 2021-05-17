
with Report;
package body C460015_1 is

   protected body Some_Lock is
      procedure Set is
      begin
         Locked := True;
      end Set;

      procedure Clear is
      begin
         Locked := False;
      end Clear;

      function Is_Locked return Boolean is
      begin
         return Locked;
      end Is_Locked;
   end Some_Lock;

   procedure Define_Construct
    (Facade_Class_Ptr : in Facade_Class_Ptr_Type) is

      Facade_A_Ptr : constant Facade_A_Ptr_Type :=
                                         Facade_A_Ptr_Type (Facade_Class_Ptr);

      My_A : Some_Lock renames Facade_A_Ptr.Lock_A;
   begin
      if not My_A.Is_Locked then
         Report.Comment ("Wrong value"); -- So My_A is not dead by 11.6(5).
      end if;
   end Define_Construct;

   procedure Define_Class_Construct
    (Facade_Class_Ptr : in Facade_Class_Ptr_Type) is

      Facade_Class_A_Ptr : constant Facade_A_Class_Ptr_Type :=
                                  Facade_A_Class_Ptr_Type (Facade_Class_Ptr);

   begin
      if Facade_Class_A_Ptr /= null and then
         (not Facade_Class_A_Ptr.Lock_A.Is_Locked) then
         Report.Comment ("Wrong value"); -- So the ptr is not dead by 11.6(5).
      end if;
   end Define_Class_Construct;

   Dummy_Root_Facade : aliased Root_Facade_Type := (Error_Code => 123);

   Dummy_Facade_A    : aliased Facade_A_Type;

   Dummy_Facade_B    : aliased Facade_B_Type;

   function Init_Facade_Class_Ptr_with_Root return Facade_Class_Ptr_Type is
   begin
      return Dummy_Root_Facade'Access;
   end Init_Facade_Class_Ptr_with_Root;

   function Init_Facade_Class_Ptr_with_A return Facade_Class_Ptr_Type is
   begin
      Dummy_Facade_A.Error_Code := 235;
      Dummy_Facade_A.Lock_A.Set;
      return Dummy_Facade_A'Access;
   end Init_Facade_Class_Ptr_with_A;

   function Init_Facade_Class_Ptr_with_B return Facade_Class_Ptr_Type is
   begin
      Dummy_Facade_B.Error_Code := 987;
      Dummy_Facade_B.Lock_A.Set;
      Dummy_Facade_B.B := 'Z';
      return Dummy_Facade_B'Access;
   end Init_Facade_Class_Ptr_with_B;

end C460015_1;
