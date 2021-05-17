
package body C324005_0 is

   function Is_Good (X : Priv_T) return Boolean is
   begin
      return X.Acc /= null;
   end Is_Good;

   function Good return Priv_T is
   begin
      return Result : constant Priv_T
        := (Comp => 0, Acc => new String'("xxx"))
      do
         null;
         --pragma Assert (Is_Good (Result));
         --pragma Assert (Result in Priv_T_P);
      end return;
   end Good;

   function Bad return Priv_T is
   begin
      return Result : constant Priv_T
        := (Comp => 0, Acc => null)
      do
         null;
         --pragma Assert (not Is_Good (Result));
         --pragma Assert (Result not in Priv_T_P);
      end return;
   end Bad;

end C324005_0;
