
with TcTouch;
package body F416A00.C416A02_A is

   function CRef (W : in New_Window; N : in Name) return Sprite is
   begin
      TcTouch.Touch('b'); TcTouch.Touch(N(1));  ---------------
      for I in 1 .. W.Count loop
         if W.Sprites(I).N = N then
            return W.Sprites(I).S;
         end if;
      end loop;
      raise Missing_Error;
   end CRef;

   function VRef (W : aliased in out New_Window; N : in Name)
      return F416A00.Ref_Rec is
   begin
      TcTouch.Touch('t'); TcTouch.Touch(N(1));  ---------------
      for I in 1 .. W.Count loop
         if W.Sprites(I).N = N then
            return (D => W.Sprites(I).S'Access);
         end if;
      end loop;
      raise Missing_Error;
   end VRef;

   function CRef (W : in New_Window; N : in Name) return Kind is
   begin
      TcTouch.Touch('a'); TcTouch.Touch(N(1));  ---------------
      for I in 1 .. W.Count loop
         if W.Sprites(I).N = N then
            return W.Sprites(I).S.K;
         end if;
      end loop;
      raise Missing_Error;
   end CRef;

   function VRef (W : aliased in out New_Window; N : in Name)
      return K_Ref_Rec is
   begin
      TcTouch.Touch('s'); TcTouch.Touch(N(1));  ---------------
      for I in 1 .. W.Count loop
         if W.Sprites(I).N = N then
            return (D => W.Sprites(I).S.K'Access);
         end if;
      end loop;
      raise Missing_Error;
   end VRef;

end F416A00.C416A02_A;
