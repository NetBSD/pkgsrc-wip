
package body C393013_4 is

   function Kind (Obj : in Gas_Turbine) return Gas_Kind_Type is
   begin
       return Obj.Kind;
   end Kind;

   procedure Set_Kind (Obj : in out Gas_Turbine; Kind : in Gas_Kind_Type) is
   begin
      Obj.Kind := Kind;
   end Set_Kind;

   function Create (Power : in Natural) return Gas_Turbine is
   begin
       return (C393013_1.Create (Power) with Kind => Natural_Gas);
   end Create;

   function Clone (Obj : Gas_Turbine; New_Location : in Character)
     return Gas_Turbine is
   begin
       return  (C393013_1.Clone (C393013_1.Generator(Obj), New_Location) with
           Kind => Natural_Gas);
   end Clone;

end C393013_4;
