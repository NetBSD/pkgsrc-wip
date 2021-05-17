
package body B416002_A is

   function Cnst (W : in Window; N : in Name) return Sprite is
   begin
      for I in 1 .. W.Count loop
         if W.Sprites(I).N = N then
            return W.Sprites(I).S;
         end if;
      end loop;
      raise Missing_Error;
   end Cnst;

   procedure Create_Sprite (W : in out Window;
                            N : in Name;
                            X : in Natural;
                            Y : in Natural;
                            K : in Kind;
                            C : in Color) is
   begin
      W.Count := W.Count + 1;
      W.Sprites(W.Count) := (N => N, S => (K, C, X, Y));
   end Create_Sprite;

end B416002_A;
