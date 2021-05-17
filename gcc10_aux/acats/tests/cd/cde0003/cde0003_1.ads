
     --==================================================================--

with CDE0003_0;
package CDE0003_1 is

   Success : Boolean := False;

   type Priv is private;

   C : constant Priv;

   Z : constant Priv;

   function F (X : Priv) return Integer;

   procedure P (X : Priv);

   package Pkg is new CDE0003_0.G (Priv, F, P);

private
   type Priv is new Natural;

   C : constant Priv := 21;

   Z : constant Priv := 0;

end CDE0003_1;
