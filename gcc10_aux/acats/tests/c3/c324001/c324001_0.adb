
package body c324001_0 is

   pragma Assertion_Policy (Check);

   function Not_Another_One return Color is
   begin
      return Result : constant Color := Red do
         pragma Assert (Result in RGB);
         pragma Assert
           (Result not in Another_Color);
      end return;
   end Not_Another_One;

   function Is_Good
     (X : No_Defaults) return Boolean is
   begin
      return X.Acc /= null;
   end Is_Good;

   function Good return No_Defaults is
   begin
      return Result : constant No_Defaults
        := (Comp => 0, Acc => new String'("xxx"))
      do
         pragma Assert (Result in No_Defaults_P);
         pragma Assert (Is_Good (Result));
      end return;
   end Good;

   function Bad return No_Defaults is
   begin
      return Result : constant No_Defaults
        := (Comp => 0, Acc => null)
      do
         pragma Assert (Result not in No_Defaults_P);
         pragma Assert (not Is_Good (Result));
      end return;
   end Bad;

   function Is_Good (X : Defaults) return Boolean is
   begin
      return X.Acc /= null;
   end Is_Good;

   function Good return Defaults is
   begin
      return Result : constant Defaults
        := (Comp => 0, Acc => new String'("xxx"))
      do
         pragma Assert (Is_Good (Result));
         pragma Assert (Result in Defaults_P);
      end return;
   end Good;

   function Bad return Defaults is
   begin
      return Result : constant Defaults
        := (Comp => 0, Acc => null)
      do
         pragma Assert (not Is_Good (Result));
         pragma Assert (Result not in Defaults_P);
      end return;
   end Bad;

end C324001_0;
