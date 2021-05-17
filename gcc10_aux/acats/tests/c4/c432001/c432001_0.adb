
package body C432001_0 is

   function Check (Rec : in P) return Boolean is
   begin
      return Rec.How_Long_Ago = 150 and Rec.Era = Mesozoic;
   end Check;

   function Check (Rec : in N;
                   N   : in Natural;
                   E   : in Eras) return Boolean is
   begin
      return Rec.How_Long_Ago = N and Rec.Era = E;
   end Check;

end C432001_0;
