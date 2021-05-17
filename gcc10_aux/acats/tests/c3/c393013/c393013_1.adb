
package body C393013_1 is

   function Power_Output (Obj : in Generator) return Natural is
   begin
       return Obj.Power_Output;
   end Power_Output;

   procedure Set_Power_Output (Obj : in out Generator; Power : in Natural) is
   begin
      Obj.Power_Output := Power;
   end Set_Power_Output;

   function Location (Obj : in Generator) return Character is
   begin
       return Obj.Location;
   end Location;

   procedure Set_Location (Obj : in out Generator; Location : in Character) is
   begin
       Obj.Location := Location;
   end Set_Location;

   function Create (Power : in Natural) return Generator is
   begin
       return (Power_Output => Power, Location => 'A');
   end Create;

   function Clone (Obj : Generator; New_Location : in Character)
     return Generator is
   begin
       return  (Power_Output => Obj.Power_Output, Location => New_Location);
   end Clone;

end C393013_1;
