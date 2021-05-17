
with TCTouch;
package body C452004_A is

   function Zero return Rat is
   begin
      TCTouch.Touch ('0'); -------------------------------------------- 0
      return (Num => 0, Dem => 1);
   end Zero;

   function One return Rat is
   begin
      TCTouch.Touch ('1'); -------------------------------------------- 0
      return (Num => 1, Dem => 1);
   end One;

   function Val (Num : Integer; Dem : Positive) return Rat is
   begin
      TCTouch.Touch ('V'); -------------------------------------------- V
      return (Num => Num, Dem => Dem);
   end Val;

   function "=" (Left, Right : Rat) return Boolean is
   begin
      TCTouch.Touch ('='); -------------------------------------------- =
      if Left.Dem = Right.Dem then
         return Left.Num = Right.Num;
      else
         declare
            LTemp, RTemp : Integer;
         begin
            LTemp := Left.Num*Right.Dem;
            RTemp := Right.Num*Left.Dem;
            return LTemp = RTemp;
         end;
      end if;
   end "=";

   function "+" (Right : Rat) return Rat is
   begin
      TCTouch.Touch ('p'); -------------------------------------------- p
      return Right;
   end "+";

   function "-" (Right : Rat) return Rat is
   begin
      TCTouch.Touch ('m'); -------------------------------------------- m
      return (Num => -Right.Num, Dem => Right.Dem);
   end "-";

   function Add (Left, Right : Rat) return Rat is
      -- Note: No touch here.
   begin
      if Left.Dem = Right.Dem then
         return (Num => Left.Num + Right.Num, Dem => Left.Dem);
      else
         declare
            LTemp, RTemp : Integer;
         begin
            LTemp := Left.Num*Right.Dem;
            RTemp := Right.Num*Left.Dem;
            return (Num => LTemp + RTemp, Dem => Left.Dem*Right.Dem);
         end;
      end if;
   end Add;

   function "+" (Left, Right : Rat) return Rat is
   begin
      TCTouch.Touch ('+'); -------------------------------------------- +
      return Add (Left, Right);
   end "+";

   function "-" (Left, Right : Rat) return Rat is
   begin
      TCTouch.Touch ('-'); -------------------------------------------- -
      return Add (Left, (Num => -Right.Num, Dem => Right.Dem));
   end "-";

end C452004_A;
