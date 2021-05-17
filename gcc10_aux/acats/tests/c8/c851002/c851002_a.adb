
with Report;
package body C851002_A is
   Auxf : aliased Float := 4.0;

   function Double (X : Float) return Float is
   begin
      return X * 2.0;
   end Double;

   function Element1 (Cursor : Natural) return Expected is
   begin
      return (others => <>);
   end Element1;

   function Element2 (Cursor : Natural) return Expected is
   begin
      return (others => <>);
   end Element2;

   function Element3 (Cursor : Natural) return Expected is
   begin
      return (others => <>);
   end Element3;

   function Element1 (Cursor : Natural) return Not_Right_1 is
   begin
      Report.Failed ("Wrong Element1 routine called -" & Natural'Image(Cursor));
      return (others => <>);
   end Element1;

   function Element2 (Cursor : Natural) return Not_Right_2 is
   begin
      Report.Failed ("Wrong Element2 routine called -" & Natural'Image(Cursor));
      return (others => <>);
   end Element2;

   function Element3 (Cursor : Natural) return Not_Right_3 is
   begin
      Report.Failed ("Wrong Element3 routine called -" & Natural'Image(Cursor));
      return (others => <>);
   end Element3;

end C851002_A;
