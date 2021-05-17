
with Report;
package body C460014_1 is

   procedure Define_Construct
    (Facade_Class_Ptr : in Facade_Class_Ptr_Type) is

      Facade_A_Ptr : constant Facade_A_Ptr_Type :=
                                         Facade_A_Ptr_Type (Facade_Class_Ptr);

      My_A : Data_A_Type renames Facade_A_Ptr.Data_A;
   begin
      if not My_A.A then
         Report.Comment ("Wrong value"); -- So My_A is not dead by 11.6(5).
      end if;
   end Define_Construct;

   procedure Define_Class_Construct
    (Facade_Class_Ptr : in Facade_Class_Ptr_Type) is

      Facade_Class_A_Ptr : constant Facade_A_Class_Ptr_Type :=
                                  Facade_A_Class_Ptr_Type (Facade_Class_Ptr);

   begin
      if Facade_Class_A_Ptr /= null and then
         (not Facade_Class_A_Ptr.Data_A.A) then
         Report.Comment ("Wrong value"); -- So the ptr is not dead by 11.6(5).
      end if;
   end Define_Class_Construct;

   Dummy_Root_Facade : aliased Root_Facade_Type := (Error_Code => 123);

   function Init_Root_Facade_Ptr return Root_Facade_Ptr_Type is
   begin
      return Dummy_Root_Facade'Access;
   end Init_Root_Facade_Ptr;

   Dummy_Facade_A    : aliased Facade_A_Type := (Error_Code => 123,
                                                 Data_A     => (A => True));

   function Init_Facade_A_Ptr     return Facade_A_Ptr_Type is
   begin
      return Dummy_Facade_A'Access;
   end Init_Facade_A_Ptr;

   Dummy_Facade_B    : aliased Facade_B_Type := (Error_Code => 234,
                                                 Data_A     => (A => True),
                                                 B          => 'P');

   function Init_Facade_B_Ptr     return Facade_B_Ptr_Type is
   begin
      return Dummy_Facade_B'Access;
   end Init_Facade_B_Ptr;

   function Init_Facade_Class_Ptr_with_Root return Facade_Class_Ptr_Type is
   begin
      return Dummy_Root_Facade'Access;
   end Init_Facade_Class_Ptr_with_Root;

   function Init_Facade_Class_Ptr_with_A return Facade_Class_Ptr_Type is
   begin
      return Dummy_Facade_A'Access;
   end Init_Facade_Class_Ptr_with_A;

   function Init_Facade_Class_Ptr_with_B return Facade_Class_Ptr_Type is
   begin
      return Dummy_Facade_B'Access;
   end Init_Facade_Class_Ptr_with_B;

end C460014_1;
