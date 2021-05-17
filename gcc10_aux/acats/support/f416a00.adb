
with TcTouch;
package body F416A00 is

   function CRef (W : in Window; N : in Name) return Sprite is
   begin
      TcTouch.Touch('c'); TcTouch.Touch(N(1));  ---------------
      for I in 1 .. W.Count loop
         if W.Sprites(I).N = N then
            return W.Sprites(I).S;
         end if;
      end loop;
      raise Missing_Error;
   end CRef;

   function VRef (W : aliased in out Window; N : in Name) return Ref_Rec is
   begin
      TcTouch.Touch('v'); TcTouch.Touch(N(1));  ---------------
      for I in 1 .. W.Count loop
         if W.Sprites(I).N = N then
            return (D => W.Sprites(I).S'Access);
         end if;
      end loop;
      raise Missing_Error;
   end VRef;

   function CRef (W : in Window; X, Y : in Natural) return Sprite is
   begin
      TcTouch.Touch('d');                       ---------------
      TcTouch.Touch(Character'Val(X - 1 + Character'Pos('A')));
      TcTouch.Touch(Character'Val(Y - 1 + Character'Pos('A')));
      for I in 1 .. W.Count loop
         if W.Sprites(I).S.X = X and then
            W.Sprites(I).S.Y = Y then
            return W.Sprites(I).S;
         end if;
      end loop;
      raise Missing_Error;
   end CRef;

   function VRef (W : aliased in out Window; X, Y : in Natural)
      return Ref_Rec is
   begin
      TcTouch.Touch('w');                       ---------------
      TcTouch.Touch(Character'Val(X - 1 + Character'Pos('A')));
      TcTouch.Touch(Character'Val(Y - 1 + Character'Pos('A')));
      for I in 1 .. W.Count loop
         if W.Sprites(I).S.X = X and then
            W.Sprites(I).S.Y = Y then
            return (D => W.Sprites(I).S'Access);
         end if;
      end loop;
      raise Missing_Error;
   end VRef;

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

end F416A00;


