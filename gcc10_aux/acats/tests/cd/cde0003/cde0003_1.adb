
package body CDE0003_1 is
   function F (X : Priv) return Integer is (Integer (X + C));

   procedure  P (X : Priv) is
   begin
      Success := X = C;
   end P;
end CDE0003_1;
