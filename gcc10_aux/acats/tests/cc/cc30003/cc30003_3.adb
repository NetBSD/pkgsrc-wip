

with TCTouch;
package body CC30003_3 is

   procedure Make_Square (S : in out Counted_Square; Side : in Float) is
   begin
      TCTouch.Touch ('s'); ----------------------------------------- t
      TCTouch.Touch ('m'); ----------------------------------------- a
      S.Height := Side;
      S.Width  := Side;
      Clear (S);
   end Make_Square;


   function Area (S : Counted_Square) return Float is
   begin
      TCTouch.Touch ('s'); ----------------------------------------- s
      TCTouch.Touch ('a'); ----------------------------------------- a
      return S.Width ** 2;
   end Area;


   procedure Bump (S : in out Counted_Square) is
   begin
      TCTouch.Touch ('s'); ----------------------------------------- s
      TCTouch.Touch ('b'); ----------------------------------------- b
      Counted_Rectangle_Inst.Bump (Counted_Rectangle_Inst.Counted_Type(S));
   end Bump;

end CC30003_3;
