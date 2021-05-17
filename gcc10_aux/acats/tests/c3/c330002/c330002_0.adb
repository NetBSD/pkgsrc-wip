
     --==================================================================--

with Report;
package body C330002_0 is  

   procedure Assign_Tag (A : out Tag_Type) is
   begin
      A := (3, "Bye");
   end Assign_Tag;

   ----------------------------------------------------------------------
   procedure Avoid_Optimization_and_Fail (P : Tag_Type; Msg : String) is
      Default : Tag_Type := (1, "!"); -- Unique value.
   begin                       
      if P = Default then       -- Both If branches can't do the same thing.
         Report.Failed  (Msg & ": Constraint_Error not raised");
      else                      -- Subtests should always select this path.
         Report.Failed ("Constraint_Error not raised " & Msg);
      end if;
   end Avoid_Optimization_and_Fail;

   ----------------------------------------------------------------------
   function  Tag_Value return Tag_Type is
      TO : Tag_Type := (4 , "ACVC");
   begin
      return TO;
   end Tag_Value;

   ----------------------------------------------------------------------
   function  Array_Value return Array_Type is
      IA : Array_Type := (20, 31);
   begin
      return IA;
   end Array_Value;

   ----------------------------------------------------------------------
   procedure Assign_Array (A : out Array_Type) is
   begin
      A := (84, 36);
   end Assign_Array;

end C330002_0;
